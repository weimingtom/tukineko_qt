#include "nswindow.h"
#include "nscripter.h"
#include "nsactionlistener.h"
#include "global/nsresource.h"
#include "global/nsimagecache.h"
#include "global/nstimer.h"
#include "global/nsvaluestorage.h"
#include "java/awt/color.h"
#include "java/awt/toolkit.h"
#include "java/awt/image/memoryimagesource.h"
#include "java/awt/image/pixelgrabber.h"
#include "entry/nsbutton.h"
#include "entry/nsshell.h"
#include "entry/nssprite.h"
#include "entry/nstext.h"
#include "entry/nscolor.h"
#include <QDebug>
#include <QPainter>
#include "runtime.h"
#include "file_.h"

NsWindow* NsWindow::s_instance = nullptr;

NsWindow::NsWindow(/*QObject* parent*/)
    :
      //Panel_(/*parent*/),
      storageState(-1)
    , exitFlag(false)
    , nd(new NsData())
    , m_ns(nullptr)
    , m_menuSys(nullptr)
    , m_menu(nullptr)
    , m_menuSave(nullptr)
    , m_menuLoad(nullptr)
    , m_frmBuffB(nullptr)
    , m_frmBuffBG(nullptr)
    , m_frmBuffF(nullptr)
    , m_frmBuffFG(nullptr)
    , m_frmBuffR(nullptr)
    , m_al(nullptr)
    , m_timer(nullptr)
    , m_isRotate(false)
{
    s_instance = this;

    nd->rotate = m_isRotate;
    if (!nd->rotate) {
        setSize(320, 240);
    } else {
        setSize(240, 320);
    }

    addMouseListener(this);

    m_menuSys = new PopupMenu();
    nd->menuVisible = false;
    m_menuSys->Menu::add("Fade");
    m_menuSys->addSeparator();
    m_menuSys->Menu::add("Exit");
    add(m_menuSys);

    initGraph();

    m_ns = new NScripter(this, nd);

    NsResource::initLog(nd->fchk);
    NsImageCache::init(this);
    paintF();

    setVisible(true);

    m_menu = new PopupMenu();
    m_al = new NsActionListener(m_ns, this);
    m_menu->addActionListener(m_al);
    add(m_menu);

    m_timer = new NsTimer();
}

NsWindow::~NsWindow()
{
    s_instance = nullptr;
    delete nd;
}

void NsWindow::initGraph()
{
    m_frmBuffB = Panel_::createImage(320, 240);
    m_frmBuffBG = m_frmBuffB->getGraphics();
    m_frmBuffF = Panel_::createImage(320, 240);
    m_frmBuffFG = m_frmBuffF->getGraphics();
    m_frmBuffBG->setColor(Color_::black);
    m_frmBuffBG->fillRect(0, 0, 320, 240);
}

void NsWindow::mouseClicked(MouseEvent* event)
{
    Q_UNUSED(event);
}

void NsWindow::mouseEntered(MouseEvent* event)
{
    Q_UNUSED(event);
}

void NsWindow::mouseExited(MouseEvent* event)
{
    Q_UNUSED(event);
}

void NsWindow::mouseReleased(MouseEvent* event)
{
    Q_UNUSED(event);
}

void NsWindow::mousePressed(MouseEvent* event)
{
    if (!nd->menuVisible) {
        if (nd->textVisible &&
            ((!nd->rotate && event->getY() < 16 && event->getX() < 32) ||
             (nd->rotate && event->getX() < 16 && event->getY() > 288))) {
            m_menu->show(this, 0, 0);
            nd->menuVisible = true;
        } else if ((!nd->rotate && event->getY() > 224 && event->getX() < 32) ||
                   (nd->rotate && event->getX() > 224 && event->getY() > 288)) {
            m_menuSys->show(this, 0, 0);
            nd->menuVisible = true;
        } else if (!nd->rotate) {
            if (m_ns) m_ns->click(event->getX() * 2, event->getY() * 2);
        } else {
            if (m_ns) m_ns->click((319 - event->getY()) * 2, event->getX() * 2);
        }
    } else {
        nd->menuVisible = false;
    }
}

void NsWindow::actionPerformed(ActionEvent* event)
{
    QString str = event->getActionCommand();
    if (str == "Exit") {
        storageState = 3;
        paintF();
        exitFlag = true;
    } else if (str == "Fade") {
        fadeToggle();
        nd->menuVisible = false;
    }
}

void NsWindow::fadeToggle()
{
    if (!nd->fadeMode) {
        nd->fadeMode = true;
        nd->fadeFlag = false;
    } else {
        nd->fadeMode = false;
    }
    paintB();
}

void NsWindow::paint(QPainter* painter)
{
    if (m_frmBuffF) {
        if (!nd->rotate) {
            painter->drawImage(0, 0, *m_frmBuffF->m_bufferImage, 320, 240);
        } else if (m_frmBuffR) {
            painter->drawImage(0, 0, *m_frmBuffR->m_bufferImage);
        }
    }

    if (!nd->error.isNull()) {
        painter->setPen(Qt::black);
        painter->drawText(17, 17, nd->error);
        painter->setPen(Qt::white);
        painter->drawText(16, 16, nd->error);
    }
}

void NsWindow::paintB()
{
    Image_* localImage = nullptr;

    if (nd->bgColor) {
        m_frmBuffBG->setColor(getColor(nd->bgColor));
        m_frmBuffBG->fillRect(0, 0, 320, 240);
    } else if (!nd->bgImage.isEmpty()) {
        if (nd->quakex != 0) {
            m_frmBuffBG->setColor(Color_::black);
            m_frmBuffBG->fillRect((nd->quakex & 0x1) == 0 ? 0 : 304, 0, 16, 240);
        }
        if (nd->quakey != 0) {
            m_frmBuffBG->setColor(Color_::black);
            m_frmBuffBG->fillRect(0, (nd->quakey & 0x1) == 0 ? 0 : 224, 320, 16);
        }

        localImage = NsImageCache::get(nd->bgImage);
        if (localImage) {
            m_frmBuffBG->drawImage(localImage,
                nd->quakex == 0 ? 0 : 16 - (nd->quakex & 0x1) * 32,
                nd->quakey == 0 ? 0 : 16 - (nd->quakey & 0x1) * 32, this);
        } else {
            m_frmBuffBG->setColor(Color_::black);
            m_frmBuffBG->fillRect(0, 0, 320, 240);
        }
    }

    if (nd->btnVisible && nd->btnSel != -1) {
        NsButton* localNsButton = nd->btn[nd->btnSel];
        m_frmBuffBG->setClip(localNsButton->x >> 1, localNsButton->y >> 1,
                             localNsButton->width >> 1, localNsButton->height >> 1);
        localImage = NsImageCache::get(nd->btnImage);
        if (localImage) {
            m_frmBuffBG->drawImage(localImage,
                (localNsButton->x >> 1) - (localNsButton->u >> 1),
                (localNsButton->y >> 1) - (localNsButton->v >> 1), this);
        }
        m_frmBuffBG->setClip(0, 0, 320, 240);
    }

    for (int j = 0; j < 3; ++j) {
        if (nd->shell[j]) {
            int i;
            switch (j) {
                case 0: i = 80 - (nd->shell[j]->width >> 1); break;
                case 2: i = 240 - (nd->shell[j]->width >> 1); break;
                default: i = 160 - (nd->shell[j]->width >> 1); break;
            }
            localImage = NsImageCache::get(nd->shell[j]->image);
            if (localImage) {
                m_frmBuffBG->drawImage(localImage, i, 240 - nd->shell[j]->height, this);
            }
        }
    }

    for (int j = 0; j < 50; ++j) {
        if (nd->sprite[j]->visible && nd->sprite[j]->image.size() > 0) {
            localImage = NsImageCache::get(nd->sprite[j]->image);
            if (localImage) {
                m_frmBuffBG->drawImage(localImage, nd->sprite[j]->x >> 1, nd->sprite[j]->y >> 1, this);
            }
        }
    }

    if (nd->fadeMode && nd->textVisible && nd->text && nd->text->getY() != 0) {
        nd->fadeFlag = true;
    } else {
        nd->fadeFlag = false;
    }

    paintF();
}

void NsWindow::paintF()
{
    if (storageState != 0) {
        m_frmBuffFG->setColor(Color_::black);
        m_frmBuffFG->fillRect(0, 0, 320, 240);
        m_frmBuffFG->setColor(Color_::white);

        switch (storageState) {
            case -2: {
                Image_* img;
                if ((img = NsImageCache::get(path + "MOON.PNG"))) {
                    m_frmBuffFG->drawImage(img, 5, 70, this);
                } else {
                    m_frmBuffFG->drawRect(5, 70, 100, 100);
                }
                if ((img = NsImageCache::get(path + "PLUS.PNG"))) {
                    m_frmBuffFG->drawImage(img, 110, 70, this);
                } else {
                    m_frmBuffFG->drawRect(110, 70, 100, 100);
                }
                if ((img = NsImageCache::get(path + "KAGETU.PNG"))) {
                    m_frmBuffFG->drawImage(img, 215, 70, this);
                } else {
                    m_frmBuffFG->drawRect(215, 70, 100, 100);
                }
                break;
            }
            case -1:
                m_frmBuffFG->drawString("初期化中", 140, 100);
                break;
            case 1:
                m_frmBuffFG->drawString("保存中", 140, 100);
                break;
            case 2:
                m_frmBuffFG->drawString("読出中", 140, 100);
                break;
            case 3:
                m_frmBuffFG->drawString("終了中", 140, 100);
                break;
        }
    } else {
        m_frmBuffFG->drawImage(m_frmBuffB, 0, 0, this);

        if (nd->text && nd->textVisible) {
            int i = nd->twinLx;
            int j = nd->twinLy + nd->twinFh;
            for (int k = 0; k < nd->text->getY(); ++k) {
                if (nd->twinShadow) {
                    m_frmBuffFG->setColor(Color_::black);
                    drawString(m_frmBuffFG, nd->text->getMess(k), i + 2, j + 2, nd->twinFw + nd->twinSw);
                }
                if (nd->text->getAttr(k)) {
                    m_frmBuffFG->setColor(getColor(nd->text->getColor(k)));
                } else {
                    m_frmBuffFG->setColor(new Color_(144, 144, 144));
                }
                drawString(m_frmBuffFG, nd->text->getMess(k), i, j, nd->twinFw + nd->twinSw);
                j += nd->twinFh + nd->twinSh;
            }
        }
    }

    m_frmBuffFG->setColor(Color_::black);
    QString str = QString::number(Runtime::getRuntime()->freeMemory()) + ":" +
                  QString::number(Runtime::getRuntime()->totalMemory());
    m_frmBuffFG->drawString(str, 200, 239);
    m_frmBuffFG->setColor(Color_::white);
    m_frmBuffFG->drawString(str, 201, 238);

    repaintWin();
}

void NsWindow::repaintWin()
{
    if (nd->rotate) {
        unsigned int* arrayOfInt1 = new unsigned int[320 * 240];
        unsigned int* arrayOfInt2 = new unsigned int[320 * 240];
        grabPixels(m_frmBuffF, 0, 0, 320, 240, arrayOfInt1, 0, 320);

        int k = 0;
        for (int i = 0; i < 320; ++i) {
            for (int j = 0; j < 240; ++j) {
                arrayOfInt2[k++] = arrayOfInt1[319 - i + j * 320];
            }
        }
        m_frmBuffR = createImage(240, 320, arrayOfInt2, 0, 240);
        delete[] arrayOfInt1;
        delete[] arrayOfInt2;
    }

    repaint();
}

void NsWindow::blt(int j, int k, int m, int n, int i1, int i2)
{
    m_frmBuffBG->setClip(j >> 1, k >> 1, m >> 1, n >> 1);
    Image_* localImage = NsImageCache::get(nd->btnImage);
    if (localImage) {
        m_frmBuffBG->drawImage(localImage, (j >> 1) - (i1 >> 1), (k >> 1) - (i2 >> 1), this);
    }
    m_frmBuffBG->setClip(0, 0, 320, 240);
}

Image_* NsWindow::createImage(int w, int h, unsigned int* pix, int off, int scan)
{
    return Toolkit::getDefaultToolkit()->createImage(w, h, pix, off, scan);
}

void NsWindow::grabPixels(Image_* img, int x, int y, int w, int h, unsigned int* pix, int off, int scansize)
{
    PixelGrabber grabber(img, x, y, w, h, pix, off, scansize);
    grabber.grabPixels();
}

void NsWindow::drawString(Graphics_* paramGraphics, const QString& paramString, int x, int y, int charWidth)
{
    if (paramString.isNull() || paramString.isEmpty()) return;

    FontMetrics fm = paramGraphics->getFontMetrics();
    for (int i = 0; i < paramString.length(); ++i) {
        QString ch = paramString.mid(i, 1);
        int w = fm.stringWidth(ch);
        paramGraphics->drawString(ch, (x + charWidth * i + (charWidth - w) / 2) / 2, y / 2);
    }
}

Color_* NsWindow::getColor(NsColor* color)
{
    if (!color) return Color_::black;
    return new Color_(color->getRGB(), true);
}

int NsWindow::putMess(NsText* nt, const QString& mess, NsColor* color, bool attr1, bool attr2)
{
    QString str;
    if (!attr2) {
        str = mess;
    } else {
        if (nt->curY > 0) nt->curY--;
        str = nt->mess[nt->curY] + mess;
        nt->mess[nt->curY] = "";
    }

    int j = str.length();
    int i = 0;
    if (j < 2) {
        i = 1;
    } else {
        i = (j - 1) / nt->width + 1;
    }

    if (j == 0) {
        nt->mess[nt->curY] = "";
        nt->color[nt->curY] = color;
        nt->attr[nt->curY++] = attr1;
        return 1;
    }

    i = 0;
    for (int k = 0; k < str.length(); k += nt->width) {
        if (nt->curY >= nt->height - 1) {
            nt->mess[nt->curY - 1] += "▼";
            if (!nd->fadeFlag) paintB();
            else paintF();
            newpage(true);
        }

        if (k + nt->width < str.length()) {
            int m = 0;
            for (; m < 1 && k + nt->width + m < j; ++m) {
                if (QString::fromLatin1("、。」▼▽").indexOf(str[k + nt->width + m]) == -1) break;
            }
            nt->mess[nt->curY] = nd->evalStr(str.mid(k, nt->width + m));
            k += m;
        } else {
            nt->mess[nt->curY] = nd->evalStr(str.mid(k));
        }
        nt->color[nt->curY] = color;
        nt->attr[nt->curY++] = attr1;
        ++i;
    }
    return i;
}

void NsWindow::timerExit() { if (m_timer) m_timer->exit(); }
void NsWindow::timerClear() { if (m_timer) m_timer->clear(); }
int NsWindow::timerRead() { return m_timer ? m_timer->read() : 0; }

void NsWindow::initSar(const QString& filename) { NsResource::initSar(filename, this); }
void NsWindow::initNsa(const QString& filename) { NsResource::initNsa(filename, this); }
bool NsWindow::setImageCache(const QString& name) { return NsImageCache::set(name); }

void NsWindow::loadValueStorage(InputStream* is, int* values, QString* strings, int start, int end)
{
    NsValueStorage::load(is, values, strings, start, end);
}

void NsWindow::saveValueStorage(OutputStream* os, int* values, QString* strings, int start, int end)
{
    NsValueStorage::save(os, values, strings, start, end);
}

int NsWindow::getImageWidth(const QString& image)
{
    Image_* img = NsImageCache::get(image);
    return img ? img->getWidth() : 0;
}

int NsWindow::getImageHeight(const QString& image)
{
    Image_* img = NsImageCache::get(image);
    return img ? img->getHeight() : 0;
}

void NsWindow::popupMenuAdd(const QString& str) { if (m_menu) m_menu->Menu::add(str); }

void NsWindow::makemenu(int savenumber, const QString& path, const QString& savenameTitle)
{
    makeFileMenu(m_menuSave, savenumber, path, savenameTitle);
    makeFileMenu(m_menuLoad, savenumber, path, savenameTitle);
}

void NsWindow::makeFileMenu(Menu* paramMenu, int savenumber, const QString& path, const QString& savenameTitle)
{
    if (!paramMenu) return;
    paramMenu->removeAll();

    for (int i = 0; i < savenumber; ++i) {
        QString filename = path + "SAVE" + QString::number(i + 1) + ".DAT";
        File_ file(filename);
        if (file.exists()) {
            QDateTime dt = file.lastModified();
            QString text = savenameTitle + (i < 9 ? "0" : "") + QString::number(i + 1) + " " +
                          QString::number(dt.date().month()).rightJustified(2, '0') + "/" +
                          QString::number(dt.date().day()).rightJustified(2, '0') + " " +
                          QString::number(dt.time().hour()).rightJustified(2, '0') + ":" +
                          QString::number(dt.time().minute()).rightJustified(2, '0');
            paramMenu->add(text);
        } else {
            paramMenu->add(savenameTitle + (i < 9 ? "0" : "") + QString::number(i + 1) + " --/-- --:--");
        }
    }
}

void NsWindow::createMenuSave(const QString& str)
{
    m_menuSave = new Menu(str);
    m_menuSave->addActionListener(m_al);
    m_menu->PopupMenu::add(m_menuSave);
}

void NsWindow::createMenuLoad(const QString& str)
{
    m_menuLoad = new Menu(str);
    m_menuLoad->addActionListener(m_al);
    m_menu->PopupMenu::add(m_menuLoad);
}

void NsWindow::wait(int ms, bool clickable)
{
    if (!clickable) {
        QThread::msleep(ms);
    } else {
        nd->click = false;
        if (ms == 0) {
            while (!nd->click && storageState == 0) {
                QThread::msleep(100);
            }
        } else {
            int remaining = ms;
            while (!nd->click && storageState == 0) {
                if (remaining > 100) {
                    QThread::msleep(100);
                    remaining -= 100;
                } else {
                    QThread::msleep(remaining);
                    remaining = 0;
                }
            }
        }
    }
}

void NsWindow::newpage(bool autoClick)
{
    nd->selectState = 1;
    if (autoClick) wait(nd->autoclick, true);
    if (storageState == 0) {
        nd->select.clear();
        if (nd->text) nd->text->cls();
    }
}

void NsWindow::close()
{
    storageState = 3;
    exitFlag = true;
}

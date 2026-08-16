#include "NsWindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include <QThread>
#include "parser/NScripter.h"
#include "NsActionListener.h"
#include "global/NsResource.h"
#include "global/NsImageCache.h"
#include "global/NsValueStorage.h"
#include "entry/NsButton.h"
#include "java/awt/PopupMenu.h"
#include "java/awt/Menu.h"
#include "java/awt/Toolkit.h"
#include "java/awt/image/MemoryImageSource.h"
#include "java/awt/image/PixelGrabber.h"
#include "java/awt/FontMetrics.h"
#include "java/awt/event/ActionEvent.h"

namespace tukineko {

NsWindow::NsWindow(QWidget *parent)
    : QWidget(parent)
    , ns(nullptr)
    , thd(nullptr)
    , menuSave(nullptr)
    , menuLoad(nullptr)
    , ndata(nullptr)
    , menuSys(nullptr)
    , menu(nullptr)
    , al(nullptr)
    , timer(nullptr)
    , frmBuffB(nullptr)
    , frmBuffBG(nullptr)
    , frmBuffF(nullptr)
    , frmBuffFG(nullptr)
    , frmBuffR(nullptr)
{
    bool isRotate = false;

    _start();

    this->ndata = new NsData();
    this->ndata->rotate = isRotate;

    if (!this->ndata->rotate) {
        this->setFixedSize(320, 240);
    } else {
        this->setFixedSize(240, 320);
    }

    this->menuSys = new java::awt::PopupMenu();
    this->ndata->menuVisible = false;
    this->menuSys->add("Fade");
    this->menuSys->addSeparator();
    this->menuSys->add("Exit");
    this->menuSys->addActionListener(this);
    this->add(this->menuSys);

    this->initGraph();

    this->ns = new NScripter(this, this->ndata);
    NsResource::initLog(this->ndata->fchk);
    NsImageCache::init();
    this->paintF();

    this->setVisible(true);

    this->menu = new java::awt::PopupMenu();

    this->al = new NsActionListener(this->ns, this);
    this->menu->addActionListener(this->al);
    this->add(this->menu);

    this->thd = new NsThread(this->ns, this);
    this->thd->start();

    this->timer = new NsTimer(this);
}

NsWindow::~NsWindow()
{
    if (timer) {
        timer->exit();
        delete timer;
    }
    if (thd) {
        thd->quit();
        thd->wait();
        delete thd;
    }
    if (al) {
        delete al;
    }
    if (ndata) {
        delete ndata;
    }
    if (ns) {
        delete ns;
    }
    if (menuSys) {
        delete menuSys;
    }
    if (menu) {
        delete menu;
    }
    if (menuSave) {
        delete menuSave;
    }
    if (menuLoad) {
        delete menuLoad;
    }
    if (frmBuffFG) {
        delete frmBuffFG;
    }
    if (frmBuffF) {
        delete frmBuffF;
    }
    if (frmBuffBG) {
        delete frmBuffBG;
    }
    if (frmBuffB) {
        delete frmBuffB;
    }
    if (frmBuffR) {
        delete frmBuffR;
    }
}

void NsWindow::_start()
{
    this->setFixedSize(320, 240);
}

void NsWindow::mouseClicked(java::awt::event::MouseEvent *event_)
{
    Q_UNUSED(event_)
}

void NsWindow::mouseEntered(java::awt::event::MouseEvent *event_)
{
    Q_UNUSED(event_)
}

void NsWindow::mouseExited(java::awt::event::MouseEvent *event_)
{
    Q_UNUSED(event_)
}

void NsWindow::mouseReleased(java::awt::event::MouseEvent *event_)
{
    Q_UNUSED(event_)
}

void NsWindow::mousePressed(java::awt::event::MouseEvent *event_)
{
    if (!this->ndata->menuVisible) {
        if (this->ndata->textVisible
                && ((!this->ndata->rotate && event_->getY() < 16 && event_->getX() < 32)
                    || (this->ndata->rotate && event_->getX() < 16 && event_->getY() > 288))) {
            this->menu->show(event_->getComponent(), 0, 0);
            this->ndata->menuVisible = true;
        } else if ((!this->ndata->rotate && event_->getY() > 224 && event_->getX() < 32)
                   || (this->ndata->rotate && event_->getX() > 224 && event_->getY() > 288)) {
            this->menuSys->show(event_->getComponent(), 0, 0);
            this->ndata->menuVisible = true;
        } else if (!this->ndata->rotate) {
            this->ns->click(event_->getX() * 2, event_->getY() * 2);
        } else {
            this->ns->click((319 - event_->getY()) * 2, event_->getX() * 2);
        }
    } else {
        this->ndata->menuVisible = false;
    }
}

void NsWindow::actionPerformed(java::awt::event::ActionEvent *event_)
{
    QString str = event_->getActionCommand();
    if (str == "Exit") {
        this->ns->storageState = 3;
        this->paintF();
        this->ns->exitFlag = true;
    } else if (str == "Fade") {
        this->fadeToggle();
        this->ndata->menuVisible = false;
    }
}

void NsWindow::fadeToggle()
{
    if (!this->ndata->fadeMode) {
        this->ndata->fadeMode = true;
        this->ndata->fadeFlag = false;
    } else {
        this->ndata->fadeMode = false;
    }
    this->paintB();
}

void NsWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);

    if (this->frmBuffF && this->frmBuffF->m_bufferBmp) {
        if (!this->ndata->rotate) {
            painter.drawImage(0, 0, *this->frmBuffF->m_bufferBmp);
        } else {
            if (this->frmBuffR && this->frmBuffR->m_bufferBmp) {
                painter.drawImage(0, 0, *this->frmBuffR->m_bufferBmp);
            }
        }
    }

    if (!this->ndata->error.isEmpty()) {
        painter.setPen(Qt::black);
        painter.drawText(17, 17, this->ndata->error);
        painter.setPen(Qt::white);
        painter.drawText(16, 16, this->ndata->error);
    }
}

void NsWindow::makeFileMenu(java::awt::Menu *paramMenu, int savenumber, const QString &path, const QString &savenameTitle)
{
    if (paramMenu != nullptr) {
        paramMenu->removeAll();
    }
    for (int i = 0; i < savenumber; i++) {
        QFileInfo localFile(path + "SAVE" + QString::number(i + 1) + ".DAT");
        if (localFile.exists()) {
            QDateTime localDate = localFile.lastModified();
            int j = localDate.date().month();
            int k = localDate.date().day();
            int m = localDate.time().hour();
            int n = localDate.time().minute();
            paramMenu->add(savenameTitle + (i < 9 ? "0" : "")
                           + QString::number(i + 1) + " " + (j < 10 ? "0" : "")
                           + QString::number(j) + "/" + (k < 10 ? "0" : "")
                           + QString::number(k) + " " + (m < 10 ? "0" : "")
                           + QString::number(m) + ":" + (n < 10 ? "0" : "")
                           + QString::number(n));
        } else {
            paramMenu->add(savenameTitle + (i < 9 ? "0" : "")
                           + QString::number(i + 1) + " " + "--/-- --:--");
        }
    }
}

void NsWindow::makemenu(int savenumber, const QString &path, const QString &savenameTitle)
{
    this->makeFileMenu(this->menuSave, savenumber, path, savenameTitle);
    this->makeFileMenu(this->menuLoad, savenumber, path, savenameTitle);
}

void NsWindow::createMenuSave(const QString &str)
{
    this->menuSave = new java::awt::Menu(str);
    this->menuSave->addActionListener(this->al);
    this->menu->add(this->menuSave);
}

void NsWindow::createMenuLoad(const QString &str)
{
    this->menuLoad = new java::awt::Menu(str);
    this->menuLoad->addActionListener(this->al);
    this->menu->add(this->menuLoad);
}

java::awt::Image_* NsWindow::createImage(int w, int h, const QVector<quint32> &pix, int off, int scan)
{
    java::awt::image::MemoryImageSource mis(w, h, pix, off, scan);
    return java::awt::Toolkit::getDefaultToolkit()->createImage(&mis);
}

void NsWindow::grabPixels(java::awt::Image_ *img, int x, int y, int w, int h, QVector<quint32> &pix, int off, int scansize)
{
    Q_UNUSED(off)
    Q_UNUSED(scansize)
    if (img && img->m_bufferBmp) {
        for (int j = 0; j < h; j++) {
            for (int i = 0; i < w; i++) {
                QColor c = img->m_bufferBmp->pixelColor(x + i, y + j);
                quint32 p = (c.alpha() << 24) | (c.red() << 16) | (c.green() << 8) | c.blue();
                pix[j * w + i] = p;
            }
        }
    }
}

void NsWindow::drawString(java::awt::Graphics_ *paramGraphics, const QString &paramString, int paramInt1, int paramInt2, int paramInt3)
{
    if (paramString.isEmpty()) {
        return;
    }

    java::awt::FontMetrics *localFontMetrics = paramGraphics->getFontMetrics();
    for (int i = 0; i < paramString.length(); i++) {
        QString str = paramString.mid(i, 1);
        int j = localFontMetrics->stringWidth(str);
        paramGraphics->drawString(str,
                (paramInt1 + paramInt3 * i + (paramInt3 - j) / 2) / 2,
                paramInt2 / 2);
    }
    delete localFontMetrics;
}

void NsWindow::paintB()
{
    java::awt::Image_ *localImage;
    if (this->ndata->bgColor.getRGB() != 0) {
        this->frmBuffBG->setColor(&getColor(&this->ndata->bgColor));
        this->frmBuffBG->fillRect(0, 0, 320, 240);
    } else if (!this->ndata->bgImage.isEmpty()) {
        if (this->ndata->quakex != 0) {
            this->frmBuffBG->setColor(&java::awt::Color_::black);
            this->frmBuffBG->fillRect((this->ndata->quakex & 0x1) == 0 ? 0 : 304, 0, 16, 240);
        }
        if (this->ndata->quakey != 0) {
            this->frmBuffBG->setColor(&java::awt::Color_::black);
            this->frmBuffBG->fillRect(0, (this->ndata->quakey & 0x1) == 0 ? 0 : 224, 320, 16);
        }

        localImage = NsImageCache::get(this->ndata->bgImage);
        if (localImage != nullptr) {
            this->frmBuffBG->drawImage(localImage, this->ndata->quakex == 0 ? 0
                    : 16 - (this->ndata->quakex & 0x1) * 32,
                    this->ndata->quakey == 0 ? 0
                            : 16 - (this->ndata->quakey & 0x1) * 32, this);
        } else {
            this->frmBuffBG->setColor(&java::awt::Color_::black);
            this->frmBuffBG->fillRect(0, 0, 320, 240);
        }
    }
    if ((this->ndata->btnVisible == true) && (this->ndata->btnSel != -1)) {
        NsButton *localNsButton = &this->ndata->btn[this->ndata->btnSel];
        this->frmBuffBG->setClip(localNsButton->x >> 1, localNsButton->y >> 1,
                localNsButton->width >> 1, localNsButton->height >> 1);
        localImage = NsImageCache::get(this->ndata->btnImage);
        if (localImage != nullptr) {
            this->frmBuffBG->drawImage(localImage, (localNsButton->x >> 1)
                    - (localNsButton->u >> 1), (localNsButton->y >> 1)
                    - (localNsButton->v >> 1), this);
        }
        this->frmBuffBG->setClip(0, 0, 320, 240);
    }
    int j = 0;
    for (; j < 3; j++) {
        if (!this->ndata->shell[j].image.isEmpty()) {
            int i;
            switch (j) {
            case 0:
                i = 80 - (this->ndata->shell[j].width >> 1);
                break;

            default:
                i = 160 - (this->ndata->shell[j].width >> 1);
                break;

            case 2:
                i = 240 - (this->ndata->shell[j].width >> 1);
                break;
            }
            localImage = NsImageCache::get(this->ndata->shell[j].image);
            if (localImage != nullptr) {
                this->frmBuffBG->drawImage(localImage, i,
                        240 - this->ndata->shell[j].height, this);
            }
        }
    }
    for (j = 0; j < 50; j++) {
        if ((this->ndata->sprite[j].visible != true)
                || ((localImage = NsImageCache
                        .get(this->ndata->sprite[j].image)) == nullptr)) {
            continue;
        }
        this->frmBuffBG->drawImage(localImage, this->ndata->sprite[j].x >> 1,
                this->ndata->sprite[j].y >> 1, this);
    }
    if ((this->ndata->fadeMode == true) && (this->ndata->textVisible == true)
            && (this->ndata->text != nullptr) && (this->ndata->text->getY() != 0)) {
        this->ndata->fadeFlag = true;
    } else {
        this->ndata->fadeFlag = false;
    }
    paintF();
}

void NsWindow::paintF()
{
    if (this->ns->storageState != 0) {
        this->frmBuffFG->setColor(&java::awt::Color_::black);
        this->frmBuffFG->fillRect(0, 0, 320, 240);
        this->frmBuffFG->setColor(&java::awt::Color_::white);
        switch (this->ns->storageState) {
        case -2:
        {
            java::awt::Image_ *localImage;
            localImage = NsImageCache::get(this->ns->path + "MOON.PNG");
            if (localImage != nullptr) {
                this->frmBuffFG->drawImage(localImage, 5, 70, this);
            } else {
                this->frmBuffFG->drawRect(5, 70, 100, 100);
            }
            localImage = NsImageCache::get(this->ns->path + "PLUS.PNG");
            if (localImage != nullptr) {
                this->frmBuffFG->drawImage(localImage, 110, 70, this);
            } else {
                this->frmBuffFG->drawRect(110, 70, 100, 100);
            }
            localImage = NsImageCache::get(this->ns->path + "KAGETU.PNG");
            if (localImage != nullptr) {
                this->frmBuffFG->drawImage(localImage, 215, 70, this);
            } else {
                this->frmBuffFG->drawRect(215, 70, 100, 100);
            }
            break;
        }

        case -1:
            this->frmBuffFG->drawString(QString::fromUtf8("初期化中"), 140, 100);
            break;

        case 1:
            this->frmBuffFG->drawString(QString::fromUtf8("保存中"), 140, 100);
            break;

        case 2:
            this->frmBuffFG->drawString(QString::fromUtf8("読出中"), 140, 100);
            break;

        case 3:
            this->frmBuffFG->drawString(QString::fromUtf8("終了中"), 140, 100);
            break;

        case 0:
            break;
        }
    } else {
        this->frmBuffFG->drawImage(this->frmBuffB, 0, 0, this);
        if ((this->ndata->text != nullptr) && (this->ndata->textVisible == true)) {
            int i = this->ndata->twinLx;
            int j = this->ndata->twinLy + this->ndata->twinFh;
            for (int k = 0; k < this->ndata->text->getY(); k++) {
                if (this->ndata->twinShadow == true) {
                    this->frmBuffFG->setColor(&java::awt::Color_::black);
                    drawString(this->frmBuffFG,
                            this->ndata->text->getMess(k), i + 2, j + 2,
                            this->ndata->twinFw + this->ndata->twinSw);
                    if (this->ndata->twinBold == true) {
                        drawString(this->frmBuffFG,
                                this->ndata->text->getMess(k), i + 4, j + 2,
                                this->ndata->twinFw + this->ndata->twinSw);
                    }
                }
                if (this->ndata->text->getAttr(k) == true) {
                    this->frmBuffFG->setColor(&getColor(&this->ndata->text->getColor(k)));
                } else {
                    java::awt::Color_ gray(144, 144, 144);
                    this->frmBuffFG->setColor(&gray);
                }
                drawString(this->frmBuffFG,
                        this->ndata->text->getMess(k), i, j, this->ndata->twinFw
                                + this->ndata->twinSw);
                if (this->ndata->twinBold == true) {
                    drawString(this->frmBuffFG,
                            this->ndata->text->getMess(k), i + 2, j,
                            this->ndata->twinFw + this->ndata->twinSw);
                }
                j += this->ndata->twinFh + this->ndata->twinSh;
            }
        }
    }
    this->frmBuffFG->setColor(&java::awt::Color_::black);
    QString str1 = QString::number(Runtime::getRuntime()->freeMemory());
    QString str2 = QString::number(Runtime::getRuntime()->totalMemory());
    QString str = str1 + ":" + str2;
    this->frmBuffFG->drawString(str, 200, 239);
    this->frmBuffFG->setColor(&java::awt::Color_::white);
    this->frmBuffFG->drawString(str, 201, 238);
    repaintWin();
}

void NsWindow::repaintWin()
{
    if (this->ndata->rotate == true) {
        QVector<quint32> arrayOfInt1(320 * 240);
        QVector<quint32> arrayOfInt2(320 * 240);
        grabPixels(this->frmBuffF, 0, 0, 320, 240, arrayOfInt1, 0, 320);
        int k = 0;
        for (int i = 0; i < 320; i++) {
            for (int j = 0; j < 240; j++) {
                arrayOfInt2[(k++)] = arrayOfInt1[(319 - i + j * 320)];
            }
        }
        if (this->frmBuffR) {
            delete this->frmBuffR;
        }
        this->frmBuffR = createImage(240, 320, arrayOfInt2, 0, 240);
    }
    this->update();
}

void NsWindow::blt(int j, int k, int m, int n, int i1, int i2)
{
    this->frmBuffBG->setClip(j >> 1, k >> 1, m >> 1, n >> 1);
    java::awt::Image_ *localImage = NsImageCache::get(this->ndata->btnImage);
    if (localImage != nullptr) {
        this->frmBuffBG->drawImage(localImage, (j >> 1) - (i1 >> 1), (k >> 1)
                - (i2 >> 1), this);
    }
    this->frmBuffBG->setClip(0, 0, 320, 240);
}

void NsWindow::initGraph()
{
    this->frmBuffB = new java::awt::Image_();
    this->frmBuffB->m_bufferBmp = new QImage(320, 240, QImage::Format_ARGB32);
    this->frmBuffB->m_bufferBmp->fill(Qt::transparent);
    this->frmBuffBG = this->frmBuffB->getGraphics();

    this->frmBuffF = new java::awt::Image_();
    this->frmBuffF->m_bufferBmp = new QImage(320, 240, QImage::Format_ARGB32);
    this->frmBuffF->m_bufferBmp->fill(Qt::transparent);
    this->frmBuffFG = this->frmBuffF->getGraphics();

    this->frmBuffBG->setColor(&java::awt::Color_::black);
    this->frmBuffBG->fillRect(0, 0, 320, 240);
}

int NsWindow::putMess(NsText *nt, const QString &mess, NsColor *color, bool paramBoolean1, bool paramBoolean2)
{
    QString str;
    if (!paramBoolean2) {
        str = mess;
    } else {
        if (nt->curY > 0) {
            nt->curY -= 1;
        }
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
        nt->color[nt->curY] = *color;
        nt->attr[(nt->curY++)] = paramBoolean1;
        return 1;
    }
    i = 0;
    for (int k = 0; k < str.length(); k += nt->width) {
        if (nt->curY >= nt->height - 1) {
            nt->mess[nt->curY - 1] += QString::fromUtf8("▼");
            if (!this->ndata->fadeFlag) {
                this->paintB();
            } else {
                this->paintF();
            }
            this->newpage(true);
        }
        if (k + nt->width < str.length()) {
            int m = 0;
            for (; m < 1 && k + nt->width + m < j; m++) {
                if (QString::fromUtf8("、。」,▼▽").indexOf(str[k + nt->width + m]) == -1) {
                    break;
                }
            }
            nt->mess[nt->curY] = this->ndata->evalStr(str.mid(k, nt->width + m));
            k += m;
        } else {
            nt->mess[nt->curY] = this->ndata->evalStr(str.mid(k));
        }
        nt->color[nt->curY] = *color;
        nt->attr[(nt->curY++)] = paramBoolean1;
        i++;
    }
    return i;
}

void NsWindow::timerExit()
{
    this->timer->exit();
}

void NsWindow::timerClear()
{
    this->timer->clear();
}

int NsWindow::timerRead()
{
    return this->timer->read();
}

void NsWindow::initSar(const QString &filename)
{
    NsResource::initSar(filename, this);
}

void NsWindow::initNsa(const QString &filename)
{
    NsResource::initNsa(filename, this);
}

bool NsWindow::setImageCache(const QString &name)
{
    return NsImageCache::set(name);
}

void NsWindow::loadValueStorage(java::io::InputStream *paramInputStream,
        QVector<int> &paramArrayOfInt, QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2)
{
    NsValueStorage::load(*paramInputStream->device(), paramArrayOfInt,
            paramArrayOfString, paramInt1, paramInt2);
}

void NsWindow::saveValueStorage(java::io::OutputStream *paramOutputStream,
        const QVector<int> &paramArrayOfInt, const QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2)
{
    NsValueStorage::save(*paramOutputStream->device(), paramArrayOfInt,
            paramArrayOfString, paramInt1, paramInt2);
}

int NsWindow::getImageWidth(const QString &image)
{
    java::awt::Image_ *localImage = NsImageCache::get(image);
    if (localImage != nullptr) {
        return localImage->getWidth(nullptr);
    } else {
        return 0;
    }
}

int NsWindow::getImageHeight(const QString &image)
{
    java::awt::Image_ *localImage = NsImageCache::get(image);
    if (localImage != nullptr) {
        return localImage->getHeight(nullptr);
    } else {
        return 0;
    }
}

java::awt::Color_ NsWindow::getColor(NsColor *color)
{
    return java::awt::Color_(color->getRGB(), true);
}

void NsWindow::popupMenuAdd(const QString &str)
{
    this->menu->add(str);
}

void NsWindow::wait(int paramInt, bool paramBoolean)
{
    if (!paramBoolean) {
        QThread::msleep(paramInt);
    } else {
        this->ndata->click = false;
        if (paramInt == 0) {
            do {
                QThread::msleep(100);
                if (this->ndata->click) {
                    break;
                }
            } while (this->ns->storageState == 0);
        } else {
            int i = paramInt;
            while ((this->ndata->click != true)
                   && (this->ns->storageState == 0)) {
                if (i > 100) {
                    QThread::msleep(100);
                    i -= 100;
                    continue;
                }
                QThread::msleep(i);
            }
        }
    }
}

void NsWindow::newpage(bool paramBoolean)
{
    this->ndata->selectState = 1;
    if (paramBoolean == true) {
        this->wait(this->ndata->autoclick, true);
    }
    if (this->ns->storageState == 0) {
        this->ndata->select.clear();
        this->ndata->text->cls();
    }
}

void NsWindow::mousePressEvent(QMouseEvent *event)
{
    java::awt::event::MouseEvent me;
    me.x = event->x();
    me.y = event->y();
    mousePressed(&me);
}

}

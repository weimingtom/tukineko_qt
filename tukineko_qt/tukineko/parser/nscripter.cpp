#include "nscripter.h"
#include "nswindow.h"
#include "entry/nsdata.h"
#include "entry/nstext.h"
#include "entry/nscolor.h"
#include "entry/nssselect.h"
#include "entry/nsbutton.h"
#include "entry/nsshell.h"
#include "entry/nssprite.h"
#include "java/io/file_.h"
#include "global/nsimagecache.h"
#include "global/nsvaluestorage.h"
#include <QDebug>
#include <QTextCodec>
#include <QCoreApplication>
#include <QThread>

NScripter* NScripter::s_instance = nullptr;

NScripter::NScripter(NsWindow* nsWindow, NsData* data)
    : NsParser("./")
    , tn(nsWindow)
    , nd(data)
    , raf(nullptr)
    , m_readBuff(nullptr)
    , m_readTop(0)
    , m_readEnd(0)
    , m_readPos(0)
{
    s_instance = this;
    m_readBuff = new int[4096];
}

NScripter::~NScripter()
{
    if (m_readBuff) delete[] m_readBuff;
    s_instance = nullptr;
}

void NScripter::run()
{
    initParser();

    bool hasMoon = tn->setImageCache(path + "MOON.PNG");
    bool hasPlus = tn->setImageCache(path + "PLUS.PNG");
    bool hasKagetu = tn->setImageCache(path + "KAGETU.PNG");

    qDebug() << "INFO: check MOON.PNG, PLUS.PNG, KAGETU.PNG";
    if (!hasMoon) qDebug() << "ERROR: image not found:" << path + "MOON.PNG";
    if (!hasPlus) qDebug() << "ERROR: image not found:" << path + "PLUS.PNG";
    if (!hasKagetu) qDebug() << "ERROR: image not found:" << path + "KAGETU.PNG";

    storageState = -2;
    tn->paintF();

    while (!exitFlag) {
        if (nd->click) {
            nd->click = false;
            if (nd->clickY >= 140 && nd->clickY < 340) {
                if (hasMoon && nd->clickX >= 10 && nd->clickX < 210) {
                    path += "MOON" + File_::separator();
                    break;
                }
                if (hasPlus && nd->clickX >= 220 && nd->clickX < 420) {
                    path += "PLUS" + File_::separator();
                    break;
                }
                if (hasKagetu && nd->clickX >= 430 && nd->clickX < 630) {
                    path += "KAGETU" + File_::separator();
                    break;
                }
            }
        }
        QThread::msleep(100);
    }

    if (exitFlag) {
        QCoreApplication::quit();
        return;
    }

    storageState = -1;
    tn->paintF();

    try {
        raf = new RandomAccessFile(path + "NSCRIPT.DAT", "r");
        File_ labelFile(path + "LABEL.DAT");

        if (!labelFile.exists()) {
            FileOutputStream* fos = new FileOutputStream(path + "LABEL.DAT");
            QString l;
            while (!(l = readLine()).isNull()) {
                int i = 0;
                while (i < l.length() && QString::fromLatin1(" \t").indexOf(l[i]) != -1) i++;
                if (i > 0) l = l.mid(i);

                if (l.startsWith("*")) {
                    int pos = getFilePointer();
                    nd->label[l.mid(1)] = pos;

                    QByteArray data = l.mid(1).toUtf8();
                    fos->write(data.length());
//                    fos->write(data); //FIXME:
                    fos->write(pos & 0xFF);
                    fos->write((pos >> 8) & 0xFF);
                    fos->write((pos >> 16) & 0xFF);
                    fos->write((pos >> 24) & 0xFF);
                }
            }
            fos->close();
            delete fos;
        } else {
            FileInputStream* fis = new FileInputStream(path + "LABEL.DAT");
            char buf[64];
            int len;
            while ((len = fis->read()) >= 0) {
//                fis->read(QByteArray(buf, len)); //FIXME:
                int pos = fis->read();
                pos |= fis->read() << 8;
                pos |= fis->read() << 16;
                pos |= fis->read() << 24;

                QTextCodec* codec = QTextCodec::codecForName("Shift-JIS");
                QString labelName = codec->toUnicode(buf, len);
                nd->label[labelName] = pos;
            }
            fis->close();
            delete fis;
        }
    } catch (...) {
        error("Error: LABEL.DAT");
        QCoreApplication::quit();
        return;
    }

    storageState = 0;

    try {
        gotoLabel("*define");
        exitFlag = false;

        while (!exitFlag) {
            int state = exec();
            if (state == 1) {
                // save handling
            } else if (state == 2) {
                // load handling
            }

            if (!nd->error.isNull()) {
                tn->repaint();
                while (true) {
                    QThread::sleep(1);
                }
            }
        }
    } catch (...) {
        error("Error: Read Script");
    }

    QCoreApplication::quit();
}

void NScripter::click(int x, int y)
{
    if (nd->textVisible) {
        nd->click = true;
        nd->clickX = x;
        nd->clickY = y;
    } else {
        nd->textVisible = true;
        tn->paintB();
    }
}

void NScripter::loadGlobalData()
{
    try {
        File_ file(path + "GLOVAL.SAV");
        if (file.exists()) {
            int len = file.length();
            char* data = new char[len];
            FileInputStream* fis = new FileInputStream(path + "GLOVAL.SAV");
//            fis->read(QByteArray(data, len)); //FIXME:
            fis->close();
            delete fis;

            ByteArrayInputStream bais(QByteArray(data, len));
            tn->loadValueStorage(&bais, nd->valueNum, nd->valueStr, 200, 4095);
            bais.close();
            delete[] data;
        }
    } catch (...) {
        error("load-gloval: IOException");
    }
}

void NScripter::saveGlobalData()
{
    try {
        ByteArrayOutputStream baos;
        tn->saveValueStorage(&baos, nd->valueNum, nd->valueStr, 200, 4095);
        QByteArray data = baos.toByteArray();

        FileOutputStream* fos = new FileOutputStream(path + "GLOVAL.SAV");
        //FIXME:
        //fos->write(data);
        fos->close();
        delete fos;
    } catch (...) {
        error("save-global: IOException");
    }
}

void NScripter::gotoLabel(const QString& label)
{
    if (!label.startsWith("*")) {
        error("Error Label:" + label);
        return;
    }

    if (!nd->label.contains(label.mid(1))) {
        error("Error Label:" + label);
        return;
    }

    int pos = nd->label[label.mid(1)];
    setFilePointer(pos);
    nd->historyPos = 0;
    nd->historyCount = 0;
    lineRest = "";
}

void NScripter::backHistory(int paramInt)
{
    if (nd->historyPos >= paramInt + 1) {
        nd->historyPos -= paramInt + 1;
    } else {
        nd->historyPos = (nd->historyPos - (paramInt + 1) + 100);
    }
    setFilePointer(nd->history[nd->historyPos]);
    nd->historyPos = 0;
    nd->historyCount = 0;
    lineRest = "";
}

void NScripter::addHistory()
{
    nd->history[nd->historyPos] = getFilePointer();
    nd->historyPos = (nd->historyPos + 1) % 100;
    nd->historyCount++;
//    if (this->nd) {
//        this->nd->history[nd->historyPos] = getFilePointer();
//        this->nd->historyPos = (nd->historyPos + 1) % 100;
//        this->nd->historyCount++;
//    }
}

void NScripter::continueSelect()
{
    switch (nd->selectState) {
        case 1:
            tn->newpage(true);
            break;
        case 2:
            selectWait();
            break;
    }
}

void NScripter::error(const QString& str)
{
    NsParser::error(str);
    nd->error = str;
}

void NScripter::textStar()
{
    if (nd->labellog) {
        QString labelName = line.mid(1).toUpper();
        if (!nd->lchk.contains(labelName)) {
            nd->lchk[labelName] = 1;
        }
    }
}

void NScripter::textPage()
{
    tn->putMess(nd->text, "▼", nd->textcolor, true, true);
    if (!nd->fadeFlag) {
        tn->paintB();
    } else {
        tn->paintF();
    }
    tn->newpage(true);
}

void NScripter::textSd()
{
    nd->twinSpeed = nd->defSpeed;
}

void NScripter::textW()
{
    if (!nd->fadeFlag) {
        tn->paintB();
    } else {
        tn->paintF();
    }
    bool ok;
    int waitTime = line.mid(2).toInt(&ok);
    if (ok) {
        tn->wait(waitTime, false);
    }
}

void NScripter::textSharp()
{
    nd->textcolor = nd->evalColor(line.mid(0, 7));
}

void NScripter::textTilde()
{
    try {
        nd->jumpBack = getFilePointer();
    } catch (...) {
        qDebug() << "textTilde error";
    }
}

QString NScripter::evalStr(const QString& str)
{
    return nd->evalStr(str);
}

void NScripter::textShow(const QString& str1)
{
    if (!str1.isEmpty()) {
        tn->putMess(nd->text, str1, nd->textcolor, true, lineCont);
        qDebug() << str1;
    }

    if (!nd->fadeFlag) {
        tn->paintB();
    } else {
        tn->paintF();
    }
}

NsColor* NScripter::newColor(NsColor* color)
{
    if (!color) return nullptr;
    return new NsColor(color->getRGB());
}

void NScripter::selectWait()
{
    nd->selectState = 2;
    nd->click = false;

    NsSelect* sel1 = nullptr;

    while (true) {
        if (storageState != 0) return;

        if (nd->click) {
            nd->click = false;
            nd->textSel = -1;

            for (int i = 0; i < nd->select.size(); ++i) {
                NsSelect* sel = nd->select[i];
                int y = nd->twinLy + sel->y * (nd->twinFh + nd->twinSh);
                if (nd->clickY > y && nd->clickY < y + sel->height * (nd->twinFh + nd->twinSh)) {
                    nd->textSel = i;
                    break;
                }
            }

            if (nd->textSel == -1) {
                for (int i = 0; i < nd->select.size(); ++i) {
                    NsSelect* sel = nd->select[i];
                    sel->selected = false;
                    for (int k = 0; k < sel->height; ++k) {
                        nd->text->setAttr(sel->y + k, false);
                    }
                }
            } else {
                sel1 = nd->select[nd->textSel];
                if (sel1->selected) break;

                for (int i = 0; i < nd->select.size(); ++i) {
                    NsSelect* sel = nd->select[i];
                    sel->selected = false;
                    for (int k = 0; k < sel->height; ++k) {
                        nd->text->setAttr(sel->y + k, false);
                    }
                }
                sel1->selected = true;
                for (int k = 0; k < sel1->height; ++k) {
                    nd->text->setAttr(sel1->y + k, true);
                }
            }

            if (!nd->fadeFlag) {
                tn->paintB();
            } else {
                tn->paintF();
            }
        }

        QThread::msleep(100);
    }

    try {
        if (nd->selnum != -1) {
            nd->valueNum[nd->selnum] = sel1->label.toInt();
            nd->selnum = -1;
            tn->newpage(false);
        } else {
            if (!nd->selSkipFlag) {
                nd->gosub[nd->gosubPos].retpos = getFilePointer();
                nd->gosub[nd->gosubPos].rest = lineRest;
                nd->gosubPos++;
            }
            tn->newpage(false);
            gotoLabel(sel1->label);
        }
    } catch (...) {
        error("select|selgosub|selnum");
    }
}

void NScripter::loadLogData(const QString& filename, QMap<QString, int>& dict)
{
    Q_UNUSED(filename);
    Q_UNUSED(dict);
}

void NScripter::saveLogData(const QString& filename, const QMap<QString, int>& dict)
{
    Q_UNUSED(filename);
    Q_UNUSED(dict);
}

void NScripter::save(const QString& str)
{
    if (nd->rmenu[2] != "") {
        storageState = 1;
        nd->storageNo = str.mid(nd->savenameTitle.length(), 2).toInt();
        nd->menuVisible = false;
    }
}

void NScripter::load(const QString& str)
{
    if (nd->rmenu[3] != "") {
        storageState = 2;
        nd->storageNo = str.mid(nd->savenameTitle.length(), 2).toInt();
        nd->menuVisible = false;
    }
}

void NScripter::menu3(const QString& str)
{
    if (nd->rmenu[5] != "" && str == nd->rmenu[5]) {
        nd->textVisible = false;
        tn->paintB();
        nd->menuVisible = false;
    }
}

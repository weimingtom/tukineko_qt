#include "NScripter.h"
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QTextCodec>
#include <QDebug>
#include <QThread>
#include <QBuffer>

namespace tukineko {

NScripter* NScripter::instance = nullptr;

NScripter* NScripter::getInstance()
{
    return instance;
}

NScripter::NScripter(NsWindow* paramtukineko, NsData* nd)
    : NSParser("./")
    , tn(paramtukineko)
    , nd(nd)
{
    instance = this;

    readBuff.resize(4096);
    readTop = 0;
    readEnd = 0;
    readPos = 0;

    line = QString();
    lineRest = QString();
    lineCont = false;
    argCont = false;
}

NScripter::~NScripter()
{
    destructor();
    instance = nullptr;
}

void NScripter::destructor()
{
    if (this->nd->globalon == true) {
        saveGlobalData();
    }
    if (this->nd->filelog == true) {
        saveLogData(this->path + "NSCRFLOG.DAT", this->nd->fchk);
    }
    if (this->nd->labellog == true) {
        saveLogData(this->path + "NSCRLLOG.DAT", this->nd->lchk);
    }
    if (this->raf != nullptr) {
        this->raf->close();
        delete this->raf;
        this->raf = nullptr;
    }
    // this->tn->timerExit();
}

void NScripter::run()
{
    initParser();
    bool bool1 = this->tn->setImageCache(this->path + "MOON.PNG");
    bool bool2 = this->tn->setImageCache(this->path + "PLUS.PNG");
    bool bool3 = this->tn->setImageCache(this->path + "KAGETU.PNG");

    qDebug() << "INFO: check MOON.PNG, PLUS.PNG, KAGETU.PNG";
    if (bool1 == false) {
        qDebug() << "ERROR: image not found:" << this->path + "MOON.PNG";
    }
    if (bool2 == false) {
        qDebug() << "ERROR: image not found:" << this->path + "PLUS.PNG";
    }
    if (bool3 == false) {
        qDebug() << "ERROR: image not found:" << this->path + "KAGETU.PNG";
    }

    this->storageState = -2;
    this->tn->paintF();
    while (!this->exitFlag) {
        if (this->nd->click == true) {
            this->nd->click = false;
            if ((this->nd->clickY >= 140) && (this->nd->clickY < 340)) {
                if ((bool1 == true) && (this->nd->clickX >= 10)
                        && (this->nd->clickX < 210)) {
                    this->path += "MOON" + QString(QDir::separator()) + "/";
                    break;
                }
                if ((bool2 == true) && (this->nd->clickX >= 220)
                        && (this->nd->clickX < 420)) {
                    this->path += "PLUS" + QString(QDir::separator()) + "/";
                    break;
                }
                if ((bool3 == true) && (this->nd->clickX >= 430)
                        && (this->nd->clickX < 630)) {
                    this->path += "KAGETU" + QString(QDir::separator()) + "/";
                    break;
                }
            }
        }
        QThread::msleep(100);
    }
    if (this->exitFlag == true) {
        // Environment.Exit(0);
        return;
    }
    this->storageState = -1;
    this->tn->paintF();

    try {
        this->raf = new QFile(this->path + "NSCRIPT.DAT");
        this->raf->open(QIODevice::ReadOnly);

        QFileInfo localFile(this->path + "LABEL.DAT");
        int j;
        QByteArray arrayOfByte;

        if (!localFile.exists()) {
            QFile outFile(this->path + "LABEL.DAT");
            outFile.open(QIODevice::WriteOnly);
            QDataStream localObject(&outFile);

            while ((this->line = readLine()) != QString()) {
                int i = 0;
                for (; i < this->line.length(); i++) {
                    if (" \t".indexOf(this->line[i]) == -1) {
                        break;
                    }
                }
                if (i > 0) {
                    this->line = this->line.mid(i);
                }
                if (this->line.startsWith("*") == true) {
                    j = getFilePointer();
                    this->nd->label.insert(this->line.mid(1), j);

                    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
                    arrayOfByte = codec->fromUnicode(this->line.mid(1));

                    localObject << (quint8)arrayOfByte.length();
                    outFile.write(arrayOfByte);
                    localObject << (quint8)(j & 0xFF);
                    localObject << (quint8)(j >> 8 & 0xFF);
                    localObject << (quint8)(j >> 16 & 0xFF);
                    localObject << (quint8)(j >> 24 & 0xFF);
                }
            }
            outFile.close();
        } else {
            QFile inFile(this->path + "LABEL.DAT");
            inFile.open(QIODevice::ReadOnly);
            QDataStream localObject(&inFile);
            arrayOfByte.resize(64);

            while (!inFile.atEnd()) {
                quint8 byteVal;
                localObject >> byteVal;
                j = byteVal;
                if (j < 0) break;

                inFile.read(arrayOfByte.data(), j);
                int k = 0;
                quint8 b;
                localObject >> b; k |= b;
                localObject >> b; k |= b << 8;
                localObject >> b; k |= b << 16;
                localObject >> b; k |= b << 24;

                QTextCodec* codec = QTextCodec::codecForName("Shift-JIS");
                QString labelStr;
                if (codec) {
                    labelStr = codec->toUnicode(arrayOfByte.mid(0, j));
                } else {
                    labelStr = QString::fromLocal8Bit(arrayOfByte.mid(0, j));
                }
                this->nd->label.insert(labelStr, k);
            }
            inFile.close();
        }
    } catch (...) {
        qCritical() << "Error: LABEL.DAT";
        return;
    }

    this->storageState = 0;
    try {
        gotoLabel("*define");
        this->exitFlag = false;
        while (!this->exitFlag) {
            switch (exec()) {
            case 1:
                saveLocalData();
                break;
            case 2:
                loadLocalData();
                break;
            }
            if (hasError()) {
                this->tn->repaint();
                while (true) {
                    QThread::msleep(1000);
                }
            }
        }
    } catch (...) {
        error("Error: Read Script");
    }
    destructor();
}

void NScripter::click(int paramInt1, int paramInt2)
{
    if (this->nd->textVisible == true) {
        this->nd->click = true;
        this->nd->clickX = paramInt1;
        this->nd->clickY = paramInt2;
    } else {
        this->nd->textVisible = true;
        this->tn->paintB();
    }
}

void NScripter::loadGlobalData()
{
    try {
        QFileInfo localFile(this->path + "GLOVAL.SAV");
        if (localFile.exists() == true) {
            int i = localFile.size();
            QByteArray arrayOfByte(i, 0);
            QFile localFileInputStream(localFile.absoluteFilePath());
            localFileInputStream.open(QIODevice::ReadOnly);
            localFileInputStream.read(arrayOfByte.data(), i);
            localFileInputStream.close();

            QBuffer localByteArrayInputStream(&arrayOfByte);
            localByteArrayInputStream.open(QIODevice::ReadOnly);
            this->tn->loadValueStorage(&localByteArrayInputStream, this->nd->valueNum, this->nd->valueStr, 200, 4095);
            localByteArrayInputStream.close();
        }
    } catch (...) {
        error("load-gloval: IOException");
    }
}

void NScripter::saveGlobalData()
{
    try {
        QByteArray byteArray;
        QBuffer localByteArrayOutputStream(&byteArray);
        localByteArrayOutputStream.open(QIODevice::WriteOnly);
        this->tn->saveValueStorage(&localByteArrayOutputStream,
                this->nd->valueNum, this->nd->valueStr, 200, 4095);
        localByteArrayOutputStream.close();

        QFile localFileOutputStream(this->path + "GLOVAL.SAV");
        localFileOutputStream.open(QIODevice::WriteOnly);
        localFileOutputStream.write(byteArray);
        localFileOutputStream.close();
    } catch (...) {
        error("save-global: IOException");
    }
}

void NScripter::loadLogData(const QString& paramString,
        QMap<QString, int>& paramDictionary)
{
    QByteArray arrayOfByte(1024, 0);
    try {
        QFile localFileInputStream(paramString);
        if (!localFileInputStream.open(QIODevice::ReadOnly)) {
            qCritical() << "error: read " << paramString;
            return;
        }
        QDataStream localObject(&localFileInputStream);

        int i = 0;
        int j;
        while ((j = localFileInputStream.read(1)[0]) != 10) {
            i = i * 10 + (j - 48);
        }
        for (int k = 0; k < i; k++) {
            if (localFileInputStream.read(1)[0] != 34) {
                qCritical() << "error: read " << paramString;
                break;
            }
            int m = 0;
            while ((j = localFileInputStream.read(1)[0]) != 34) {
                j ^= 132;
                arrayOfByte[m] = (j < 128 ? (char)j : (char)(j - 256));
                m++;
            }
            QTextCodec* codec = QTextCodec::codecForName("UTF-8");
            QString key;
            if (codec) {
                key = codec->toUnicode(arrayOfByte.mid(0, m));
            } else {
                key = QString::fromLocal8Bit(arrayOfByte.mid(0, m));
            }
            paramDictionary.insert(key, 1);
        }
        localFileInputStream.close();
    } catch (...) {
        qCritical() << "error: read " << paramString;
    }
}

void NScripter::saveLogData(const QString& paramString,
        const QMap<QString, int>& paramDictionary)
{
    try {
        QFile localFileOutputStream(paramString);
        localFileOutputStream.open(QIODevice::WriteOnly);
        QDataStream out(&localFileOutputStream);

        QTextCodec* codec = QTextCodec::codecForName("UTF-8");
        QByteArray countBytes = codec->fromUnicode(QString::number(paramDictionary.size()));
        localFileOutputStream.write(countBytes);
        localFileOutputStream.write(1, '\n');

        QMapIterator<QString, int> it(paramDictionary);
        while (it.hasNext()) {
            it.next();
            QByteArray arrayOfByte = codec->fromUnicode(it.key());
            for (int i = 0; i < arrayOfByte.length(); i++) {
                arrayOfByte[i] ^= 0x84;
            }
            localFileOutputStream.write(1, '"');
            localFileOutputStream.write(arrayOfByte);
            localFileOutputStream.write(1, '"');
        }
        localFileOutputStream.close();
    } catch (...) {
        qCritical() << "error: write " << paramString;
    }
}

void NScripter::loadLocalData(const QString& paramString)
{
    this->tn->paintF();
    try {
        QFileInfo localFile(this->path + paramString);
        if (!localFile.exists()) {
            this->storageState = 0;
            this->tn->paintB();
            continueSelect();
            return;
        }
        int j = localFile.size();
        QByteArray arrayOfByte(j, 0);
        QFile localFileInputStream(localFile.absoluteFilePath());
        localFileInputStream.open(QIODevice::ReadOnly);
        localFileInputStream.read(arrayOfByte.data(), j);
        localFileInputStream.close();

        QBuffer localByteArrayInputStream(&arrayOfByte);
        localByteArrayInputStream.open(QIODevice::ReadOnly);
        QDataStream in(&localByteArrayInputStream);

        int i = 0;
        quint8 b;
        in >> b; i |= b;
        in >> b; i |= b << 8;
        in >> b; i |= b << 16;
        in >> b; i |= b << 24;
        setFilePointer(i);

        tn->loadValueStorage(&localByteArrayInputStream, this->nd->valueNum,
                this->nd->valueStr, 0, 199);

        // Note: Object serialization is complex in C++
        // This would need a custom serialization approach
        // For now, we skip the ObjectInputStream part
        localByteArrayInputStream.close();

        // TODO: Restore state from serialized data
        // This requires implementing custom serialization

    } catch (...) {
        qCritical() << "Error loading local data";
    }
    this->storageState = 0;
    this->tn->paintB();
}

void NScripter::saveLocalData(const QString& paramString)
{
    this->tn->paintF();
    if (this->nd->globalon == true) {
        saveGlobalData();
    }
    if (this->nd->filelog == true) {
        saveLogData(this->path + "NSCRFLOG.DAT", this->nd->fchk);
    }
    if (this->nd->labellog == true) {
        saveLogData(this->path + "NSCRLLOG.DAT", this->nd->lchk);
    }
    try {
        QByteArray byteArray;
        QBuffer localByteArrayOutputStream(&byteArray);
        localByteArrayOutputStream.open(QIODevice::WriteOnly);
        QDataStream out(&localByteArrayOutputStream);

        int i = getFilePointer();
        out << (quint8)(i & 0xFF);
        out << (quint8)(i >> 8 & 0xFF);
        out << (quint8)(i >> 16 & 0xFF);
        out << (quint8)(i >> 24 & 0xFF);

        tn->saveValueStorage(&localByteArrayOutputStream, this->nd->valueNum, this->nd->valueStr, 0, 199);

        // Note: Object serialization requires custom implementation
        localByteArrayOutputStream.close();

        QFile localFileOutputStream(this->path + paramString);
        localFileOutputStream.open(QIODevice::WriteOnly);
        localFileOutputStream.write(byteArray);
        localFileOutputStream.close();
    } catch (...) {
        qCritical() << "Error saving local data";
    }
    this->storageState = 0;
    this->tn->paintB();
}

void NScripter::loadLocalData()
{
    loadLocalData("SAVE" + QString::number(this->nd->storageNo) + ".DAT");
    continueSelect();
}

void NScripter::saveLocalData()
{
    saveLocalData("SAVE" + QString::number(this->nd->storageNo) + ".DAT");
    tn->makemenu(this->nd->savenumber, this->path, this->nd->savenameTitle);
    continueSelect();
}

void NScripter::save(const QString& str)
{
    if (this->nd->rmenu[2] != nullptr) {
        this->storageState = 1;
        this->nd->storageNo = str.mid(this->nd->savenameTitle.length(), 2).toInt();
        this->nd->menuVisible = false;
    }
}

void NScripter::load(const QString& str)
{
    if (this->nd->rmenu[3] != nullptr) {
        this->storageState = 2;
        this->nd->storageNo = str.mid(this->nd->savenameTitle.length(), 2).toInt();
        this->nd->menuVisible = false;
    }
}

void NScripter::menu3(const QString& str)
{
    if ((this->nd->rmenu[5] != nullptr) && str == this->nd->rmenu[5]) {
        this->nd->textVisible = false;
        this->tn->paintB();
        this->nd->menuVisible = false;
    }
}

void NScripter::gotoLabel(const QString& paramString)
{
    if (!paramString.startsWith("*")) {
        error("Error Label:" + paramString);
        return;
    }
    int localint;
    if (!this->nd->label.contains(paramString.mid(1))) {
        error("Error Label:" + paramString);
        return;
    }
    localint = this->nd->label.value(paramString.mid(1));
    setFilePointer(localint);
    this->nd->historyPos = 0;
    this->nd->historyCount = 0;
    this->lineRest = QString();
}

void NScripter::backHistory(int paramInt)
{
    if (this->nd->historyPos >= paramInt + 1) {
        this->nd->historyPos -= paramInt + 1;
    } else {
        this->nd->historyPos = (this->nd->historyPos - (paramInt + 1) + 100);
    }
    setFilePointer(this->nd->history[this->nd->historyPos]);
    this->nd->historyPos = 0;
    this->nd->historyCount = 0;
    this->lineRest = QString();
}

void NScripter::addHistory()
{
    this->nd->history[this->nd->historyPos] = getFilePointer();
    this->nd->historyPos = ((this->nd->historyPos + 1) % 100);
    this->nd->historyCount += 1;
}

void NScripter::continueSelect()
{
    NSParser::continueSelect();

    switch (this->nd->selectState) {
    case 1:
        this->tn->newpage(true);
        break;

    case 2:
        selectWait();
        break;
    }
}

void NScripter::selectWait()
{
    this->nd->selectState = 2;
    this->nd->click = false;
    NsSelect* localNsSelect1 = nullptr;

    while (true) {
        if (this->storageState != 0) {
            return;
        }
        if (this->nd->click == true) {
            this->nd->click = false;
            this->nd->textSel = -1;
            int i = 0;
            for (; i < this->nd->select.size(); i++) {
                localNsSelect1 = this->nd->select[i];
                int j = this->nd->twinLy + localNsSelect1->y
                        * (this->nd->twinFh + this->nd->twinSh);
                if ((j > this->nd->clickY)
                        || (this->nd->clickY >= j + localNsSelect1->height
                                * (this->nd->twinFh + this->nd->twinSh))) {
                    continue;
                }
                this->nd->textSel = i;
                break;
            }
            NsSelect* localNsSelect2;
            int k;
            if (this->nd->textSel == -1) {
                for (i = 0; i < this->nd->select.size(); i++) {
                    localNsSelect2 = this->nd->select[i];
                    localNsSelect2->selected = false;
                    for (k = 0; k < localNsSelect2->height; k++) {
                        this->nd->text->setAttr(localNsSelect2->y + k, false);
                    }
                }
            } else {
                localNsSelect1 = this->nd->select[this->nd->textSel];
                if (localNsSelect1->selected) {
                    break;
                }
                for (i = 0; i < this->nd->select.size(); i++) {
                    localNsSelect2 = this->nd->select[i];
                    localNsSelect2->selected = false;
                    for (k = 0; k < localNsSelect2->height; k++) {
                        this->nd->text->setAttr(localNsSelect2->y + k, false);
                    }
                }
                localNsSelect1->selected = true;
                for (k = 0; k < localNsSelect1->height; k++) {
                    this->nd->text->setAttr(localNsSelect1->y + k, true);
                }
            }
            if (!this->nd->fadeFlag) {
                this->tn->paintB();
            } else {
                this->tn->paintF();
            }
        }
        QThread::msleep(100);
    }

    try {
        if (this->nd->selnum != -1) {
            this->nd->valueNum[this->nd->selnum] = localNsSelect1->label.toInt();
            this->nd->selnum = -1;
            this->tn->newpage(false);
        } else {
            if (!this->nd->selSkipFlag) {
                this->nd->gosub[this->nd->gosubPos].retpos = getFilePointer();
                this->nd->gosub[this->nd->gosubPos].rest = this->lineRest;
                this->nd->gosubPos += 1;
            }
            this->tn->newpage(false);
            gotoLabel(localNsSelect1->label);
        }
    } catch (...) {
        error("select|selgosub|selnum");
    }
}

void NScripter::error(const QString& str)
{
    NSParser::error(str);
    this->nd->error = str;
}

bool NScripter::hasError()
{
    return !this->nd->error.isNull() && !this->nd->error.isEmpty();
}

NsColor* NScripter::newColor(NsColor* color)
{
    if (color == nullptr) {
        return nullptr;
    }
    // return new NsColor(color->getRGB());
    return nullptr; // TODO: Implement
}

void NScripter::textStar()
{
    if (this->nd->labellog == true) {
        QString str2 = this->line.mid(1).toUpper();
        if (!this->nd->lchk.contains(str2)) {
            this->nd->lchk.insert(str2, 1);
        }
    }
}

void NScripter::textPage()
{
    this->tn->putMess(this->nd->text, "▼", this->nd->textcolor, true, true);
    if (!this->nd->fadeFlag)
        this->tn->paintB();
    else {
        this->tn->paintF();
    }
    this->tn->newpage(true);
}

void NScripter::textSd()
{
    this->nd->twinSpeed = this->nd->defSpeed;
}

void NScripter::textW()
{
    if (!this->nd->fadeFlag) {
        this->tn->paintB();
    } else {
        this->tn->paintF();
    }
    this->tn->wait(this->line.mid(2).toInt(), false);
}

void NScripter::textSharp()
{
    this->nd->textcolor = nd->evalColor(this->line.mid(0, 7));
}

void NScripter::textTilde()
{
    try {
        this->nd->jumpBack = getFilePointer();
    } catch (...) {
        qDebug() << "Error in textTilde";
    }
}

QString NScripter::evalStr(const QString& paramString)
{
    return nd->evalStr(paramString);
}

void NScripter::textShow(const QString& str1)
{
    if (str1.length() > 0) {
        tn->putMess(this->nd->text, str1, this->nd->textcolor, true, this->lineCont);
        qDebug() << str1;
    }
    if (!this->nd->fadeFlag) {
        this->tn->paintB();
    } else {
        this->tn->paintF();
    }
}

} // namespace tukineko

#include "NSParser.h"
#include <QTextCodec>
#include <QDebug>

namespace tukineko {

NSParser::NSParser(const QString& path)
    : storageState(-1)
    , exitFlag(false)
    , path(path)
    , lineRest() //nullptr
    , lineCont(false)
    , argCont(false)
    , readTop(0)
    , readEnd(0)
    , readPos(0)
    , raf(nullptr)
    , line() //nullptr
    , IS_EXTRACTED(false)
{
    readBuff.resize(4096);
}

NSParser::~NSParser()
{
    if (raf) {
        raf->close();
        delete raf;
    }
    // TODO: Clean up command objects
}

void NSParser::initParser()
{
    // TODO: Initialize command objects
    // sfCommands.append(new LookbackbuttonCommand());
    // ... etc
}

void NSParser::error(const QString& str)
{
    qCritical() << str;
    qDebug() << str;
}

void NSParser::debug(const QString& str)
{
    qDebug() << str;
}

void NSParser::putMess(const QString& str, bool isLineCont)
{
    qDebug() << str;
}

void NSParser::run()
{
    initParser();
    storageState = -2;
    storageState = -1;

    raf = new QFile(path);
    if (!raf->open(QIODevice::ReadOnly)) {
        error("Cannot open file: " + path);
        return;
    }

    storageState = 0;
    gotoLabel("*define");
    exitFlag = false;
    argCont = false;
    while (!exitFlag) {
        exec();
    }

    raf->close();
    delete raf;
    raf = nullptr;
}

QString NSParser::newString(const QString& paramString)
{
    if (paramString.isNull()) {
        return QString();
    }
    return QString(paramString);
}

int NSParser::read()
{
    if ((readTop > readPos) || (readPos >= readEnd)) {
        if (readPos == readEnd) {
            readTop = readEnd;
            if (raf && raf->isOpen()) {
                readEnd += raf->read(readBuff.data(), 4096);
            }
        } else {
            if (raf && raf->isOpen()) {
                raf->seek(readPos);
            }
            readTop = readPos;
            if (raf && raf->isOpen()) {
                readEnd = readTop + raf->read(readBuff.data(), 4096);
            }
        }
    }
    if ((readTop <= readPos) && (readPos < readEnd)) {
        if (IS_EXTRACTED) {
            return readBuff[readPos++ - readTop];
        } else {
            return (readBuff[readPos++ - readTop] & 0xFF) ^ 0x84;
        }
    }
    return -1;
}

int NSParser::getFilePointer()
{
    return readPos;
}

void NSParser::setFilePointer(int paramInt)
{
    readPos = paramInt;
}

QString NSParser::readLine()
{
    QByteArray arrayOfByte(1024, 0);
    lineCont = false;

    if (lineRest.isNull() || lineRest.isEmpty()) {
        addHistory();
        int k = 0;
        int i = k;
        int j;

        while (((j = read()) != 10) && (j != -1)) {
            if (j == 13) {
                continue;
            }
            arrayOfByte[i++] = (char)j;
            if ((j != 32) && (j != 9)) {
                k = i;
            }
            if (j >= 128) {
                int b = read();
                if (b == -1) break;
                arrayOfByte[i++] = (char)b;
                k = i;
            }
        }

        if ((i > 0) || (j != -1)) {
            QTextCodec* codec = QTextCodec::codecForName("Shift-JIS");
            if (codec) {
                line = codec->toUnicode(arrayOfByte.mid(0, k));
            } else {
                line = QString::fromLocal8Bit(arrayOfByte.mid(0, k));
            }
        } else {
            line = QString();
        }
    } else {
        line = lineRest;
        lineRest = QString();
        lineCont = true;
    }
    return line;
}

void NSParser::gotoLabel(const QString& paramString)
{
    if (!paramString.startsWith("*")) {
        error("Error Label:" + paramString);
        return;
    }
}

void NSParser::setMsRest()
{
    int i;
    if ((i = line.indexOf(":")) != -1) {
        lineRest = line.mid(i + 1);
    }
}

QString NSParser::getArg(int paramInt)
{
    return args[paramInt];
}

int NSParser::getArgSize()
{
    return args.size();
}

int NSParser::evalNumAlias(const QString& paramString)
{
    return paramString.toInt();
}

int NSParser::evalNum(const QString& paramString)
{
    if (paramString.startsWith("%")) {
        return 0;
    }
    return evalNumAlias(paramString);
}

QString NSParser::evalStrAlias(const QString& paramString)
{
    return paramString;
}

QString NSParser::evalStr(const QString& paramString)
{
    if (paramString.startsWith("$") == true) {
        return QString();
    }
    return evalStrAlias(paramString);
}

bool NSParser::evalBoolean(const QString& paramString)
{
    return evalNum(paramString) == 1;
}

bool NSParser::checkCommand(const QString& paramString1, const QString& paramString2)
{
    return (paramString1 == paramString2)
        || ((paramString1.length() > paramString2.length())
            && (paramString1.mid(0, paramString2.length()) == paramString2)
            && (QString(" \t").indexOf(paramString1[paramString2.length()]) != -1));
}

void NSParser::parseMessageCommand()
{
    int j = 0;
    for (; j < line.length(); j++) {
        ushort i = line[j].unicode();
        if ((i >= 256) || ((j > 0) && (QString("!\\").indexOf((char)i) != -1))) {
            break;
        }
    }
    if (j < line.length()) {
        lineRest = line.mid(j);
        line = line.mid(0, j);
    }
}

void NSParser::continueSelect()
{
}

int NSParser::exec()
{
    readLine();
    if (line.isNull() || line.isEmpty()) {
        if (line.isNull()) {
            exitFlag = true;
        }
        return storageState;
    }

    int i = 0;
    for (; i < line.length(); i++) {
        if (QString(" \t").indexOf(line[i]) == -1) {
            break;
        }
    }
    if (i > 0) {
        line = line.mid(i);
    }

    if (line.startsWith(";") == true) {
        return storageState;
    }
    if (line.startsWith("*") == true) {
        textStar();
        return storageState;
    }
    if (settingF(line) == true) {
        return storageState;
    }
    if (settingFE(line) == true) {
        return storageState;
    }
    if (settingE(line) == true) {
        return storageState;
    }
    if (visualE(line) == true) {
        return storageState;
    }
    if (visualFE(line) == true) {
        return storageState;
    }
    if (execF(line) == true) {
        return storageState;
    }
    if (execE(line) == true) {
        return storageState;
    }
    if (execFE(line) == true) {
        return storageState;
    }
    if (line.startsWith("\\") == true) {
        parseMessageCommand();
        textPage();
        return storageState;
    }
    if (line.startsWith("!sd") == true) {
        parseMessageCommand();
        textSd();
        return storageState;
    }
    if (line.startsWith("!w") == true) {
        parseMessageCommand();
        textW();
        return storageState;
    }
    if (line.startsWith("#") == true) {
        parseMessageCommand();
        textSharp();
        return storageState;
    }
    if (line.startsWith("~") == true) {
        parseMessageCommand();
        textTilde();
        return storageState;
    }

    QString str1 = evalStr(line);
    if ((str1.length() > 0) && (str1[0].unicode() < 256)) {
        error("Warning: " + str1);
        return storageState;
    }

    for (i = 0; i < str1.length(); i++) {
        if (str1[i] == '_' || str1[i] == '@'
            || str1[i] == '%'
            || (str1[i] >= '0' && str1[i] <= '9')) {
            str1 = str1.mid(0, i) + str1.mid(i + 1);
            i--;
        } else if (str1[i] == '$') {
            int j = i + 1;
            for (; j < str1.length(); j++) {
                if (str1[j].unicode() >= 256) {
                    break;
                }
            }
            str1 = str1.mid(0, i) + evalStr(str1.mid(i, j - i)) + str1.mid(j);
        } else if (str1[i].unicode() < 256) {
            lineRest = str1.mid(i);
            str1 = str1.mid(0, i);
            break;
        }
    }

    textShow(str1);
    return storageState;
}

void NSParser::makeLineRest(int paramInt)
{
    if (paramInt >= getArgSize()) {
        return;
    }
    int j = 0;
    int i = 0;
    for (; i < paramInt; i++) {
        j = line.indexOf(getArg(i), j) + getArg(i).length();
    }
    j = line.indexOf(getArg(i), j);
    lineRest = line.mid(j);
}

bool NSParser::settingF(const QString& paramString)
{
    foreach (SFCommand* command, sfCommands) {
        // TODO: Implement command check and execute
        // if (command->check(paramString)) {
        //     command->execute();
        //     return true;
        // }
    }
    return false;
}

bool NSParser::settingFE(const QString& paramString)
{
    foreach (SFECommand* command, sfeCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

bool NSParser::settingE(const QString& paramString)
{
    foreach (SECommand* command, seCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

bool NSParser::visualE(const QString& paramString)
{
    foreach (VECommand* command, veCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

bool NSParser::visualFE(const QString& paramString)
{
    foreach (VFECommand* command, vfeCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

bool NSParser::execF(const QString& paramString)
{
    foreach (FCommand* command, fCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

bool NSParser::execE(const QString& paramString)
{
    foreach (ECommand* command, eCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

bool NSParser::execFE(const QString& paramString)
{
    foreach (FECommand* command, feCommands) {
        // TODO: Implement command check and execute
    }
    return false;
}

int NSParser::parseArgs(bool paramBoolean)
{
    args.clear();
    int i = 0;
    if (paramBoolean == true) {
        while (QString(" \t").indexOf(line[i]) == -1)
            i++;
    }
    do {
        while (QString(" \t").indexOf(line[i]) != -1)
            i++;
        int j;
        int k;
        if (line[i] == '"') {
            i++;
            if ((j = i) >= line.length())
                break;
            do {
                j++;
                if (j >= line.length())
                    break;
            } while (line[j] != '"');

            args.append(line.mid(i, j - i));
            j++;
        } else {
            j = i + 1;

            while ((j < line.length())
                   && (QString(" \t,:;&\\").indexOf((char)(k = line[j].unicode())) == -1)
                   && (k < 256)) {
                j++;
            }
            if ((j < line.length()) && (line[i] == '&')
                && (line[j] == '&')) {
                j++;
            }
            args.append(line.mid(i, j - i));
        }

        while ((j < line.length())
               && (QString(" \t").indexOf(line[j]) != -1)) {
            j++;
        }
        argCont = false;
        if (j < line.length()) {
            if ((k = line[j].unicode()) == ':') {
                lineRest = line.mid(j + 1);
                break;
            }
            if (k > 255) {
                lineRest = line.mid(j);
                break;
            }
            if (k == 59)
                break;
            if (k == 44) {
                argCont = true;
                j++;
            }
        }
        i = j;
    } while (i < line.length());

    return args.size();
}

void NSParser::textStar()
{
}

void NSParser::textPage()
{
}

void NSParser::textSd()
{
}

void NSParser::textW()
{
}

void NSParser::textSharp()
{
}

void NSParser::textTilde()
{
}

void NSParser::textShow(const QString& str1)
{
    if (str1.length() > 0) {
        putMess(str1, lineCont);
    }
}

void NSParser::addHistory()
{
}

} // namespace tukineko

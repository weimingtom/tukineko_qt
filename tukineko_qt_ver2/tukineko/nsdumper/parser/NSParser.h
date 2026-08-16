#ifndef NSPARSER_H
#define NSPARSER_H

#include <QString>
#include <QList>
#include <QFile>
#include <QDataStream>
#include <QTextCodec>
#include <QDebug>

namespace tukineko {

// Forward declarations for command classes
class SFCommand;
class SFECommand;
class SECommand;
class VFECommand;
class VECommand;
class FCommand;
class ECommand;
class FECommand;

class NSParser
{
public:
    void setMsRest();
public:
    NSParser(const QString& path = "./");
    virtual ~NSParser();

    virtual void run();
    virtual void error(const QString& str);
    virtual void gotoLabel(const QString& paramString);
    virtual void continueSelect();

    QString newString(const QString& paramString);

    int getFilePointer();
    void setFilePointer(int paramInt);

    QString readLine();
    QString getArg(int paramInt);
    int getArgSize();

    int evalNumAlias(const QString& paramString);
    int evalNum(const QString& paramString);
    QString evalStrAlias(const QString& paramString);
    bool evalBoolean(const QString& paramString);
    bool checkCommand(const QString& paramString1, const QString& paramString2);

    void parseMessageCommand();
    void makeLineRest(int paramInt);

    int parseArgs(bool paramBoolean);

    bool settingF(const QString& paramString);
    bool settingFE(const QString& paramString);
    bool settingE(const QString& paramString);
    bool visualE(const QString& paramString);
    bool visualFE(const QString& paramString);
    bool execF(const QString& paramString);
    bool execE(const QString& paramString);
    bool execFE(const QString& paramString);

    void debug(const QString& str);
    void putMess(const QString& str, bool isLineCont);

    // Public members
    int storageState;
    bool exitFlag;
    QString path;
    QString lineRest;
    bool argCont;

protected:
    void initParser();
    int read();
    int exec();

    virtual QString evalStr(const QString& paramString);

    // Virtual text handlers
    virtual void textStar();
    virtual void textPage();
    virtual void textSd();
    virtual void textW();
    virtual void textSharp();
    virtual void textTilde();
    virtual void textShow(const QString& str1);

    virtual void addHistory();

    // Protected members
    QByteArray readBuff;
    int readTop;
    int readEnd;
    int readPos;
    QFile* raf;
    QString line;
    bool lineCont;
    QList<QString> args;

    bool IS_EXTRACTED;

private:
    QList<SFCommand*> sfCommands;
    QList<SFECommand*> sfeCommands;
    QList<SECommand*> seCommands;
    QList<VFECommand*> vfeCommands;
    QList<VECommand*> veCommands;
    QList<FCommand*> fCommands;
    QList<ECommand*> eCommands;
    QList<FECommand*> feCommands;
};

} // namespace tukineko

#endif // NSPARSER_H

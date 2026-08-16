#ifndef NSPARSERIMPL_H
#define NSPARSERIMPL_H

#include <QString>
#include <QVector>
#include <QMap>
#include "sfcommand.h"
#include "sfecommand.h"
#include "secommand.h"
#include "vfecommand.h"
#include "vecommand.h"
#include "fcommand.h"
#include "ecommand.h"
#include "fecommand.h"
#include "nsdata.h"
#include "randomaccessfile.h"

class NsParser
{
public:
    NsParser(const QString& path);
    virtual ~NsParser();

    void run();
    void error(const QString& str);
    void addHistory();
    void continueSelect();

protected:
    void textStar();
    void textPage();
    void textSd();
    void textW();
    void textSharp();
    void textTilde();
    void textShow(const QString& str);

    bool settingF(const QString& line);
    bool settingFE(const QString& line);
    bool settingE(const QString& line);
    bool visualE(const QString& line);
    bool visualFE(const QString& line);
    bool execF(const QString& line);
    bool execE(const QString& line);
    bool execFE(const QString& line);

    void initParser();

private:
    QVector<SFCommand*> sfCommands;
    QVector<SFECommand*> sfeCommands;
    QVector<SECommand*> seCommands;
    QVector<VFECommand*> vfeCommands;
    QVector<VECommand*> veCommands;
    QVector<FCommand*> fCommands;
    QVector<ECommand*> eCommands;
    QVector<FECommand*> feCommands;

protected:
    //byte[] readBuff = new byte[4096];
    int readTop;// = 0;
    int readEnd;// = 0;
    int readPos;// = 0;
    RandomAccessFile *raf;
    QString line;// = null;
    bool lineCont;// = false;
    QVector<QString> args;

public:
    int storageState;// = -1;
    bool exitFlag;
    QString path; // = "./"; //FIXME:???ns.nd.path
    QString lineRest;// = null;
    bool argCont;

public:
    QString newString(const QString& str);
    void setMsRest();
    int exec();
    QString readLine() {return "";}
    int getFilePointer() {return 0;}
    void setFilePointer(int paramInt) {Q_UNUSED(paramInt)}
    int parseArgs(bool paramBoolean) {Q_UNUSED(paramBoolean) return 0;}
    QString getArg(int paramInt) {Q_UNUSED(paramInt) return "";}
    void parseMessageCommand() {}
    QString evalStr(const QString& paramString) {Q_UNUSED(paramString) return ""; }
    void putMess(const QString& str, bool isLineCont) {Q_UNUSED(str) Q_UNUSED(isLineCont) }
    void gotoLabel(const QString& paramString) { Q_UNUSED(paramString) }
};

#endif // NSPARSERIMPL_H

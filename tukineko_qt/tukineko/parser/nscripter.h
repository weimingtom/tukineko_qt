#ifndef NSCRIPTER_H
#define NSCRIPTER_H

#include "nsparser.h"
#include <QMap>
#include <QString>
#include "java/io/randomaccessfile.h"
#include "java/io/fileinputstream.h"
#include "java/io/fileoutputstream.h"
#include "java/io/bytearrayinputstream.h"
#include "java/io/bytearrayoutputstream.h"
#include "java/io/objectinputstream.h"
#include "java/io/objectoutputstream.h"

class NsWindow;
class NsData;

class NScripter : public NsParser
{
    //Q_OBJECT

public:
    NScripter(NsWindow* nsWindow, NsData* data);
    virtual ~NScripter();

    void run();
    void click(int x, int y);

    void loadGlobalData();
    void saveGlobalData();
    void loadLocalData(const QString& filename);
    void saveLocalData(const QString& filename);

    void save(const QString& str);
    void load(const QString& str);
    void menu3(const QString& str);

    void gotoLabel(const QString& label);// override;
    void backHistory(int paramInt);

    void makeLineRest(int paramInt) { Q_UNUSED(paramInt) }
protected:
    void addHistory();
    void continueSelect();
public:
    void error(const QString& str);

protected:
    void textStar();
    void textPage();
    void textSd();
    void textW();
    void textSharp();
    void textTilde();
    QString evalStr(const QString& str);
    void textShow(const QString& str);

public:
    static NScripter* getInstance() { return s_instance; }

    void selectWait();
    void loadLogData(const QString& filename, QMap<QString, int>& dict);
    void saveLogData(const QString& filename, const QMap<QString, int>& dict);

private:
    NsColor* newColor(NsColor* color);

private:
    static NScripter* s_instance;
public:
    NsWindow* tn;
    NsData* nd;
private:
    RandomAccessFile* raf;
    int* m_readBuff;
    int m_readTop;
    int m_readEnd;
    int m_readPos;
};

#endif // NSCRIPTER_H

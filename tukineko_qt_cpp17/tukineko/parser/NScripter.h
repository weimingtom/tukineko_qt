#ifndef NSCRIPTER_H
#define NSCRIPTER_H

#include "../nsdumper/parser/NSParser.h"
#include <QMap>
#include <QThread>
#include <QFile>
#include <QDataStream>
#include <QTextCodec>
#include <QDebug>
#include "NsData.h"
#include "NsWindow.h"

namespace tukineko {

// Forward declarations
//class NsWindow;
//class NsData;
class NsColor;
class NsText;
class NsShell;
class NsSelect;
class NsButton;

class NScripter : public NSParser
{
public:
    static NScripter* getInstance();

    NScripter(NsWindow* paramtukineko, NsData* nd);
    virtual ~NScripter();

    virtual void run() override;
    virtual void gotoLabel(const QString& paramString) override;
    virtual void continueSelect() override;
    virtual void error(const QString& str) override;

    void click(int paramInt1, int paramInt2);
    void loadGlobalData();

    void loadLocalData(const QString& paramString);
    void saveLocalData(const QString& paramString);
    void save(const QString& str);
    void load(const QString& str);
    void menu3(const QString& str);

    void backHistory(int paramInt);

    static void loadLogData(const QString& paramString, QMap<QString, int>& paramDictionary);

    // Public members
    NsWindow* tn;
    NsData* nd;

protected:
    virtual void textStar() override;
    virtual void textPage() override;
    virtual void textSd() override;
    virtual void textW() override;
    virtual void textSharp() override;
    virtual void textTilde() override;
    virtual QString evalStr(const QString& paramString) override;
    virtual void textShow(const QString& str1) override;
    virtual void addHistory() override;

private:
    static NScripter* instance;

    void destructor();
    void saveGlobalData();
    static void saveLogData(const QString& paramString, const QMap<QString, int>& paramDictionary);
    void loadLocalData();
    void saveLocalData();
public:
    void selectWait();
private:
    bool hasError();

    static NsColor* newColor(NsColor* color);
};

} // namespace tukineko

#endif // NSCRIPTER_H

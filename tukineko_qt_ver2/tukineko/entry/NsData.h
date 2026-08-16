#ifndef NSDATA_H
#define NSDATA_H

#include <QString>
#include <QList>
#include <QVector>
#include <QMap>
#include "NsColor.h"
#include "NsText.h"
#include "NsGosub.h"
#include "NsShell.h"
#include "NsSprite.h"
#include "NsSelect.h"
#include "NsButton.h"
#include "NsEffect.h"

class NsData
{
public:
    int selectState;
    bool textVisible;
    int gosubPos;

    int twinLx;
    int twinLy;
    int twinLw;
    int twinLh;
    int twinFw;
    int twinFh;
    int twinSw;
    int twinSh;
    int twinSpeed;
    int twinHx;
    int twinHy;
    int twinEx;
    int twinEy;
    bool twinBold;
    bool twinShadow;
    NsColor twinColor;
    QString twinImage;

    QString bgImage;
    NsColor bgColor;
    int bgEffect;
    int autoclick;

    int quakex;
    int quakey;

    int textSel;
    bool selSkipFlag;
    int selnum;
    NsColor textcolor;

    QString btnImage;

    int btnSel;
    bool btnVisible;

    QVector<int> history;
    int historyPos;
    int historyCount;
    int jumpBack;

    int effectblank;
    int cdfadeout;
    QString clickstr;
    int clickstrLine;
    NsColor selectcolorOn;
    NsColor selectcolorOut;
    int menusetwindowFx;
    int menusetwindowFy;
    int menusetwindowSx;
    int menusetwindowSy;
    bool menusetwindowBold;
    bool menusetwindowShadow;
    NsColor menusetwindowColor;
    NsColor menuselectcolorOn;
    NsColor menuselectcolorOut;
    NsColor menuselectcolorNosave;

    QString savenameSave;
    QString savenameLoad;
    QString savenameTitle;

    NsColor lookbackcolor;

    bool globalon;
    bool filelog;
    bool labellog;

    int defSpeed;
    int defSpeedLow;
    int defSpeedMiddle;
    int defSpeedHigh;

    int savenumber;

    QVector<QString> rmenu;

    QVector<quint32> fadeImg;
    bool fadeMode;
    bool fadeFlag;

    bool click;
    int clickX;
    int clickY;

    int storageNo;

    QVector<int> valueNum;
    QVector<QString> valueStr;

    QMap<QString, int> label;
    QMap<QString, QString> numalias;
    QMap<QString, QString> stralias;
    QMap<QString, NsEffect> effect;
    QMap<QString, int> fchk;
    QMap<QString, int> lchk;

    NsText *text;
    QVector<NsGosub> gosub;
    QVector<NsShell> shell;
    QVector<NsSprite> sprite;
    QList<NsSelect> select;
    QList<NsButton> btn;

    bool menuVisible;
    bool rotate;

    QString error;

    NsData();

    int evalNumAlias(const QString &paramString);
    int evalNum(const QString &paramString);
    QString evalStrAlias(const QString &paramString);
    QString evalStr(const QString &paramString);
    bool evalBoolean(const QString &paramString);
    NsColor evalColor(const QString &paramString);
};

#endif // NSDATA_H

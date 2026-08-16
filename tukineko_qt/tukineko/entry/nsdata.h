#ifndef NSDATA_H
#define NSDATA_H

#include <QString>
#include <QMap>
#include <QVector>
#include "nscolor.h"
#include "nstext.h"
#include "nsbutton.h"
#include "nssselect.h"
#include "nssprite.h"
#include "nsshell.h"
#include "nseffect.h"

class NsData
{
public:
    // Selection state
    int selectState;
    bool textVisible;
    int gosubPos;

    // Text window properties
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
    NsColor* twinColor;
    QString twinImage;

    // Background
    QString bgImage;
    NsColor* bgColor;
    int bgEffect;
    int autoclick;

    // Effects
    int quakex;
    int quakey;

    // Selection
    int textSel;
    bool selSkipFlag;
    int selnum;
    NsColor* textcolor;

    // Button
    QString btnImage;
    int btnSel;
    bool btnVisible;

    // History
    int* history;
    int historyPos;
    int historyCount;
    int jumpBack;

    // Effect settings
    int effectblank;
    int cdfadeout;
    QString clickstr;
    int clickstrLine;
    NsColor* selectcolorOn;
    NsColor* selectcolorOut;
    int menusetwindowFx;
    int menusetwindowFy;
    int menusetwindowSx;
    int menusetwindowSy;
    bool menusetwindowBold;
    bool menusetwindowShadow;
    NsColor* menusetwindowColor;
    NsColor* menuselectcolorOn;
    NsColor* menuselectcolorOut;
    NsColor* menuselectcolorNosave;

    // Save/Load
    QString savenameSave;
    QString savenameLoad;
    QString savenameTitle;

    // Lookback
    NsColor* lookbackcolor;

    // Global settings
    bool globalon;
    bool filelog;
    bool labellog;

    // Speed settings
    int defSpeed;
    int defSpeedLow;
    int defSpeedMiddle;
    int defSpeedHigh;

    // Save number
    int savenumber;

    // RMenu
    QString* rmenu;

    // Fade
    unsigned int* fadeImg;
    bool fadeMode;
    bool fadeFlag;

    // Click state
    bool click;
    int clickX;
    int clickY;

    // Storage
    int storageNo;

    // Variables
    int* valueNum;
    QString* valueStr;

    // Labels and aliases
    QMap<QString, int> label;
    QMap<QString, QString> numalias;
    QMap<QString, QString> stralias;
    QMap<QString, NsEffect*> effect;
    QMap<QString, int> fchk;
    QMap<QString, int> lchk;

    // Text and game objects
    NsText* text;
    NsGosub* gosub;
    NsShell** shell;
    NsSprite** sprite;
    QVector<NsSelect*> select;
    QVector<NsButton*> btn;

    // Menu visibility
    bool menuVisible;

    // Rotation
    bool rotate;

    // Error
    QString error;

    NsData();
    virtual ~NsData();

    int evalNumAlias(const QString& paramString);
    int evalNum(const QString& paramString);
    QString evalStrAlias(const QString& paramString);
    QString evalStr(const QString& paramString);
    bool evalBoolean(const QString& paramString);
    NsColor* evalColor(const QString& paramString);
};

#endif // NSDATA_H

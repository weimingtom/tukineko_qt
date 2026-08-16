#include "nsdata.h"
#include <QDebug>

NsData::NsData()
    : selectState(0)
    , textVisible(true)
    , gosubPos(0)
    , twinLx(0), twinLy(0), twinLw(0), twinLh(0)
    , twinFw(0), twinFh(0), twinSw(0), twinSh(0)
    , twinSpeed(10), twinHx(0), twinHy(0), twinEx(0), twinEy(0)
    , twinBold(false), twinShadow(true)
    , twinColor(new NsColor(255, 255, 255))
    , twinImage()
    , bgImage(), bgColor(nullptr), bgEffect(0)
    , autoclick(0)
    , quakex(0), quakey(0)
    , textSel(-1), selSkipFlag(false), selnum(-1)
    , textcolor(NsColor::white)
    , btnImage(), btnSel(-1), btnVisible(false)
    , history(new int[100])
    , historyPos(0), historyCount(0), jumpBack(0)
    , effectblank(0), cdfadeout(0)
    , selectcolorOn(nullptr), selectcolorOut(nullptr)
    , menusetwindowFx(0), menusetwindowFy(0)
    , menusetwindowSx(0), menusetwindowSy(0)
    , menusetwindowBold(false), menusetwindowShadow(false)
    , menusetwindowColor(nullptr)
    , menuselectcolorOn(nullptr), menuselectcolorOut(nullptr)
    , menuselectcolorNosave(nullptr)
    , lookbackcolor(nullptr)
    , globalon(false), filelog(false), labellog(false)
    , defSpeed(10), defSpeedLow(20), defSpeedMiddle(10), defSpeedHigh(0)
    , savenumber(10)
    , rmenu(new QString[6])
    , fadeImg(new unsigned int[320 * 240])
    , fadeMode(true), fadeFlag(false)
    , click(false), clickX(-1), clickY(-1)
    , storageNo(0)
    , valueNum(new int[4096])
    , valueStr(new QString[4096])
    , text(nullptr)
    , gosub(new NsGosub[8])
    , shell(new NsShell*[3])
    , sprite(new NsSprite*[50])
    , menuVisible(false)
    , rotate(false)
    , error()
{
    for (int i = 0; i < 4096; ++i) {
        valueNum[i] = 0;
        valueStr[i] = "";
    }

    for (int i = 0; i < 100; ++i) {
        history[i] = 0;
    }

    for (int i = 0; i < 8; ++i) {
        gosub[i] = NsGosub();
    }

    for (int i = 0; i < 3; ++i) {
        shell[i] = nullptr;
    }

    for (int i = 0; i < 50; ++i) {
        sprite[i] = new NsSprite();
    }

    for (int i = 0; i < 6; ++i) {
        rmenu[i] = "";
    }
}

NsData::~NsData()
{
    delete[] history;
    delete[] valueNum;
    delete[] valueStr;
    delete[] gosub;
    delete[] shell;
    for (int i = 0; i < 50; ++i) {
        delete sprite[i];
    }
    delete[] sprite;
    delete[] fadeImg;
    delete[] rmenu;
    delete twinColor;
    delete textcolor;
}

int NsData::evalNumAlias(const QString& paramString)
{
    if (numalias.contains(paramString)) {
        return numalias[paramString].toInt();
    }
    return paramString.toInt();
}

int NsData::evalNum(const QString& paramString)
{
    if (paramString.startsWith("%")) {
        return valueNum[evalNumAlias(paramString.mid(1))];
    }
    return evalNumAlias(paramString);
}

QString NsData::evalStrAlias(const QString& paramString)
{
    if (stralias.contains(paramString)) {
        return stralias[paramString];
    }
    return paramString;
}

QString NsData::evalStr(const QString& paramString)
{
    if (paramString.startsWith("$")) {
        return valueStr[evalNum(paramString.mid(1))];
    }
    return evalStrAlias(paramString);
}

bool NsData::evalBoolean(const QString& paramString)
{
    return evalNum(paramString) == 1;
}

NsColor* NsData::evalColor(const QString& paramString)
{
    if (paramString.length() != 7 || !paramString.startsWith("#")) {
        qDebug() << "color value:" << paramString;
        return nullptr;
    }
    bool ok;
    unsigned int color = paramString.mid(1).toUInt(&ok, 16) | 0xFF000000;
    if (ok) {
        return new NsColor(color);
    }
    qDebug() << "color value:" << paramString;
    return nullptr;
}

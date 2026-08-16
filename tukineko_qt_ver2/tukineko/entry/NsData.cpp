#include "NsData.h"
#include <QDebug>

NsData::NsData()
    : selectState(0)
    , textVisible(true)
    , gosubPos(0)
    , twinLx(0)
    , twinLy(0)
    , twinLw(0)
    , twinLh(0)
    , twinFw(0)
    , twinFh(0)
    , twinSw(0)
    , twinSh(0)
    , twinSpeed(0)
    , twinHx(0)
    , twinHy(0)
    , twinEx(0)
    , twinEy(0)
    , twinBold(false)
    , twinShadow(false)
    , twinColor(NsColor::white)
    , bgEffect(0)
    , autoclick(0)
    , quakex(0)
    , quakey(0)
    , textSel(-1)
    , selSkipFlag(false)
    , selnum(-1)
    , textcolor(NsColor::white)
    , btnSel(-1)
    , btnVisible(false)
    , historyPos(0)
    , historyCount(0)
    , jumpBack(0)
    , effectblank(0)
    , cdfadeout(0)
    , clickstrLine(0)
    , menusetwindowFx(0)
    , menusetwindowFy(0)
    , menusetwindowSx(0)
    , menusetwindowSy(0)
    , menusetwindowBold(false)
    , menusetwindowShadow(false)
    , globalon(false)
    , filelog(false)
    , labellog(false)
    , defSpeedLow(20)
    , defSpeedMiddle(10)
    , defSpeedHigh(0)
    , defSpeed(10)
    , savenumber(0)
    , fadeMode(true)
    , fadeFlag(false)
    , click(false)
    , clickX(-1)
    , clickY(-1)
    , storageNo(0)
    , text(nullptr)
    , menuVisible(false)
    , rotate(false)
{
    valueNum.resize(4096);
    valueStr.resize(4096);
    for (int i = 0; i < 4096; i++) {
        valueNum[i] = 0;
        valueStr[i] = QString();
    }

    fadeImg.resize(320 * 240);

    gosub.resize(8);
    for (int i = 0; i < 8; i++) {
        gosub[i] = NsGosub();
    }

    shell.resize(3);

    sprite.resize(50);
    for (int i = 0; i < 50; i++) {
        sprite[i] = NsSprite();
    }

    history.resize(100);
    rmenu.resize(6);

    defSpeed = defSpeedMiddle;
    twinSpeed = defSpeed;
}

int NsData::evalNumAlias(const QString &paramString)
{
    if (numalias.contains(paramString)) {
        return numalias.value(paramString).toInt();
    }
    return paramString.toInt();
}

int NsData::evalNum(const QString &paramString)
{
    if (paramString.startsWith("%")) {
        return valueNum[evalNumAlias(paramString.mid(1))];
    }
    return evalNumAlias(paramString);
}

QString NsData::evalStrAlias(const QString &paramString)
{
    if (stralias.contains(paramString)) {
        return stralias.value(paramString);
    }
    return paramString;
}

QString NsData::evalStr(const QString &paramString)
{
    if (paramString.startsWith("$")) {
        return valueStr[evalNum(paramString.mid(1))];
    }
    return evalStrAlias(paramString);
}

bool NsData::evalBoolean(const QString &paramString)
{
    return evalNum(paramString) == 1;
}

NsColor NsData::evalColor(const QString &paramString)
{
    if ((paramString.length() != 7) || (!paramString.startsWith("#"))) {
        qWarning() << "color value:" << paramString;
        return NsColor(0);
    }
    bool ok;
    quint32 color = paramString.mid(1).toUInt(&ok, 16);
    if (ok) {
        return NsColor(color | 0xFF000000);
    }
    qWarning() << "color value:" << paramString;
    return NsColor(0);
}

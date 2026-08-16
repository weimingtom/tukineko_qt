#include <iostream>
#include <QDebug>
#include "sfcommand.h"

SFCommand::SFCommand()
{
}

SFCommand::~SFCommand()
{
}

bool SFCommand::checkCommand(const QString& paramString1, const QString& paramString2)
{
    if (paramString1 == paramString2)
    {
        return true;
    }
    if (paramString1.length() > paramString2.length() &&
        paramString1.startsWith(paramString2) &&
        (QString(" \t").indexOf(paramString1[paramString2.length()]) != -1))
    {
        return true;
    }
    return false;
}

bool SFCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SFCommand::execute()
{
}

void SFCommand::debug(const QString& str)
{
    std::cout << str.toStdString() << std::endl;
    qDebug() << str;
}

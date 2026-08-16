#include <iostream>
#include <QDebug>
#include "vecommand.h"

VECommand::VECommand()
{
}

VECommand::~VECommand()
{
}

bool VECommand::checkCommand(const QString& paramString1, const QString& paramString2)
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

bool VECommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void VECommand::execute()
{
}

void VECommand::debug(const QString& str)
{
    std::cout << str.toStdString() << std::endl;
    qDebug() << str;
}

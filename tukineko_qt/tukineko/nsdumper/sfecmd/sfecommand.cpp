#include "sfecommand.h"
#include <iostream>
#include <QDebug>

SFECommand::SFECommand()
{
}

SFECommand::~SFECommand()
{
}

bool SFECommand::checkCommand(const QString& paramString1, const QString& paramString2)
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

bool SFECommand::check(const QString& str)
{
    Q_UNUSED(str)
    return false;
}

void SFECommand::execute()
{
}

void SFECommand::debug(const QString& str)
{
    std::cout << str.toStdString() << std::endl;
    qDebug() << str;
}

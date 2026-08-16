#include "sfecommand.h"
#include <QDebug>
#include <iostream>

SFECommand::SFECommand()
{
}

SFECommand::~SFECommand()
{
}

bool SFECommand::check(const QString &str)
{
    Q_UNUSED(str)
    return false;
}

void SFECommand::execute()
{
}

bool SFECommand::checkCommand(const QString &paramString1, const QString &paramString2)
{
    if (paramString1 == paramString2) {
        return true;
    }
    if (paramString1.length() > paramString2.length() &&
        paramString1.startsWith(paramString2) &&
        (paramString1[paramString2.length()] == ' ' || paramString1[paramString2.length()] == '\t')) {
        return true;
    }
    return false;
}

void SFECommand::debug(const QString &str)
{
    std::cout << str.toStdString() << std::endl;
    qDebug() << str;
}

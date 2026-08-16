#include "sfcommand.h"
#include <QDebug>
#include <iostream>

SFCommand::SFCommand()
{
}

SFCommand::~SFCommand()
{
}

bool SFCommand::check(const QString &str)
{
    Q_UNUSED(str)
    return false;
}

void SFCommand::execute()
{
}

bool SFCommand::checkCommand(const QString &paramString1, const QString &paramString2)
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

void SFCommand::debug(const QString &str)
{
    std::cerr << ">>>>>>>>>>>debug<<<<<<<<<<<<<" << str.toStdString() << std::endl;
    qDebug() << ">>>>>>>>>>>debug<<<<<<<<<<<<<" << str;
}

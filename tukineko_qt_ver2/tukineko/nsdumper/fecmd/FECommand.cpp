#include "FECommand.h"
#include <QDebug>

FECommand::FECommand()
{
}

FECommand::~FECommand()
{
}

bool FECommand::check(const QString &str)
{
    Q_UNUSED(str)
    return false;
}

void FECommand::execute()
{
}

bool FECommand::checkCommand(const QString &paramString1, const QString &paramString2)
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

void FECommand::debug(const QString &str)
{
    qDebug() << str;
}

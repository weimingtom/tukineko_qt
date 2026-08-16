#include "SECommand.h"
#include <QDebug>

SECommand::SECommand()
{
}

SECommand::~SECommand()
{
}

bool SECommand::check(const QString &str)
{
    Q_UNUSED(str)
    return false;
}

void SECommand::execute()
{
}

bool SECommand::checkCommand(const QString &paramString1, const QString &paramString2)
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

void SECommand::debug(const QString &str)
{
    qDebug() << str;
}

#include "TimeCommand.h"
#include "NScripter.h"
#include <QDateTime>

TimeCommand::TimeCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool TimeCommand::check(const QString &str)
{
    return checkCommand(str, "time");
}

void TimeCommand::execute()
{
    debug("[FECommand] time");

    if (ns->parseArgs(true) < 3) {
        ns->error("time");
    } else {
        QDateTime localDate = QDateTime::currentDateTime();
        if (ns->getArg(0).startsWith("%") &&
            ns->getArg(1).startsWith("%") &&
            ns->getArg(2).startsWith("%")) {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = localDate.time().hour();
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(1).mid(1))] = localDate.time().minute();
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(2).mid(1))] = localDate.time().second();
        } else {
            ns->error("time");
        }
        ns->makeLineRest(3);
    }
}

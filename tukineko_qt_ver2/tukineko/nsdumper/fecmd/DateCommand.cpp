#include "DateCommand.h"
#include "NScripter.h"
#include <QDateTime>

DateCommand::DateCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool DateCommand::check(const QString &str)
{
    return checkCommand(str, "date");
}

void DateCommand::execute()
{
    debug("[FECommand] date");

    if (ns->parseArgs(true) < 3) {
        ns->error("date");
    } else {
        QDateTime localDate = QDateTime::currentDateTime();
        if (ns->getArg(0).startsWith("%") &&
            ns->getArg(1).startsWith("%") &&
            ns->getArg(2).startsWith("%")) {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = localDate.date().year();
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(1).mid(1))] = localDate.date().month();
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(2).mid(1))] = localDate.date().day();
        } else {
            ns->error("date");
        }
        ns->makeLineRest(3);
    }
}

#include "IncCommand.h"
#include "NScripter.h"

IncCommand::IncCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool IncCommand::check(const QString &str)
{
    return checkCommand(str, "inc");
}

void IncCommand::execute()
{
    debug("[FECommand] inc");

    if (ns->parseArgs(true) < 1) {
        ns->error("inc");
    } else {
        if (!ns->getArg(0).startsWith("%")) {
            ns->error("inc");
        } else {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] += 1;
        }
        ns->makeLineRest(1);
    }
}

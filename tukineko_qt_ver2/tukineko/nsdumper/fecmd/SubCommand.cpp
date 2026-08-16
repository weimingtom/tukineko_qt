#include "SubCommand.h"
#include "NScripter.h"

SubCommand::SubCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SubCommand::check(const QString &str)
{
    return checkCommand(str, "sub");
}

void SubCommand::execute()
{
    debug("[FECommand] sub");

    if (ns->parseArgs(true) < 2) {
        ns->error("sub");
    } else if (!ns->getArg(0).startsWith("%")) {
        ns->error("sub");
    } else {
        ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] -= ns->nd->evalNum(ns->getArg(1));
    }
}

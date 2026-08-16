#include "CmpCommand.h"
#include "NScripter.h"

CmpCommand::CmpCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool CmpCommand::check(const QString &str)
{
    return checkCommand(str, "cmp");
}

void CmpCommand::execute()
{
    debug("[FECommand] cmp");

    if (ns->parseArgs(true) < 3) {
        ns->error("cmp");
    } else if (!ns->getArg(0).startsWith("%")) {
        ns->error("cmp");
    } else {
        ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = ns->nd->evalStr(ns->getArg(1)).compare(ns->getArg(2));
        ns->makeLineRest(3);
    }
}

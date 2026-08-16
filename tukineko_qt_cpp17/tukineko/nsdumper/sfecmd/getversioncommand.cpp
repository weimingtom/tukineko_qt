#include "getversioncommand.h"
#include "nscripter.h"

GetversionCommand::GetversionCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool GetversionCommand::check(const QString &str)
{
    return checkCommand(str, "getversion");
}

void GetversionCommand::execute()
{
    debug("[SFECommand] getversion");

    if (ns->parseArgs(true) < 1) {
        ns->error("getversion");
    } else {
        if (!ns->getArg(0).startsWith("%")) {
            ns->error("getversion");
        } else {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = 999;
        }
        ns->makeLineRest(1);
    }
}

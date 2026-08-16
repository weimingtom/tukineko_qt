#include "cdfadeoutcommand.h"
#include "nscripter.h"

CdfadeoutCommand::CdfadeoutCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool CdfadeoutCommand::check(const QString &str)
{
    return checkCommand(str, "cdfadeout");
}

void CdfadeoutCommand::execute()
{
    debug("[SFCommand] cdfadeout");

    if (ns->parseArgs(true) < 1) {
        ns->error("cdfadeout");
    } else {
        ns->nd->cdfadeout = ns->nd->evalNum(ns->getArg(0));
        ns->makeLineRest(1);
    }
}

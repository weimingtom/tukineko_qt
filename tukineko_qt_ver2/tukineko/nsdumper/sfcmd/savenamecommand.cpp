#include "savenamecommand.h"
#include "nscripter.h"

SavenameCommand::SavenameCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SavenameCommand::check(const QString &str)
{
    return checkCommand(str, "savename");
}

void SavenameCommand::execute()
{
    debug("[SFCommand] savename");

    if (ns->parseArgs(true) < 3) {
        ns->error("savename");
    } else {
        ns->nd->savenameSave = ns->nd->evalStr(ns->getArg(0));
        ns->nd->savenameLoad = ns->nd->evalStr(ns->getArg(1));
        ns->nd->savenameTitle = ns->nd->evalStr(ns->getArg(2));
        ns->makeLineRest(3);
    }
}

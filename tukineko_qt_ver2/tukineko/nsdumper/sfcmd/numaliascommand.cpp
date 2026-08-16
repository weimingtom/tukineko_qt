#include "numaliascommand.h"
#include "nscripter.h"

NumaliasCommand::NumaliasCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool NumaliasCommand::check(const QString &str)
{
    return checkCommand(str, "numalias");
}

void NumaliasCommand::execute()
{
    debug("[SFCommand] numalias");

    if (ns->parseArgs(true) < 2) {
        ns->error("numalias");
    } else {
        ns->nd->numalias.insert(ns->getArg(0), ns->getArg(1));
        ns->makeLineRest(2);
    }
}

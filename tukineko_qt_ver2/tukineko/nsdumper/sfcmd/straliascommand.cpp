#include "straliascommand.h"
#include "nscripter.h"

StraliasCommand::StraliasCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool StraliasCommand::check(const QString &str)
{
    return checkCommand(str, "stralias");
}

void StraliasCommand::execute()
{
    debug("[SFCommand] stralias");

    if (ns->parseArgs(true) < 2) {
        ns->error("stralias");
    } else {
        ns->nd->stralias.insert(ns->getArg(0), ns->getArg(1));
        ns->makeLineRest(2);
    }
}

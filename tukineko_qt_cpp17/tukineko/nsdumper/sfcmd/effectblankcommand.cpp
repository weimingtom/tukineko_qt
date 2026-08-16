#include "effectblankcommand.h"
#include "nscripter.h"

EffectblankCommand::EffectblankCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool EffectblankCommand::check(const QString &str)
{
    return checkCommand(str, "effectblank");
}

void EffectblankCommand::execute()
{
    debug("[SFCommand] effectblank");

    if (ns->parseArgs(true) < 1) {
        ns->error("effectblank");
    } else {
        ns->nd->effectblank = ns->nd->evalNum(ns->getArg(0));
        ns->makeLineRest(1);
    }
}

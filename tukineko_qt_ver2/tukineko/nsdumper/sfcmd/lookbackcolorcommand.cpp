#include "lookbackcolorcommand.h"
#include "nscripter.h"

LookbackcolorCommand::LookbackcolorCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool LookbackcolorCommand::check(const QString &str)
{
    return checkCommand(str, "lookbackcolor");
}

void LookbackcolorCommand::execute()
{
    debug("[SFCommand] lookbackcolor");

    if (ns->parseArgs(true) < 1) {
        ns->error("lookbackcolor");
    } else {
        ns->nd->lookbackcolor = ns->nd->evalColor(ns->getArg(0));
        ns->makeLineRest(1);
    }
}

#include "clickstrcommand.h"
#include "nscripter.h"

ClickstrCommand::ClickstrCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool ClickstrCommand::check(const QString &str)
{
    return checkCommand(str, "clickstr");
}

void ClickstrCommand::execute()
{
    debug("[SFCommand] clickstr");

    if (ns->parseArgs(true) < 2) {
        ns->error("clickstr");
    } else {
        ns->nd->clickstr = ns->nd->evalStr(ns->getArg(0));
        ns->nd->clickstrLine = ns->nd->evalNum(ns->getArg(1));
        ns->makeLineRest(2);
    }
}

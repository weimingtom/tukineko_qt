#include "selectcolorcommand.h"
#include "nscripter.h"

SelectcolorCommand::SelectcolorCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SelectcolorCommand::check(const QString &str)
{
    return checkCommand(str, "selectcolor");
}

void SelectcolorCommand::execute()
{
    debug("[SFCommand] selectcolor");

    if (ns->parseArgs(true) < 2) {
        ns->error("selectcolor");
    } else {
        ns->nd->selectcolorOn = ns->nd->evalColor(ns->nd->evalStr(ns->getArg(0)));
        ns->nd->selectcolorOut = ns->nd->evalColor(ns->nd->evalStr(ns->getArg(1)));
        ns->makeLineRest(2);
    }
}

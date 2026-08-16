#include "defspeedcommand.h"
#include "nscripter.h"

DefSpeedCommand::DefSpeedCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool DefSpeedCommand::check(const QString &str)
{
    return checkCommand(str, "defSpeed");
}

void DefSpeedCommand::execute()
{
    debug("[SFCommand] defSpeed");

    if (ns->parseArgs(true) < 3) {
        ns->error("defSpeed");
    } else {
        ns->nd->defSpeedLow = ns->nd->evalNum(ns->getArg(0));
        ns->nd->defSpeedMiddle = ns->nd->evalNum(ns->getArg(1));
        ns->nd->defSpeedHigh = ns->nd->evalNum(ns->getArg(2));
        ns->makeLineRest(3);
    }
}

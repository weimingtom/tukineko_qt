#include "savenumbercommand.h"
#include "nscripter.h"

bool SavenumberCommand::check(const QString &str)
{
    return checkCommand(str, "savenumber");
}

void SavenumberCommand::execute()
{
    debug("[FCommand] savenumber");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    if (ns->parseArgs(true) < 1) {
        ns->error("savenumber");
    } else {
        ns->nd->savenumber = ns->nd->evalNum(ns->getArg(0));
        if (ns->nd->savenumber > 10) {
            ns->nd->savenumber = 10;
        }
        ns->makeLineRest(1);
    }
}

#include "delaycommand.h"
#include "nscripter.h"

bool DelayCommand::check(const QString &str)
{
    return checkCommand(str, "delay");
}

void DelayCommand::execute()
{
    debug("[ECommand] delay");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    if (ns->parseArgs(true) < 1) {
        ns->error("delay");
    } else {
        ns->tn->wait(ns->nd->evalNum(ns->getArg(0)), true);
        ns->makeLineRest(1);
    }
}

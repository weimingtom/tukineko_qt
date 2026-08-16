#include "resettimercommand.h"
#include "nscripter.h"

bool ResettimerCommand::check(const QString &str)
{
    return str.startsWith("resettimer");
}

void ResettimerCommand::execute()
{
    debug("[ECommand] resettimer");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->setMsRest();
    ns->tn->timerClear();
}

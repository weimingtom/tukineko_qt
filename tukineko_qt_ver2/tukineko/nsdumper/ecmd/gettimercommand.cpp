#include "gettimercommand.h"
#include "nscripter.h"

bool GettimerCommand::check(const QString &str)
{
    return checkCommand(str, "gettimer");
}

void GettimerCommand::execute()
{
    debug("[ECommand] gettimer");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("gettimer");
}

#include "resetcommand.h"
#include "nscripter.h"

bool ResetCommand::check(const QString &str)
{
    return checkCommand(str, "reset");
}

void ResetCommand::execute()
{
    debug("[ECommand] reset");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();

    if (ns == nullptr) {
        debug("[ECommand] reset ns == null");
        return;
    }

    ns->error("reset");
}

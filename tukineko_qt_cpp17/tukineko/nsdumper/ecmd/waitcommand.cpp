#include "waitcommand.h"
#include "nscripter.h"

bool WaitCommand::check(const QString &str)
{
    return checkCommand(str, "wait");
}

void WaitCommand::execute()
{
    debug("[ECommand] wait");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("wait");
}

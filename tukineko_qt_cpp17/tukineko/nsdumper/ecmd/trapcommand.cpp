#include "trapcommand.h"
#include "nscripter.h"

bool TrapCommand::check(const QString &str)
{
    return checkCommand(str, "trap");
}

void TrapCommand::execute()
{
    debug("[ECommand] trap");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("trap");
}

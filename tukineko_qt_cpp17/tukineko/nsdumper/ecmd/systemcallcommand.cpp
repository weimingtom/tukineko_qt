#include "systemcallcommand.h"
#include "nscripter.h"

bool SystemcallCommand::check(const QString &str)
{
    return checkCommand(str, "systemcall");
}

void SystemcallCommand::execute()
{
    debug("[ECommand] systemcall");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("systemcall");
}

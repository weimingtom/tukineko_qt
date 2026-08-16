#include "rmodecommand.h"
#include "nscripter.h"

bool RmodeCommand::check(const QString &str)
{
    return checkCommand(str, "rmode");
}

void RmodeCommand::execute()
{
    debug("[ECommand] rmode");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("rmode");
}

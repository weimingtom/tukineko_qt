#include "roffcommand.h"
#include "nscripter.h"

RoffCommand::RoffCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool RoffCommand::check(const QString &str)
{
    return checkCommand(str, "roff");
}

void RoffCommand::execute()
{
    debug("[SFCommand] roff");

    ns->error("roff");
}

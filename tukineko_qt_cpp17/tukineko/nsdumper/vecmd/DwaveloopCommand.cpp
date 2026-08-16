#include "DwaveloopCommand.h"
#include "NScripter.h"

DwaveloopCommand::DwaveloopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

DwaveloopCommand::~DwaveloopCommand()
{
}

bool DwaveloopCommand::check(const QString &str)
{
    return checkCommand(str, "dwaveloop");
}

void DwaveloopCommand::execute()
{
    debug("[VECommand] dwaveloop");

    ns->error("dwaveloop");
}

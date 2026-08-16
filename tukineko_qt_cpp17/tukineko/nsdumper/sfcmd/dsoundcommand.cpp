#include "dsoundcommand.h"
#include "nscripter.h"

DsoundCommand::DsoundCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool DsoundCommand::check(const QString &str)
{
    return checkCommand(str, "dsound");
}

void DsoundCommand::execute()
{
    debug("[SFCommand] dsound");

    ns->error("dsound");
}

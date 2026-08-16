#include "humanzcommand.h"
#include "nscripter.h"

HumanzCommand::HumanzCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool HumanzCommand::check(const QString &str)
{
    return checkCommand(str, "humanz");
}

void HumanzCommand::execute()
{
    debug("[SFCommand] humanz");

    ns->error("humanz");
}

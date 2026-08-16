#include "GetregCommand.h"
#include "NScripter.h"

GetregCommand::GetregCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool GetregCommand::check(const QString &str)
{
    return checkCommand(str, "getreg");
}

void GetregCommand::execute()
{
    debug("[FECommand] getreg");

    ns->error("getreg");
}

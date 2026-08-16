#include "ModCommand.h"
#include "NScripter.h"

ModCommand::ModCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool ModCommand::check(const QString &str)
{
    return checkCommand(str, "mod");
}

void ModCommand::execute()
{
    debug("[FECommand] mod");

    ns->error("mod");
}

#include "AtoiCommand.h"
#include "NScripter.h"

AtoiCommand::AtoiCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool AtoiCommand::check(const QString &str)
{
    return checkCommand(str, "atoi");
}

void AtoiCommand::execute()
{
    debug("[FECommand] atoi");

    ns->error("atoi");
}

#include "ItoaCommand.h"
#include "NScripter.h"

ItoaCommand::ItoaCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool ItoaCommand::check(const QString &str)
{
    return checkCommand(str, "itoa");
}

void ItoaCommand::execute()
{
    debug("[FECommand] itoa");

    ns->error("itoa");
}

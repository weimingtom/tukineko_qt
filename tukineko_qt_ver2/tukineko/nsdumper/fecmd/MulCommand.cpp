#include "MulCommand.h"
#include "NScripter.h"

MulCommand::MulCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool MulCommand::check(const QString &str)
{
    return checkCommand(str, "mul");
}

void MulCommand::execute()
{
    debug("[FECommand] mul");

    ns->error("mul");
}

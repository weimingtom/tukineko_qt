#include "rlookbackcommand.h"
#include "nscripter.h"

RlookbackCommand::RlookbackCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool RlookbackCommand::check(const QString &str)
{
    return checkCommand(str, "rlookback");
}

void RlookbackCommand::execute()
{
    debug("[SFCommand] rlookback");

    ns->error("rlookback");
}

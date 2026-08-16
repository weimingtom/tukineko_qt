#include "transmodecommand.h"
#include "nscripter.h"

TransmodeCommand::TransmodeCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool TransmodeCommand::check(const QString &str)
{
    return checkCommand(str, "transmode");
}

void TransmodeCommand::execute()
{
    debug("[SFCommand] transmode");

    ns->error("transmode");
}

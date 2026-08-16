#include "EndCommand.h"
#include "NScripter.h"

EndCommand::EndCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool EndCommand::check(const QString &str)
{
    return checkCommand(str, "end");
}

void EndCommand::execute()
{
    debug("[FECommand] end");

    ns->setMsRest();
    ns->exitFlag = true;
}

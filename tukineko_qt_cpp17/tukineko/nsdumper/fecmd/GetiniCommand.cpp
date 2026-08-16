#include "GetiniCommand.h"
#include "NScripter.h"

GetiniCommand::GetiniCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool GetiniCommand::check(const QString &str)
{
    return checkCommand(str, "getini");
}

void GetiniCommand::execute()
{
    debug("[FECommand] getini");

    ns->error("getini");
}

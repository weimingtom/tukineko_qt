#include "DivCommand.h"
#include "NScripter.h"

DivCommand::DivCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool DivCommand::check(const QString &str)
{
    return checkCommand(str, "div");
}

void DivCommand::execute()
{
    debug("[FECommand] div");

    ns->error("div");
}

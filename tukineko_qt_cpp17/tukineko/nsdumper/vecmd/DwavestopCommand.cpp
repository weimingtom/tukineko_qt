#include "DwavestopCommand.h"
#include "NScripter.h"

DwavestopCommand::DwavestopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

DwavestopCommand::~DwavestopCommand()
{
}

bool DwavestopCommand::check(const QString &str)
{
    return checkCommand(str, "dwavestop");
}

void DwavestopCommand::execute()
{
    debug("[VECommand] dwavestop");

    ns->error("dwavestop");
}

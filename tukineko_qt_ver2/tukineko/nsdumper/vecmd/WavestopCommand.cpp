#include "WavestopCommand.h"
#include "NScripter.h"

WavestopCommand::WavestopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

WavestopCommand::~WavestopCommand()
{
}

bool WavestopCommand::check(const QString &str)
{
    return str.startsWith("wavestop");
}

void WavestopCommand::execute()
{
    debug("[VECommand] wavestop");

    ns->error("wavestop");
}

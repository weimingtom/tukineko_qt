#include "DwaveCommand.h"
#include "NScripter.h"

DwaveCommand::DwaveCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

DwaveCommand::~DwaveCommand()
{
}

bool DwaveCommand::check(const QString &str)
{
    return checkCommand(str, "dwave");
}

void DwaveCommand::execute()
{
    debug("[VECommand] dwave");

    ns->error("dwave");
}

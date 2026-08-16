#include "VspCommand.h"
#include "NScripter.h"

VspCommand::VspCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

VspCommand::~VspCommand()
{
}

bool VspCommand::check(const QString &str)
{
    return str.startsWith("vsp");
}

void VspCommand::execute()
{
    debug("[VECommand] vsp");

    if (ns->parseArgs(true) < 2) {
        ns->error("vsp");
    } else {
        ns->nd->sprite[ns->nd->evalNum(ns->getArg(0))].visible =
                (ns->nd->evalNum(ns->getArg(1)) == 1);
        ns->makeLineRest(2);
    }
}

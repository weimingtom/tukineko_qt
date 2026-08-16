#include "MspCommand.h"
#include "NScripter.h"

MspCommand::MspCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

MspCommand::~MspCommand()
{
}

bool MspCommand::check(const QString &str)
{
    return checkCommand(str, "msp");
}

void MspCommand::execute()
{
    debug("[VECommand] msp");

    if (ns->parseArgs(true) < 4) {
        ns->error("msp");
    } else {
        int i = ns->nd->evalNum(ns->getArg(0));
        ns->nd->sprite[i].x += ns->nd->evalNum(ns->getArg(1));
        ns->nd->sprite[i].y += ns->nd->evalNum(ns->getArg(2));
        ns->nd->sprite[i].alpha += ns->nd->evalNum(ns->getArg(3));
        ns->makeLineRest(4);
    }
}


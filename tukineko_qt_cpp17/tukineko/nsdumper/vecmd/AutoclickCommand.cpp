#include "AutoclickCommand.h"
#include "NScripter.h"

AutoclickCommand::AutoclickCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

AutoclickCommand::~AutoclickCommand()
{
}

bool AutoclickCommand::check(const QString &str)
{
    return checkCommand(str, "autoclick");
}

void AutoclickCommand::execute()
{
    debug("[VECommand] autoclick");

    if (ns->parseArgs(true) < 1) {
        ns->error("autoclick");
    } else {
        ns->nd->autoclick = ns->nd->evalNum(ns->getArg(0));
        ns->makeLineRest(1);
    }
}

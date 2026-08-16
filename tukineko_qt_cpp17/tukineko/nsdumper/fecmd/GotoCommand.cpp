#include "GotoCommand.h"
#include "NScripter.h"

GotoCommand::GotoCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool GotoCommand::check(const QString &str)
{
    return checkCommand(str, "goto");
}

void GotoCommand::execute()
{
    debug("[FECommand] goto");

    if (ns->parseArgs(true) < 1) {
        ns->error("goto");
    } else {
        ns->gotoLabel(ns->getArg(0));
        ns->makeLineRest(1);
    }
}

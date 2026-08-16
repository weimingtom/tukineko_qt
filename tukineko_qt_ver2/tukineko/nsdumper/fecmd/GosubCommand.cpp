#include "GosubCommand.h"
#include "NScripter.h"

GosubCommand::GosubCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool GosubCommand::check(const QString &str)
{
    return checkCommand(str, "gosub");
}

void GosubCommand::execute()
{
    debug("[FECommand] gosub");

    if (ns->parseArgs(true) < 1) {
        ns->error("gosub");
    } else if (ns->nd->gosubPos >= 8) {
        ns->error("gosub: nesting");
    } else {
        ns->nd->gosub[ns->nd->gosubPos].retpos = ns->getFilePointer();
        ns->nd->gosub[ns->nd->gosubPos].rest = ns->lineRest;
        ns->nd->gosubPos += 1;
        ns->gotoLabel(ns->getArg(0));
        ns->makeLineRest(1);
    }
}

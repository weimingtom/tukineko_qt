#include "DecCommand.h"
#include "NScripter.h"

DecCommand::DecCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool DecCommand::check(const QString &str)
{
    return checkCommand(str, "dec");
}

void DecCommand::execute()
{
    debug("[FECommand] dec");

    if (ns->parseArgs(true) < 1) {
        ns->error("dec");
    } else {
        if (!ns->getArg(0).startsWith("%")) {
            ns->error("dec");
        } else {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] -= 1;
        }
        ns->makeLineRest(1);
    }
}

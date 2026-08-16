#include "MovCommand.h"
#include "NScripter.h"

MovCommand::MovCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool MovCommand::check(const QString &str)
{
    return checkCommand(str, "mov");
}

void MovCommand::execute()
{
    debug("[FECommand] mov");

    if (ns->parseArgs(true) < 2) {
        ns->error("move");
    } else {
        if (ns->getArg(0).startsWith("%")) {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] = ns->nd->evalNum(ns->getArg(1));
        } else if (ns->getArg(0).startsWith("$")) {
            ns->nd->valueStr[ns->nd->evalNum(ns->getArg(0).mid(1))] = ns->nd->evalStr(ns->getArg(1));
        } else {
            ns->error("mov");
        }
        ns->makeLineRest(2);
    }
}

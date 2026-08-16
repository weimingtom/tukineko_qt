#include "AddCommand.h"
#include "NScripter.h"

AddCommand::AddCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool AddCommand::check(const QString &str)
{
    return checkCommand(str, "add");
}

void AddCommand::execute()
{
    debug("[FECommand] add");

    if (ns->parseArgs(true) < 2) {
        ns->error("add");
    } else {
        if (!ns->getArg(0).startsWith("%")) {
            ns->error("add");
        } else {
            ns->nd->valueNum[ns->nd->evalNum(ns->getArg(0).mid(1))] += ns->nd->evalNum(ns->getArg(1));
        }
        ns->makeLineRest(2);
    }
}

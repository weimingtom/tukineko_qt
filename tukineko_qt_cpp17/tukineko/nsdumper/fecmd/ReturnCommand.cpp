#include "ReturnCommand.h"
#include "NScripter.h"

ReturnCommand::ReturnCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool ReturnCommand::check(const QString &str)
{
    return str.startsWith("return");
}

void ReturnCommand::execute()
{
    debug("[FECommand] return");

    ns->setMsRest();
    ns->nd->historyPos = 0;
    ns->nd->historyCount = 0;
    ns->nd->gosubPos -= 1;
    ns->setFilePointer(ns->nd->gosub[ns->nd->gosubPos].retpos);
    ns->lineRest = ns->nd->gosub[ns->nd->gosubPos].rest;
}

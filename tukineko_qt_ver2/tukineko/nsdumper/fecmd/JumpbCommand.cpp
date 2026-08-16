#include "JumpbCommand.h"
#include "NScripter.h"

JumpbCommand::JumpbCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool JumpbCommand::check(const QString &str)
{
    return checkCommand(str, "jumpb");
}

void JumpbCommand::execute()
{
    debug("[FECommand] jumpb");

    ns->setFilePointer(ns->nd->jumpBack);
    ns->nd->historyPos = 0;
    ns->nd->historyCount = 0;
    ns->lineRest = QString();
}

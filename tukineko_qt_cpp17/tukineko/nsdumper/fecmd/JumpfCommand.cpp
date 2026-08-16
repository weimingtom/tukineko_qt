#include "JumpfCommand.h"
#include "NScripter.h"

JumpfCommand::JumpfCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool JumpfCommand::check(const QString &str)
{
    return checkCommand(str, "jumpf");
}

void JumpfCommand::execute()
{
    debug("[FECommand] jumpf");

    ns->lineRest = QString();
    while (true) {
        QString paramString = ns->readLine();
        if (paramString.startsWith("~")) {
            break;
        }
    }
    ns->nd->jumpBack = ns->getFilePointer();
}

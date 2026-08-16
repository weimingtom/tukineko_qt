#include "globaloncommand.h"
#include "nscripter.h"

GlobalonCommand::GlobalonCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool GlobalonCommand::check(const QString &str)
{
    return checkCommand(str, "globalon");
}

void GlobalonCommand::execute()
{
    debug("[SFCommand] globalon");

    ns->setMsRest();
    ns->nd->globalon = true;
    ns->loadGlobalData();
}

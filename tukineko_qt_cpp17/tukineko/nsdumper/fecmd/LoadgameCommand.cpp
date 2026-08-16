#include "LoadgameCommand.h"
#include "NScripter.h"

LoadgameCommand::LoadgameCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool LoadgameCommand::check(const QString &str)
{
    return checkCommand(str, "loadgame");
}

void LoadgameCommand::execute()
{
    debug("[FECommand] loadgame");

    if (ns->parseArgs(true) < 1) {
        ns->error("loadgame");
    } else {
        ns->storageState = 2;
        ns->loadLocalData("SAVE" + QString::number(ns->nd->evalNum(ns->getArg(0))) + ".DAT");
        ns->makeLineRest(1);
    }
}

#include "SavegameCommand.h"
#include "NScripter.h"

SavegameCommand::SavegameCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SavegameCommand::check(const QString &str)
{
    return checkCommand(str, "savegame");
}

void SavegameCommand::execute()
{
    debug("[FECommand] savegame");

    if (ns->parseArgs(true) < 1) {
        ns->error("savegame");
    } else {
        ns->storageState = 1;
        ns->saveLocalData("SAVE" + QString::number(ns->nd->evalNum(ns->getArg(0))) + ".DAT");
        ns->makeLineRest(1);
    }
}

#include "gamecommand.h"
#include "nscripter.h"

bool GameCommand::check(const QString &str)
{
    return str.startsWith("game");
}

void GameCommand::execute()
{
    debug("[FCommand] game");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();

    if (ns == nullptr) {
        debug("[FCommand] game ns == null");
        return;
    }

    ns->setMsRest();
    ns->tn->makemenu(ns->nd->savenumber, ns->path, ns->nd->savenameTitle);

    ns->gotoLabel("*start");
}

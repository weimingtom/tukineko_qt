#include "btndefcommand.h"
#include "nscripter.h"

bool BtndefCommand::check(const QString &str)
{
    return checkCommand(str, "btndef");
}

void BtndefCommand::execute()
{
    debug("[ECommand] btndef");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    if (ns->parseArgs(true) < 1) {
        ns->error("btndef");
    } else {
        ns->nd->btnImage = ns->nd->evalStr(ns->getArg(0));
        ns->nd->btnSel = -1;
        ns->nd->btn.clear();
        ns->makeLineRest(1);
    }
}

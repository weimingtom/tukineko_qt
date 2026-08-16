#include "nsacommand.h"
#include "nscripter.h"

NsaCommand::NsaCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool NsaCommand::check(const QString &str)
{
    return checkCommand(str, "nsa");
}

void NsaCommand::execute()
{
    debug("[SFCommand] nsa");

    ns->tn->initNsa(ns->path + "ARC.NSA");
}

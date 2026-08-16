#include "arccommand.h"
#include "nscripter.h"

ArcCommand::ArcCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool ArcCommand::check(const QString &str)
{
    return checkCommand(str, "arc");
}

void ArcCommand::execute()
{
    debug("[SFCommand] arc");

    ns->tn->initSar(ns->path + "ARC.SAR");
}

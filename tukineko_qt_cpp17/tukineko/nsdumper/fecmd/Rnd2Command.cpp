#include "Rnd2Command.h"
#include "NScripter.h"

Rnd2Command::Rnd2Command()
    : ns(tukineko::NScripter::getInstance())
{
}

bool Rnd2Command::check(const QString &str)
{
    return checkCommand(str, "rnd2");
}

void Rnd2Command::execute()
{
    debug("[FECommand] rnd2");

    ns->error("rnd2");
}

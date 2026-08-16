#include "btnwait2command.h"
#include "nscripter.h"

bool Btnwait2Command::check(const QString &str)
{
    return checkCommand(str, "btnwait2");
}

void Btnwait2Command::execute()
{
    debug("[ECommand] btnwait2");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("btnwait2");
}

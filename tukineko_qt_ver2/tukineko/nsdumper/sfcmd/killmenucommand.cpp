#include "killmenucommand.h"
#include "nscripter.h"

KillmenuCommand::KillmenuCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool KillmenuCommand::check(const QString &str)
{
    return checkCommand(str, "killmenu");
}

void KillmenuCommand::execute()
{
    debug("[SFCommand] killmenu");

    ns->error("killmenu");
}

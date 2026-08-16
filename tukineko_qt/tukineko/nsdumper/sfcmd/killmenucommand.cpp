#include "killmenucommand.h"

KillmenuCommand::KillmenuCommand()
{
}

KillmenuCommand::~KillmenuCommand()
{
}

bool KillmenuCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void KillmenuCommand::execute()
{
}

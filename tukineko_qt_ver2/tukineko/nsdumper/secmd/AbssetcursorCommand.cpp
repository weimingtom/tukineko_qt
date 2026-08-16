#include "AbssetcursorCommand.h"
#include "NScripter.h"

AbssetcursorCommand::AbssetcursorCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool AbssetcursorCommand::check(const QString &str)
{
    return str.startsWith("abssetcursor");
}

void AbssetcursorCommand::execute()
{
    debug("[SECommand] abssetcursor");

    ns->error("abssetcursor");
}

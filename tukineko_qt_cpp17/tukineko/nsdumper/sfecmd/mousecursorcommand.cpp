#include "mousecursorcommand.h"
#include "nscripter.h"

MousecursorCommand::MousecursorCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool MousecursorCommand::check(const QString &str)
{
    return checkCommand(str, "mousecursor");
}

void MousecursorCommand::execute()
{
    debug("[SFECommand] mousecursor");

    ns->error("mousecursor");
}

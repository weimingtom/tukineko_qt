#include "mousecursorcommand.h"

MousecursorCommand::MousecursorCommand()
{
    ns = NScripter::getInstance();
}

MousecursorCommand::~MousecursorCommand()
{
}

bool MousecursorCommand::check(const QString& str)
{
    return checkCommand(str, "mousecursor");
}

void MousecursorCommand::execute()
{
    debug("[SFECommand] mousecursor");

    ns->error("mousecursor");
}

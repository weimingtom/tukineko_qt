#include "menuwindowcommand.h"

MenuwindowCommand::MenuwindowCommand()
{
}

MenuwindowCommand::~MenuwindowCommand()
{
}

bool MenuwindowCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenuwindowCommand::execute()
{
}

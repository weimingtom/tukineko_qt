#include "menusetwindowcommand.h"

MenusetwindowCommand::MenusetwindowCommand()
{
}

MenusetwindowCommand::~MenusetwindowCommand()
{
}

bool MenusetwindowCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenusetwindowCommand::execute()
{
}

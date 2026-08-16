#include "MenuwindowCommand.h"
#include "NScripter.h"

MenuwindowCommand::MenuwindowCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

MenuwindowCommand::~MenuwindowCommand()
{
}

bool MenuwindowCommand::check(const QString &str)
{
    return str.startsWith("menu_window");
}

void MenuwindowCommand::execute()
{
    debug("[VECommand] menu_window");

    ns->error("menu_window");
}

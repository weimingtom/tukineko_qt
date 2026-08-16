#include "MenufullCommand.h"
#include "NScripter.h"

MenufullCommand::MenufullCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

MenufullCommand::~MenufullCommand()
{
}

bool MenufullCommand::check(const QString &str)
{
    return str.startsWith("menu_full");
}

void MenufullCommand::execute()
{
    debug("[VECommand] menu_full");

    ns->error("menu_full");
}

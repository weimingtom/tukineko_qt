#include "MenuclickdefCommand.h"
#include "NScripter.h"

MenuclickdefCommand::MenuclickdefCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

MenuclickdefCommand::~MenuclickdefCommand()
{
}

bool MenuclickdefCommand::check(const QString &str)
{
    return str.startsWith("menu_click_def");
}

void MenuclickdefCommand::execute()
{
    debug("[VECommand] menu_click_def");

    ns->error("menu_click_def");
}

#include "MenuclickpageCommand.h"
#include "NScripter.h"

MenuclickpageCommand::MenuclickpageCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

MenuclickpageCommand::~MenuclickpageCommand()
{
}

bool MenuclickpageCommand::check(const QString &str)
{
    return str.startsWith("menu_click_page");
}

void MenuclickpageCommand::execute()
{
    debug("[VECommand] menu_click_page");

    ns->error("menu_click_page");
}

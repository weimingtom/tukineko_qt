#include "menuclickdefcommand.h"

MenuclickdefCommand::MenuclickdefCommand()
{
}

MenuclickdefCommand::~MenuclickdefCommand()
{
}

bool MenuclickdefCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenuclickdefCommand::execute()
{
}

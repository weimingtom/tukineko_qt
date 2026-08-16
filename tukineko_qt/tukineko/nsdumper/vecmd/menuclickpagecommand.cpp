#include "menuclickpagecommand.h"

MenuclickpageCommand::MenuclickpageCommand()
{
}

MenuclickpageCommand::~MenuclickpageCommand()
{
}

bool MenuclickpageCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenuclickpageCommand::execute()
{
}

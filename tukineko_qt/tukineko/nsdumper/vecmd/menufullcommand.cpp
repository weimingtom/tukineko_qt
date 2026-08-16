#include "menufullcommand.h"

MenufullCommand::MenufullCommand()
{
}

MenufullCommand::~MenufullCommand()
{
}

bool MenufullCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenufullCommand::execute()
{
}

#include "menuselectcolorcommand.h"

MenuselectcolorCommand::MenuselectcolorCommand()
{
}

MenuselectcolorCommand::~MenuselectcolorCommand()
{
}

bool MenuselectcolorCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenuselectcolorCommand::execute()
{
}

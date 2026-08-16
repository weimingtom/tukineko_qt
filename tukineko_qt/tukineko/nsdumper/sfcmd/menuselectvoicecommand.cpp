#include "menuselectvoicecommand.h"

MenuselectvoiceCommand::MenuselectvoiceCommand()
{
}

MenuselectvoiceCommand::~MenuselectvoiceCommand()
{
}

bool MenuselectvoiceCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MenuselectvoiceCommand::execute()
{
}

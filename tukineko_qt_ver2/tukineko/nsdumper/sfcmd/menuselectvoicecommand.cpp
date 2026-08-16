#include "menuselectvoicecommand.h"
#include "nscripter.h"

MenuselectvoiceCommand::MenuselectvoiceCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool MenuselectvoiceCommand::check(const QString &str)
{
    return checkCommand(str, "menuselectvoice");
}

void MenuselectvoiceCommand::execute()
{
    debug("[SFCommand] menuselectvoice");

    ns->error("menuselectvoice");
}

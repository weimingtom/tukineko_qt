#include "selectvoicecommand.h"
#include "nscripter.h"

SelectvoiceCommand::SelectvoiceCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SelectvoiceCommand::check(const QString &str)
{
    return checkCommand(str, "selectvoice");
}

void SelectvoiceCommand::execute()
{
    debug("[SFCommand] selectvoice");

    ns->error("selectvoice");
}

#include "clickvoicecommand.h"
#include "nscripter.h"

ClickvoiceCommand::ClickvoiceCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool ClickvoiceCommand::check(const QString &str)
{
    return checkCommand(str, "clickvoice");
}

void ClickvoiceCommand::execute()
{
    debug("[SFCommand] clickvoice");

    ns->error("clickvoice");
}

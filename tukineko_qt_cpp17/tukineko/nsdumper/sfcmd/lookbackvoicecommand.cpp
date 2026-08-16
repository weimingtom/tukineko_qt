#include "lookbackvoicecommand.h"
#include "nscripter.h"

LookbackvoiceCommand::LookbackvoiceCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool LookbackvoiceCommand::check(const QString &str)
{
    return checkCommand(str, "lookbackvoice");
}

void LookbackvoiceCommand::execute()
{
    debug("[SFCommand] lookbackvoice");

    ns->error("lookbackvoice");
}

#include "lookbackflushcommand.h"
#include "nscripter.h"

bool LookbackflushCommand::check(const QString &str)
{
    return checkCommand(str, "lookbackflush");
}

void LookbackflushCommand::execute()
{
    debug("[ECommand] lookbackflush");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("lookbackflush");
}

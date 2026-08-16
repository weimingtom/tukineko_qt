#include "clickposcommand.h"
#include "nscripter.h"

bool ClickposCommand::check(const QString &str)
{
    return checkCommand(str, "clickpos");
}

void ClickposCommand::execute()
{
    debug("[ECommand] clickpos");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("clickpos");
}

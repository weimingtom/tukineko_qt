#include "clickcommand.h"
#include "nscripter.h"

bool ClickCommand::check(const QString &str)
{
    return checkCommand(str, "click");
}

void ClickCommand::execute()
{
    debug("[ECommand] click");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("click");
}

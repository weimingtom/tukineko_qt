#include "defineresetcommand.h"
#include "nscripter.h"

bool DefineresetCommand::check(const QString &str)
{
    return checkCommand(str, "definereset");
}

void DefineresetCommand::execute()
{
    debug("[ECommand] definereset");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("definereset");
}

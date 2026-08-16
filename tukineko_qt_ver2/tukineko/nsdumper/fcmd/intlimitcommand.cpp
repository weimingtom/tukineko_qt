#include "intlimitcommand.h"
#include "nscripter.h"

bool IntlimitCommand::check(const QString &str)
{
    return checkCommand(str, "intlimit");
}

void IntlimitCommand::execute()
{
    debug("[FCommand] intlimit");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("intlimit");
}

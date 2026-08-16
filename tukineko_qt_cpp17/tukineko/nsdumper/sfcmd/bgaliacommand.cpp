#include "bgaliacommand.h"
#include "nscripter.h"

BgaliaCommand::BgaliaCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool BgaliaCommand::check(const QString &str)
{
    return checkCommand(str, "bgalia");
}

void BgaliaCommand::execute()
{
    debug("[SFCommand] bgalia");

    ns->error("bgalia");
}

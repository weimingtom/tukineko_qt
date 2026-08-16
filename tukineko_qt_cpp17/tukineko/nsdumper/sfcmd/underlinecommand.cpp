#include "underlinecommand.h"
#include "nscripter.h"

UnderlineCommand::UnderlineCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool UnderlineCommand::check(const QString &str)
{
    return checkCommand(str, "underline");
}

void UnderlineCommand::execute()
{
    debug("[SFCommand] underline");

    ns->error("underline");
}

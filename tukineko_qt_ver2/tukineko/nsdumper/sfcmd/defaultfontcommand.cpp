#include "defaultfontcommand.h"
#include "nscripter.h"

DefaultfontCommand::DefaultfontCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool DefaultfontCommand::check(const QString &str)
{
    return checkCommand(str, "defaultfont");
}

void DefaultfontCommand::execute()
{
    debug("[SFCommand] defaultfont");

    ns->error("defaultfont");
}

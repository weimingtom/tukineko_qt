#include "textspeedcommand.h"
#include "nscripter.h"

bool TextspeedCommand::check(const QString &str)
{
    return checkCommand(str, "textspeed");
}

void TextspeedCommand::execute()
{
    debug("[ECommand] textspeed");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("textspeed");
}

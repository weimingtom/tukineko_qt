#include "inputstrcommand.h"
#include "nscripter.h"

bool InputstrCommand::check(const QString &str)
{
    return checkCommand(str, "inputstr");
}

void InputstrCommand::execute()
{
    debug("[ECommand] inputstr");

    tukineko::NScripter *ns = tukineko::NScripter::getInstance();
    ns->error("inputstr");
}

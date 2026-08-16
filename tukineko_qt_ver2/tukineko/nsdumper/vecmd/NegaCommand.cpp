#include "NegaCommand.h"
#include "NScripter.h"

NegaCommand::NegaCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

NegaCommand::~NegaCommand()
{
}

bool NegaCommand::check(const QString &str)
{
    return str.startsWith("nega");
}

void NegaCommand::execute()
{
    debug("[VECommand] nega");

    ns->error("nega");
}

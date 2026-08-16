#include "AviCommand.h"
#include "NScripter.h"

AviCommand::AviCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

AviCommand::~AviCommand()
{
}

bool AviCommand::check(const QString &str)
{
    return checkCommand(str, "avi");
}

void AviCommand::execute()
{
    debug("[VECommand] avi");

    ns->error("avi");
}

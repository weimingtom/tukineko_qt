#include "soundpressplgincommand.h"
#include "nscripter.h"

SoundpressplginCommand::SoundpressplginCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

bool SoundpressplginCommand::check(const QString &str)
{
    return checkCommand(str, "soundpressplgin");
}

void SoundpressplginCommand::execute()
{
    debug("[SFCommand] soundpressplgin");

    ns->error("soundpressplgin");
}

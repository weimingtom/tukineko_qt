#include "Mp3loopCommand.h"
#include "NScripter.h"

Mp3loopCommand::Mp3loopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

Mp3loopCommand::~Mp3loopCommand()
{
}

bool Mp3loopCommand::check(const QString &str)
{
    return checkCommand(str, "mp3loop");
}

void Mp3loopCommand::execute()
{
    debug("[VECommand] mp3loop");

    ns->error("mp3loop");
}

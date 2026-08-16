#include "PlayonceCommand.h"
#include "NScripter.h"

PlayonceCommand::PlayonceCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

PlayonceCommand::~PlayonceCommand()
{
}

bool PlayonceCommand::check(const QString &str)
{
    return str.startsWith("playonce");
}

void PlayonceCommand::execute()
{
    debug("[VECommand] playonce");

    ns->error("playonce");
}

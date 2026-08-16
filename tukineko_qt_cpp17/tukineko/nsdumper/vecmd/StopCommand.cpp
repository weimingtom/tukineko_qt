#include "StopCommand.h"
#include "NScripter.h"

namespace tukineko {

StopCommand::StopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

StopCommand::~StopCommand()
{
}

bool StopCommand::check(const QString &str)
{
    return str.startsWith("stop");
}

void StopCommand::execute()
{
    debug("[VECommand] stop");

    ns->error("stop");
}

}

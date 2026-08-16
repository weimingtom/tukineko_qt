#include "WaveloopCommand.h"
#include "NScripter.h"

namespace tukineko {

WaveloopCommand::WaveloopCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

WaveloopCommand::~WaveloopCommand()
{
}

bool WaveloopCommand::check(const QString &str)
{
    return str.startsWith("waveloop");
}

void WaveloopCommand::execute()
{
    debug("[VECommand] waveloop");

    ns->error("waveloop");
}

}

#include "PuttextCommand.h"
#include "NScripter.h"

namespace tukineko {

PuttextCommand::PuttextCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

PuttextCommand::~PuttextCommand()
{
}

bool PuttextCommand::check(const QString &str)
{
    return str.startsWith("puttext");
}

void PuttextCommand::execute()
{
    debug("[VECommand] puttext");

    ns->error("puttext");
}

}

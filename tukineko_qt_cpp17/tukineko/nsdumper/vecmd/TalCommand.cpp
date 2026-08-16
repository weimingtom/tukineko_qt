#include "TalCommand.h"
#include "NScripter.h"

namespace tukineko {

TalCommand::TalCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

TalCommand::~TalCommand()
{
}

bool TalCommand::check(const QString &str)
{
    return str.startsWith("tal");
}

void TalCommand::execute()
{
    debug("[VECommand] tal");

    ns->error("tal");
}

}

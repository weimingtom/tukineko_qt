#include "LocateCommand.h"
#include "NScripter.h"

LocateCommand::LocateCommand()
    : ns(tukineko::NScripter::getInstance())
{
}

LocateCommand::~LocateCommand()
{
}

bool LocateCommand::check(const QString &str)
{
    return str.startsWith("locate");
}

void LocateCommand::execute()
{
    debug("[VECommand] locate");

    ns->error("abssetcursor");
}

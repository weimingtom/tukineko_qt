#include "stopcommand.h"

StopCommand::StopCommand()
{
}

StopCommand::~StopCommand()
{
}

bool StopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void StopCommand::execute()
{
}

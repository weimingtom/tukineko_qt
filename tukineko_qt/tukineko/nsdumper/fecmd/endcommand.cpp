#include "endcommand.h"

EndCommand::EndCommand()
{
}

EndCommand::~EndCommand()
{
}

bool EndCommand::check(const QString& str)
{
    return str == "end";
}

void EndCommand::execute()
{
}

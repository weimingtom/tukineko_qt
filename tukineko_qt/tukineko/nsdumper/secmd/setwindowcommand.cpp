#include "setwindowcommand.h"

SetwindowCommand::SetwindowCommand()
{
}

SetwindowCommand::~SetwindowCommand()
{
}

bool SetwindowCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SetwindowCommand::execute()
{
}

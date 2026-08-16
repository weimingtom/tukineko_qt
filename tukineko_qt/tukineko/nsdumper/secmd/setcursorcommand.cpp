#include "setcursorcommand.h"

SetcursorCommand::SetcursorCommand()
{
}

SetcursorCommand::~SetcursorCommand()
{
}

bool SetcursorCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SetcursorCommand::execute()
{
}

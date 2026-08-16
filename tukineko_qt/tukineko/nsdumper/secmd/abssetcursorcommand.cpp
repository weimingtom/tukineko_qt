#include "abssetcursorcommand.h"

AbssetcursorCommand::AbssetcursorCommand()
{
}

AbssetcursorCommand::~AbssetcursorCommand()
{
}

bool AbssetcursorCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void AbssetcursorCommand::execute()
{
}

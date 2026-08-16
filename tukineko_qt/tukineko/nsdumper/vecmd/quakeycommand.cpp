#include "quakeycommand.h"

QuakeyCommand::QuakeyCommand()
{
}

QuakeyCommand::~QuakeyCommand()
{
}

bool QuakeyCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void QuakeyCommand::execute()
{
}

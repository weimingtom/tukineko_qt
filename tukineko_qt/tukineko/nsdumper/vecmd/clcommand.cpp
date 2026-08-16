#include "clcommand.h"

ClCommand::ClCommand()
{
}

ClCommand::~ClCommand()
{
}

bool ClCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void ClCommand::execute()
{
}

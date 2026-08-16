#include "straliascommand.h"

StraliasCommand::StraliasCommand()
{
}

StraliasCommand::~StraliasCommand()
{
}

bool StraliasCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void StraliasCommand::execute()
{
}

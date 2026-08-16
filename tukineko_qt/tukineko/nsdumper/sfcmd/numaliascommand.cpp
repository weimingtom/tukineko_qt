#include "numaliascommand.h"

NumaliasCommand::NumaliasCommand()
{
}

NumaliasCommand::~NumaliasCommand()
{
}

bool NumaliasCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void NumaliasCommand::execute()
{
}


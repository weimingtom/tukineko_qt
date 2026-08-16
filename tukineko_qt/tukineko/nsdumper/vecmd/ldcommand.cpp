#include "ldcommand.h"

LdCommand::LdCommand()
{
}

LdCommand::~LdCommand()
{
}

bool LdCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LdCommand::execute()
{
}


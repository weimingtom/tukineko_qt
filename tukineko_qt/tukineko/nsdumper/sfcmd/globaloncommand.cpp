#include "globaloncommand.h"

GlobalonCommand::GlobalonCommand()
{
}

GlobalonCommand::~GlobalonCommand()
{
}

bool GlobalonCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void GlobalonCommand::execute()
{
}

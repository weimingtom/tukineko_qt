#include "roffcommand.h"

RoffCommand::RoffCommand()
{
}

RoffCommand::~RoffCommand()
{
}

bool RoffCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void RoffCommand::execute()
{
}

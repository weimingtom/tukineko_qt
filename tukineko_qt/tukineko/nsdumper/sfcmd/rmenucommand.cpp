#include "rmenucommand.h"

RmenuCommand::RmenuCommand()
{
}

RmenuCommand::~RmenuCommand()
{
}

bool RmenuCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void RmenuCommand::execute()
{
}

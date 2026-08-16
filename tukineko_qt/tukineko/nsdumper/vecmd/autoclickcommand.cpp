#include "autoclickcommand.h"

AutoclickCommand::AutoclickCommand()
{
}

AutoclickCommand::~AutoclickCommand()
{
}

bool AutoclickCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void AutoclickCommand::execute()
{
}


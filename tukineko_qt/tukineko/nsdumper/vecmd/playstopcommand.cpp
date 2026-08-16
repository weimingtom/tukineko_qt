#include "playstopcommand.h"

PlaystopCommand::PlaystopCommand()
{
}

PlaystopCommand::~PlaystopCommand()
{
}

bool PlaystopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void PlaystopCommand::execute()
{
}

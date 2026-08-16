#include "playcommand.h"

PlayCommand::PlayCommand()
{
}

PlayCommand::~PlayCommand()
{
}

bool PlayCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void PlayCommand::execute()
{
}

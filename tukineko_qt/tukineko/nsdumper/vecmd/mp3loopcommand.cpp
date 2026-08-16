#include "mp3loopcommand.h"

Mp3loopCommand::Mp3loopCommand()
{
}

Mp3loopCommand::~Mp3loopCommand()
{
}

bool Mp3loopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void Mp3loopCommand::execute()
{
}


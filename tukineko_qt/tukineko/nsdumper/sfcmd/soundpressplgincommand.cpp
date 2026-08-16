#include "soundpressplgincommand.h"

SoundpressplginCommand::SoundpressplginCommand()
{
}

SoundpressplginCommand::~SoundpressplginCommand()
{
}

bool SoundpressplginCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SoundpressplginCommand::execute()
{
}

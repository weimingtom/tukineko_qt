#include "wavecommand.h"

WaveCommand::WaveCommand()
{
}

WaveCommand::~WaveCommand()
{
}

bool WaveCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void WaveCommand::execute()
{
}

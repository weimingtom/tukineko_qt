#include "waveloopcommand.h"

WaveloopCommand::WaveloopCommand()
{
}

WaveloopCommand::~WaveloopCommand()
{
}

bool WaveloopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void WaveloopCommand::execute()
{
}

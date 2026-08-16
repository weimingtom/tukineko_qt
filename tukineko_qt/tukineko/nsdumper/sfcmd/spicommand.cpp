#include "spicommand.h"

SpiCommand::SpiCommand()
{
}

SpiCommand::~SpiCommand()
{
}

bool SpiCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SpiCommand::execute()
{
}

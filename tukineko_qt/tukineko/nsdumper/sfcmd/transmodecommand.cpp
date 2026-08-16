#include "transmodecommand.h"

TransmodeCommand::TransmodeCommand()
{
}

TransmodeCommand::~TransmodeCommand()
{
}

bool TransmodeCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void TransmodeCommand::execute()
{
}

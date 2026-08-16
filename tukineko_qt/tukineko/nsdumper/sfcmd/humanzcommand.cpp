#include "humanzcommand.h"

HumanzCommand::HumanzCommand()
{
}

HumanzCommand::~HumanzCommand()
{
}

bool HumanzCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void HumanzCommand::execute()
{
}

#include "defspeedcommand.h"

DefSpeedCommand::DefSpeedCommand()
{
}

DefSpeedCommand::~DefSpeedCommand()
{
}

bool DefSpeedCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void DefSpeedCommand::execute()
{
}

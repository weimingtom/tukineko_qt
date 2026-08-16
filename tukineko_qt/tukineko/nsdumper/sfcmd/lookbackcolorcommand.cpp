#include "lookbackcolorcommand.h"

LookbackcolorCommand::LookbackcolorCommand()
{
}

LookbackcolorCommand::~LookbackcolorCommand()
{
}

bool LookbackcolorCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LookbackcolorCommand::execute()
{
}

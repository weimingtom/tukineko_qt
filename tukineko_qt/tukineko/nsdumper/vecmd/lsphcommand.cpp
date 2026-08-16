#include "lsphcommand.h"

LsphCommand::LsphCommand()
{
}

LsphCommand::~LsphCommand()
{
}

bool LsphCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LsphCommand::execute()
{
}

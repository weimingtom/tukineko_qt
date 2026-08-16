#include "bltcommand.h"

BltCommand::BltCommand()
{
}

BltCommand::~BltCommand()
{
}

bool BltCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void BltCommand::execute()
{
}


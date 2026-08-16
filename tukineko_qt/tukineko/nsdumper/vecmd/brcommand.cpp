#include "brcommand.h"

BrCommand::BrCommand()
{
}

BrCommand::~BrCommand()
{
}

bool BrCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void BrCommand::execute()
{
}


#include "fcommand.h"

FCommand::FCommand()
{
}

FCommand::~FCommand()
{
}

bool FCommand::check(const QString& str)
{
    Q_UNUSED(str);
    return false;
}

void FCommand::execute()
{
}

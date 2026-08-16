#include "mspcommand.h"

MspCommand::MspCommand()
{
}

MspCommand::~MspCommand()
{
}

bool MspCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void MspCommand::execute()
{
}

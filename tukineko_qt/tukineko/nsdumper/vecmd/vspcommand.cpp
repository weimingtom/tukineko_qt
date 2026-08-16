#include "vspcommand.h"

VspCommand::VspCommand()
{
}

VspCommand::~VspCommand()
{
}

bool VspCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void VspCommand::execute()
{
}

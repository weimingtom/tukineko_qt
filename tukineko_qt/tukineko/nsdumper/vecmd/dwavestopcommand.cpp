#include "dwavestopcommand.h"

DwavestopCommand::DwavestopCommand()
{
}

DwavestopCommand::~DwavestopCommand()
{
}

bool DwavestopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void DwavestopCommand::execute()
{
}

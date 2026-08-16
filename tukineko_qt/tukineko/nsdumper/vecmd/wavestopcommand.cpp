#include "wavestopcommand.h"

WavestopCommand::WavestopCommand()
{
}

WavestopCommand::~WavestopCommand()
{
}

bool WavestopCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void WavestopCommand::execute()
{
}

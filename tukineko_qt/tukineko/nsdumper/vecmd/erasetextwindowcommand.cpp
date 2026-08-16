#include "erasetextwindowcommand.h"

ErasetextwindowCommand::ErasetextwindowCommand()
{
}

ErasetextwindowCommand::~ErasetextwindowCommand()
{
}

bool ErasetextwindowCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void ErasetextwindowCommand::execute()
{
}

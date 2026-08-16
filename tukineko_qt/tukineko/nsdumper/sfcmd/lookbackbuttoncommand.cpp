#include "lookbackbuttoncommand.h"

LookbackbuttonCommand::LookbackbuttonCommand()
{
}

LookbackbuttonCommand::~LookbackbuttonCommand()
{
}

bool LookbackbuttonCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LookbackbuttonCommand::execute()
{
}

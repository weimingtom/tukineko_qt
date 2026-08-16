#include "talcommand.h"

TalCommand::TalCommand()
{
}

TalCommand::~TalCommand()
{
}

bool TalCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void TalCommand::execute()
{
}

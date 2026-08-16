#include "puttextcommand.h"

PuttextCommand::PuttextCommand()
{
}

PuttextCommand::~PuttextCommand()
{
}

bool PuttextCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void PuttextCommand::execute()
{
}

#include "effectblankcommand.h"

EffectblankCommand::EffectblankCommand()
{
}

EffectblankCommand::~EffectblankCommand()
{
}

bool EffectblankCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void EffectblankCommand::execute()
{
}


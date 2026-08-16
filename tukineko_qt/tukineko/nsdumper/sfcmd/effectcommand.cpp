#include "effectcommand.h"

EffectCommand::EffectCommand()
{
}

EffectCommand::~EffectCommand()
{
}

bool EffectCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void EffectCommand::execute()
{
}


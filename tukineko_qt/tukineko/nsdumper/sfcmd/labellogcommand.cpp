#include "labellogcommand.h"

LabellogCommand::LabellogCommand()
{
}

LabellogCommand::~LabellogCommand()
{
}

bool LabellogCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LabellogCommand::execute()
{
}



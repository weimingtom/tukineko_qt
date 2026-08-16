#include "ofscpycommand.h"

OfscpyCommand::OfscpyCommand()
{
}

OfscpyCommand::~OfscpyCommand()
{
}

bool OfscpyCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void OfscpyCommand::execute()
{
}

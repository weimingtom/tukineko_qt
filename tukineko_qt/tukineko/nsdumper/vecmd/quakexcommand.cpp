#include "quakexcommand.h"

QuakexCommand::QuakexCommand()
{
}

QuakexCommand::~QuakexCommand()
{
}

bool QuakexCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void QuakexCommand::execute()
{
}

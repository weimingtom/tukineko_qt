#include "deccommand.h"

DecCommand::DecCommand()
{
}

DecCommand::~DecCommand()
{
}

bool DecCommand::check(const QString& str)
{
    return str.startsWith("dec ");
}

void DecCommand::execute()
{
}

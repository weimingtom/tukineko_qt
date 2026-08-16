#include "atoicommand.h"

AtoiCommand::AtoiCommand()
{
}

AtoiCommand::~AtoiCommand()
{
}

bool AtoiCommand::check(const QString& str)
{
    return str.startsWith("atoi ");
}

void AtoiCommand::execute()
{
}

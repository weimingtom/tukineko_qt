#include "addcommand.h"

AddCommand::AddCommand()
{
}

AddCommand::~AddCommand()
{
}

bool AddCommand::check(const QString& str)
{
    return str.startsWith("add ");
}

void AddCommand::execute()
{
}

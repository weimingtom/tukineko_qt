#include "modcommand.h"

ModCommand::ModCommand()
{

}

ModCommand::~ModCommand()
{

}

bool ModCommand::check(const QString& str)
{
    return str.startsWith("mod ");
}

void ModCommand::execute()
{

}

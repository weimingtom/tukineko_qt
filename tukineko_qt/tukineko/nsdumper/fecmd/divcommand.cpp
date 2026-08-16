#include "divcommand.h"

DivCommand::DivCommand()
{
}

DivCommand::~DivCommand()
{
}

bool DivCommand::check(const QString& str)
{
    return str.startsWith("div ");
}

void DivCommand::execute()
{
}

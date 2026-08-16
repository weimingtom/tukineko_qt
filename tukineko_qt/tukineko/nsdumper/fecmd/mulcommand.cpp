#include "mulcommand.h"

MulCommand::MulCommand()
{

}

MulCommand::~MulCommand()
{

}

bool MulCommand::check(const QString& str)
{
    return str.startsWith("mul ");
}

void MulCommand::execute()
{

}

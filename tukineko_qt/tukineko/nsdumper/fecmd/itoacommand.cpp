#include "itoacommand.h"

ItoaCommand::ItoaCommand()
{

}

ItoaCommand::~ItoaCommand()
{

}

bool ItoaCommand::check(const QString& str)
{
    return str.startsWith("itoa ");
}

void ItoaCommand::execute()
{

}

#include "cmpcommand.h"

CmpCommand::CmpCommand()
{
}

CmpCommand::~CmpCommand()
{
}

bool CmpCommand::check(const QString& str)
{
    return str.startsWith("cmp ");
}

void CmpCommand::execute()
{
}

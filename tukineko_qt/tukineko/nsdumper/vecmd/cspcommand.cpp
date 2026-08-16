#include "cspcommand.h"

CspCommand::CspCommand()
{
}

CspCommand::~CspCommand()
{
}

bool CspCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void CspCommand::execute()
{
}


#include "cdfadeoutcommand.h"

CdfadeoutCommand::CdfadeoutCommand()
{
}

CdfadeoutCommand::~CdfadeoutCommand()
{
}

bool CdfadeoutCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void CdfadeoutCommand::execute()
{
}

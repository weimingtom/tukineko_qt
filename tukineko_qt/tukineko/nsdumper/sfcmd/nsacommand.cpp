#include "nsacommand.h"

NsaCommand::NsaCommand()
{
}

NsaCommand::~NsaCommand()
{
}

bool NsaCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void NsaCommand::execute()
{
}

#include "playoncecommand.h"

PlayonceCommand::PlayonceCommand()
{
}

PlayonceCommand::~PlayonceCommand()
{
}

bool PlayonceCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void PlayonceCommand::execute()
{
}

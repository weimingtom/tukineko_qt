#include "lspcommand.h"

LspCommand::LspCommand()
{
}

LspCommand::~LspCommand()
{
}

bool LspCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LspCommand::execute()
{
}


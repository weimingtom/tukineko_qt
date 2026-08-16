#include "lookbackvoicecommand.h"

LookbackvoiceCommand::LookbackvoiceCommand()
{
}

LookbackvoiceCommand::~LookbackvoiceCommand()
{
}

bool LookbackvoiceCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void LookbackvoiceCommand::execute()
{
}

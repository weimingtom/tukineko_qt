#include "selectvoicecommand.h"

SelectvoiceCommand::SelectvoiceCommand()
{
}

SelectvoiceCommand::~SelectvoiceCommand()
{
}

bool SelectvoiceCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void SelectvoiceCommand::execute()
{
}

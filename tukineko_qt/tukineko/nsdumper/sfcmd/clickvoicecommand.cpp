#include "clickvoicecommand.h"

ClickvoiceCommand::ClickvoiceCommand()
{
}

ClickvoiceCommand::~ClickvoiceCommand()
{
}

bool ClickvoiceCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void ClickvoiceCommand::execute()
{
}


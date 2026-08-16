#include "intlimitcommand.h"

IntlimitCommand::IntlimitCommand()
{
    m_cmdName = "intlimit";
}

IntlimitCommand::~IntlimitCommand()
{
}

bool IntlimitCommand::check(const QString& str)
{
    return str.startsWith("intlimit ");
}

void IntlimitCommand::execute()
{
}

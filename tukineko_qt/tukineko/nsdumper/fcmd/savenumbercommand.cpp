#include "savenumbercommand.h"

SavenumberCommand::SavenumberCommand()
{
    m_cmdName = "savenumber";
}

SavenumberCommand::~SavenumberCommand()
{
}

bool SavenumberCommand::check(const QString& str)
{
    return str.startsWith("savenumber ");
}

void SavenumberCommand::execute()
{
}

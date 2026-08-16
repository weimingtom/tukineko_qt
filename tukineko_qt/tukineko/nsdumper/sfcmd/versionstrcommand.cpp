#include "versionstrcommand.h"

VersionstrCommand::VersionstrCommand()
{
}

VersionstrCommand::~VersionstrCommand()
{
}

bool VersionstrCommand::check(const QString& str)
{
    return str.startsWith("abssetcursor");
}

void VersionstrCommand::execute()
{
}

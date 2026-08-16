#include "versionstrcommand.h"
#include <iostream>

VersionstrCommand::VersionstrCommand()
{
}

bool VersionstrCommand::check(const QString &str)
{
    return checkCommand(str, "versionstr");
}

void VersionstrCommand::execute()
{
    debug("[SFCommand] versionstr");

    std::cerr << "not implement: versionstr" << std::endl;
}

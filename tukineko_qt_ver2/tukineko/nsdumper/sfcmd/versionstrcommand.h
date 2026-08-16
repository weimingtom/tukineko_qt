#ifndef VERSIONSTRCOMMAND_H
#define VERSIONSTRCOMMAND_H

#include "sfcommand.h"

class VersionstrCommand : public SFCommand
{
public:
    VersionstrCommand();

    bool check(const QString &str) override;
    void execute() override;
};

#endif // VERSIONSTRCOMMAND_H

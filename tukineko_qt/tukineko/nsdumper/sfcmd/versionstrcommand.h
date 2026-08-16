#ifndef VERSIONSTRCOMMAND_H
#define VERSIONSTRCOMMAND_H

#include <QString>
#include "sfcommand.h"

class VersionstrCommand : public SFCommand
{
public:
    VersionstrCommand();
    virtual ~VersionstrCommand();

    bool check(const QString& str);
    void execute();
};

#endif // VERSIONSTRCOMMAND_H

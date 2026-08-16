#ifndef NSACOMMAND_H
#define NSACOMMAND_H

#include <QString>
#include "sfcommand.h"

class NsaCommand : public SFCommand
{
public:
    NsaCommand();
    virtual ~NsaCommand();

    bool check(const QString& str);
    void execute();
};

#endif // NSACOMMAND_H


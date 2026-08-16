#ifndef CDFADEOUTCOMMAND_H
#define CDFADEOUTCOMMAND_H

#include <QString>
#include "sfcommand.h"

class CdfadeoutCommand : public SFCommand
{
public:
    CdfadeoutCommand();
    virtual ~CdfadeoutCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CDFADEOUTCOMMAND_H

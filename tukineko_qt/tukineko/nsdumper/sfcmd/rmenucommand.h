#ifndef RMENUCOMMAND_H
#define RMENUCOMMAND_H

#include <QString>
#include "sfcommand.h"

class RmenuCommand : public SFCommand
{
public:
    RmenuCommand();
    virtual ~RmenuCommand();

    bool check(const QString& str);
    void execute();
};

#endif // RMENUCOMMAND_H


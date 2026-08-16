#ifndef LABELLOGCOMMAND_H
#define LABELLOGCOMMAND_H

#include <QString>
#include "sfcommand.h"

class LabellogCommand : public SFCommand
{
public:
    LabellogCommand();
    virtual ~LabellogCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LABELLOGCOMMAND_H

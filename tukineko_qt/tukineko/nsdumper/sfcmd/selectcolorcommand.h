#ifndef SELECTCOLORCOMMAND_H
#define SELECTCOLORCOMMAND_H

#include <QString>
#include "sfcommand.h"

class SelectcolorCommand : public SFCommand
{
public:
    SelectcolorCommand();
    virtual ~SelectcolorCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SELECTCOLORCOMMAND_H

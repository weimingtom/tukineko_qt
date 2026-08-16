#ifndef CLICKSTRCOMMAND_H
#define CLICKSTRCOMMAND_H

#include <QString>
#include "sfcommand.h"

class ClickstrCommand : public SFCommand
{
public:
    ClickstrCommand();
    virtual ~ClickstrCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CLICKSTRCOMMAND_H

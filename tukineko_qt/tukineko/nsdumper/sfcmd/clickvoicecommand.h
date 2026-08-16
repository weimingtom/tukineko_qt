#ifndef CLICKVOICECOMMAND_H
#define CLICKVOICECOMMAND_H

#include <QString>
#include "sfcommand.h"

class ClickvoiceCommand : public SFCommand
{
public:
    ClickvoiceCommand();
    virtual ~ClickvoiceCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CLICKVOICECOMMAND_H

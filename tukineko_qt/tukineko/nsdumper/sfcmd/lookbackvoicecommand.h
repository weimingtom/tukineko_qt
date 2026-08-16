#ifndef LOOKBACKVOICECOMMAND_H
#define LOOKBACKVOICECOMMAND_H

#include <QString>
#include "sfcommand.h"

class LookbackvoiceCommand : public SFCommand
{
public:
    LookbackvoiceCommand();
    virtual ~LookbackvoiceCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LOOKBACKVOICECOMMAND_H


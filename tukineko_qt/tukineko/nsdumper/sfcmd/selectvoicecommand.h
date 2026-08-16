#ifndef SELECTVOICECOMMAND_H
#define SELECTVOICECOMMAND_H

#include <QString>
#include "sfcommand.h"

class SelectvoiceCommand : public SFCommand
{
public:
    SelectvoiceCommand();
    virtual ~SelectvoiceCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SELECTVOICECOMMAND_H

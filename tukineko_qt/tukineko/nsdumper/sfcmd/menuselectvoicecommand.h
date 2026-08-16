#ifndef MENUSELECTVOICECOMMAND_H
#define MENUSELECTVOICECOMMAND_H

#include <QString>
#include "sfcommand.h"

class MenuselectvoiceCommand : public SFCommand
{
public:
    MenuselectvoiceCommand();
    virtual ~MenuselectvoiceCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MENUSELECTVOICECOMMAND_H

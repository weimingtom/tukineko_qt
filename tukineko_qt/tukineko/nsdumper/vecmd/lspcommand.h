#ifndef LSPCOMMAND_H
#define LSPCOMMAND_H

#include <QString>
#include "vecommand.h"

class LspCommand : public VECommand
{
public:
    LspCommand();
    virtual ~LspCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LSPCOMMAND_H

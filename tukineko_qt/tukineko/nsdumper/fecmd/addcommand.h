#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <QString>
#include "fecommand.h"

class AddCommand : public FECommand
{
public:
    AddCommand();
    virtual ~AddCommand();

    bool check(const QString& str);
    void execute();
};

#endif // ADDCOMMAND_H

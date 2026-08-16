#ifndef TEXTONCOMMAND_H
#define TEXTONCOMMAND_H

#include <QString>
#include "vecommand.h"

class TextonCommand : public VECommand
{
public:
    TextonCommand();
    virtual ~TextonCommand();

    bool check(const QString& str);
    void execute();
};

#endif // TEXTONCOMMAND_H

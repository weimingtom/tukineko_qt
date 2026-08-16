#ifndef TEXTOFFCOMMAND_H
#define TEXTOFFCOMMAND_H

#include <QString>
#include "vecommand.h"

class TextoffCommand : public VECommand
{
public:
    TextoffCommand();
    virtual ~TextoffCommand();

    bool check(const QString& str);
    void execute();
};

#endif // TEXTOFFCOMMAND_H

#ifndef TEXTCLEARCOMMAND_H
#define TEXTCLEARCOMMAND_H

#include <QString>
#include "vecommand.h"

class TextclearCommand : public VECommand
{
public:
    TextclearCommand();
    virtual ~TextclearCommand();

    bool check(const QString& str);
    void execute();
};

#endif // TEXTCLEARCOMMAND_H

#ifndef TEXTSPEEDCOMMAND_H
#define TEXTSPEEDCOMMAND_H

#include "ecommand.h"

class TextspeedCommand : public ECommand
{
public:
    TextspeedCommand();
    virtual ~TextspeedCommand();
    bool check(const QString& str);
    void execute();
};

#endif // TEXTSPEEDCOMMAND_H

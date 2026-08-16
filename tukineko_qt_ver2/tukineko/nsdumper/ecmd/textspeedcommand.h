#ifndef TEXTSPEEDCOMMAND_H
#define TEXTSPEEDCOMMAND_H

#include "ecommand.h"

class TextspeedCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // TEXTSPEEDCOMMAND_H

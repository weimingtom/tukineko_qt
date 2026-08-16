#ifndef GETVERSIONCOMMAND_H
#define GETVERSIONCOMMAND_H

#include <QString>
#include "sfecommand.h"
#include "nscripter.h"

class GetversionCommand : public SFECommand
{
private:
    NScripter* ns;
public:
    GetversionCommand();
    virtual ~GetversionCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GETVERSIONCOMMAND_H

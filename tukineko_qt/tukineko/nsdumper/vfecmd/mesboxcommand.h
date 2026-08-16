#ifndef MESBOXCOMMAND_H
#define MESBOXCOMMAND_H

#include <QString>
#include "vfecommand.h"
#include "nscripter.h"

class MesboxCommand : public VFECommand
{
private:
    NScripter* ns;
public:
    MesboxCommand();
    virtual ~MesboxCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MESBOXCOMMAND_H

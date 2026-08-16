#ifndef WINDOWEFFECTCOMMAND_H
#define WINDOWEFFECTCOMMAND_H

#include <QString>
#include "sfecommand.h"
#include "nscripter.h"

class WindoweffectCommand : public SFECommand
{
private:
    NScripter* ns;
public:
    WindoweffectCommand();
    virtual ~WindoweffectCommand();

    bool check(const QString& str);
    void execute();
};

#endif // WINDOWEFFECTCOMMAND_H


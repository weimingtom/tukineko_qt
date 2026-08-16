#ifndef MOUSECURSORCOMMAND_H
#define MOUSECURSORCOMMAND_H

#include <QString>
#include "sfecommand.h"
#include "nscripter.h"

class MousecursorCommand : public SFECommand
{
private:
    NScripter* ns;
public:
    MousecursorCommand();
    virtual ~MousecursorCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MOUSECURSORCOMMAND_H

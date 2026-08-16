#ifndef DEFAULTFONTCOMMAND_H
#define DEFAULTFONTCOMMAND_H

#include <QString>
#include "sfcommand.h"

class DefaultfontCommand : public SFCommand
{
public:
    DefaultfontCommand();
    virtual ~DefaultfontCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DEFAULTFONTCOMMAND_H


#ifndef LOCATECOMMAND_H
#define LOCATECOMMAND_H

#include <QString>
#include "vecommand.h"

class LocateCommand : public VECommand
{
public:
    LocateCommand();
    virtual ~LocateCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LOCATECOMMAND_H

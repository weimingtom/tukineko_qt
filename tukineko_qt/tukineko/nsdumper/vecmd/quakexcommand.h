#ifndef QUAKEXCOMMAND_H
#define QUAKEXCOMMAND_H

#include <QString>
#include "vecommand.h"

class QuakexCommand : public VECommand
{
public:
    QuakexCommand();
    virtual ~QuakexCommand();

    bool check(const QString& str);
    void execute();
};

#endif // QUAKEXCOMMAND_H


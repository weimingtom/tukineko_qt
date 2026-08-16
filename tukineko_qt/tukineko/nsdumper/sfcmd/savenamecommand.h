#ifndef SAVENAMECOMMAND_H
#define SAVENAMECOMMAND_H

#include <QString>
#include "sfcommand.h"

class SavenameCommand : public SFCommand
{
public:
    SavenameCommand();
    virtual ~SavenameCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SAVENAMECOMMAND_H

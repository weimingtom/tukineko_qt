#ifndef DATECOMMAND_H
#define DATECOMMAND_H

#include <QString>
#include "fecommand.h"

class DateCommand : public FECommand
{
public:
    DateCommand();
    virtual ~DateCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DATECOMMAND_H

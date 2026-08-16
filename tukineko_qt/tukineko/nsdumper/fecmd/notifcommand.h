#ifndef NOTIFCOMMAND_H
#define NOTIFCOMMAND_H

#include <QString>
#include "fecommand.h"

class NotifCommand : public FECommand
{
public:
    NotifCommand();
    virtual ~NotifCommand();

    bool check(const QString& str);
    void execute();
};

#endif // NOTIFCOMMAND_H

#ifndef VECOMMAND_H
#define VECOMMAND_H

#include <QString>
#include <QDebug>

namespace tukineko {

class VECommand
{
public:
    VECommand();
    virtual ~VECommand();

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

}

#endif // VECOMMAND_H

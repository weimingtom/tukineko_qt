#ifndef VFECOMMAND_H
#define VFECOMMAND_H

#include <QString>
#include <QDebug>

namespace tukineko {

class VFECommand
{
public:
    VFECommand();
    virtual ~VFECommand();

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

}

#endif // VFECOMMAND_H

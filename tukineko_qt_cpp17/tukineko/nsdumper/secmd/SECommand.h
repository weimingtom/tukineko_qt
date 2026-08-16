#ifndef SECOMMAND_H
#define SECOMMAND_H

#include <QString>

class SECommand
{
public:
    SECommand();
    virtual ~SECommand();

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

#endif // SECOMMAND_H

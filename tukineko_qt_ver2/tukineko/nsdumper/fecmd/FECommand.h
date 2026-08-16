#ifndef FECOMMAND_H
#define FECOMMAND_H

#include <QString>

class FECommand
{
public:
    FECommand();
    virtual ~FECommand();

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

#endif // FECOMMAND_H

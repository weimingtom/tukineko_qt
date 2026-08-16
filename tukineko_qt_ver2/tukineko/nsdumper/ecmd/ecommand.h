#ifndef ECOMMAND_H
#define ECOMMAND_H

#include <QString>

class ECommand
{
public:
    virtual ~ECommand() = default;

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

#endif // ECOMMAND_H

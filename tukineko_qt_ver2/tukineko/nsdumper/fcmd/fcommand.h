#ifndef FCOMMAND_H
#define FCOMMAND_H

#include <QString>

class FCommand
{
public:
    virtual ~FCommand() = default;

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

#endif // FCOMMAND_H

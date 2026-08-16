#ifndef SFCOMMAND_H
#define SFCOMMAND_H

#include <QString>

class SFCommand
{
public:
    SFCommand();
    virtual ~SFCommand();

    virtual bool check(const QString &str);
    virtual void execute();

protected:
    bool checkCommand(const QString &paramString1, const QString &paramString2);
    void debug(const QString &str);
};

#endif // SFCOMMAND_H

#ifndef SFCOMMAND_H
#define SFCOMMAND_H

#include <QString>

class SFCommand
{
public:
    SFCommand();
    virtual ~SFCommand();

    bool checkCommand(const QString& paramString1, const QString& paramString2);
    bool check(const QString& str);
    void execute();

protected:
    void debug(const QString& str);
};

#endif // SFCOMMAND_H

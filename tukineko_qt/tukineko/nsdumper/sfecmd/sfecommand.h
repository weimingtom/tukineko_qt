#ifndef SFECOMMAND_H
#define SFECOMMAND_H

#include <QString>

class SFECommand
{
public:
    SFECommand();
    virtual ~SFECommand();

    bool checkCommand(const QString& paramString1, const QString& paramString2);
    bool check(const QString& str);
    void execute();

protected:
    void debug(const QString& str);
};

#endif // SFECOMMAND_H

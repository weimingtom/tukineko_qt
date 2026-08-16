#ifndef SECOMMAND_H
#define SECOMMAND_H

#include <QString>

class SECommand
{
public:
    SECommand();
    virtual ~SECommand();

    bool checkCommand(const QString& paramString1, const QString& paramString2);
    bool check(const QString& str);
    void execute();

protected:
    void debug(const QString& str);
};

#endif // SECOMMAND_H


#ifndef FECOMMAND_H
#define FECOMMAND_H

#include <QString>

class FECommand
{
public:
    FECommand();
    virtual ~FECommand();

    bool checkCommand(const QString& paramString1, const QString& paramString2);
    bool check(const QString& str);
    void execute();

protected:
    void debug(const QString& str);
};

#endif // FECOMMAND_H

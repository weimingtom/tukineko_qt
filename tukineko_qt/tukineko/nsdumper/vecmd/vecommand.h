#ifndef VECOMMAND_H
#define VECOMMAND_H

#include <QString>

class VECommand
{
public:
    VECommand();
    virtual ~VECommand();

    bool checkCommand(const QString& paramString1, const QString& paramString2);
    bool check(const QString& str);
    void execute();

protected:
    void debug(const QString& str);
};

#endif // VECOMMAND_H

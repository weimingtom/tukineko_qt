#ifndef VFECOMMAND_H
#define VFECOMMAND_H

#include <QString>

class VFECommand
{
public:
    VFECommand();
    virtual ~VFECommand();

    bool checkCommand(const QString& paramString1, const QString& paramString2);
    bool check(const QString& str);
    void execute();

protected:
    void debug(const QString& str);
};

#endif // VFECOMMAND_H

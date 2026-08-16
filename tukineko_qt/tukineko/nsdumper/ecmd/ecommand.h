#ifndef ECOMMAND_H
#define ECOMMAND_H

#include <QString>

class ECommand
{
public:
    ECommand();
    virtual ~ECommand();
    virtual bool check(const QString& str);
    virtual void execute();

protected:
    QString m_cmdName;
};

#endif // ECOMMAND_H

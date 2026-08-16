#ifndef FCOMMAND_H
#define FCOMMAND_H

#include <QString>

class FCommand
{
public:
    FCommand();
    virtual ~FCommand();

    virtual bool check(const QString& str);
    virtual void execute();

protected:
    QString m_cmdName;
};

#endif // FCOMMAND_H

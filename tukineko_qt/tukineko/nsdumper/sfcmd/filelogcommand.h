#ifndef FILELOGCOMMAND_H
#define FILELOGCOMMAND_H

#include <QString>
#include "sfcommand.h"

class FilelogCommand : public SFCommand
{
public:
    FilelogCommand();
    virtual ~FilelogCommand();

    bool check(const QString& str);
    void execute();
};

#endif // FILELOGCOMMAND_H



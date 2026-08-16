#ifndef MP3LOOPCOMMAND_H
#define MP3LOOPCOMMAND_H

#include <QString>
#include "vecommand.h"

class Mp3loopCommand : public VECommand
{
public:
    Mp3loopCommand();
    virtual ~Mp3loopCommand();

    bool check(const QString& str);
    void execute();
};

#endif // MP3LOOPCOMMAND_H

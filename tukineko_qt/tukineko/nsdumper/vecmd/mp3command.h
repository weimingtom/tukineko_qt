#ifndef MP3COMMAND_H
#define MP3COMMAND_H

#include <QString>
#include "vecommand.h"

class Mp3Command : public VECommand
{
public:
    Mp3Command();
    virtual ~Mp3Command();

    bool check(const QString& str);
    void execute();
};

#endif // MP3COMMAND_H

#ifndef CAPTIONCOMMAND_H
#define CAPTIONCOMMAND_H

#include <QString>
#include "sfecommand.h"
#include "nscripter.h"

class CaptionCommand : public SFECommand
{
private:
    NScripter* ns;
public:
    CaptionCommand();
    virtual ~CaptionCommand();

    bool check(const QString& str);
    void execute();
};

#endif // CAPTIONCOMMAND_H

#ifndef CAPTIONCOMMAND_H
#define CAPTIONCOMMAND_H

#include "sfecommand.h"

class CaptionCommand : public SFECommand
{
public:
    CaptionCommand();

    bool check(const QString &str) override;
    void execute() override;
};

#endif // CAPTIONCOMMAND_H

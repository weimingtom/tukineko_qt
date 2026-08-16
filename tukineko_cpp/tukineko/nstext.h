#ifndef NSTEXT_H
#define NSTEXT_H

#include <QString>
#include "../java_awt/color_.h"

class NsText
{
public:
    NsText();
    
    QString text;
    int x, y;
    Color_* color;
    int fontSize;
    int align;  // 0=left, 1=center, 2=right
};

#endif // NSTEXT_H

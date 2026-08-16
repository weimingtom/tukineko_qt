#ifndef NSTEXT_H
#define NSTEXT_H

#include <QString>
#include "nscolor.h"

class NsText
{
public:
    NsText(int width, int height);
    virtual ~NsText();

    void cls();
    void clearY();
    int getY() const { return curY; }
    QString getMess(int k) const;
    NsColor* getColor(int k) const;
    bool getAttr(int k) const;
    void setAttr(int k, bool v);

    QString* mess;
    NsColor** color;
    bool* attr;
    int curX;
    int curY;
    int width;
    int height;
};

#endif // NSTEXT_H

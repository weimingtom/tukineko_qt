#ifndef NSTEXT_H
#define NSTEXT_H

#include <QString>
#include <QVector>
#include "NsColor.h"

class NsText
{
public:
    QVector<QString> mess;
    QVector<NsColor> color;
    QVector<bool> attr;
    int curX;
    int curY;
    int width;
    int height;

    NsText(int width, int height);

    void cls();
    void clearY();
    int getY() const;
    QString getMess(int k) const;
    NsColor getColor(int k) const;
    bool getAttr(int k) const;
    void setAttr(int k, bool v);
};

#endif // NSTEXT_H

#ifndef NSSHELL_H
#define NSSHELL_H

#include <QString>

class NsShell
{
public:
    QString image;
    int effect;
    int width;
    int height;

    NsShell();
    NsShell(const QString &image, int effect, int width, int height);
};

#endif // NSSHELL_H

#ifndef NSSHELL_H
#define NSSHELL_H

#include <QString>

class NsShell
{
public:
    NsShell(const QString& _image, int _effect, int _width, int _height);
    virtual ~NsShell();

    QString image;
    int effect;
    int width;
    int height;
};

#endif // NSSHELL_H

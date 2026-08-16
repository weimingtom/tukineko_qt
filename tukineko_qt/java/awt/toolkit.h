#ifndef TOOLKIT_H
#define TOOLKIT_H

#include <QString>
#include "image.h"
#include "component.h"

class Toolkit
{
public:
    static Toolkit* getDefaultToolkit();

    Image_* createImage(const QString& filename);
    Image_* createImage(const QByteArray& bytes);
    Image_* createImage(int w, int h, unsigned int* pixels, int offset, int scan);

private:
    Toolkit();
    static Toolkit* s_instance;
};

#endif // TOOLKIT_H

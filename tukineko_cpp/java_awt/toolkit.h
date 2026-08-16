#ifndef TOOLKIT_H
#define TOOLKIT_H

#include "image_.h"
#include <QString>

class Toolkit
{
public:
    static Toolkit* getDefaultToolkit();
    
    Image_* createImage(const QString& fileName);
    Image_* createImage(int width, int height);
    Dimension getScreenSize();
    
private:
    Toolkit();
    static Toolkit* s_instance;
};

#endif // TOOLKIT_H

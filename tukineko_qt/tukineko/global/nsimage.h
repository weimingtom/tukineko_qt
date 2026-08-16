#ifndef NSIMAGE_H
#define NSIMAGE_H

#include <QString>
#include "java/awt/image.h"

class NsImage
{
public:
    NsImage(const QString& name);
    virtual ~NsImage();

    QString name;
    Image_* image;

    void setImage(Image_* img);
    Image_* getImage() const;
    bool equals(const NsImage* other) const;

private:
    bool equals(const QString& otherName) const;
};

#endif // NSIMAGE_H

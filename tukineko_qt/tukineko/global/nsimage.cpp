#include "nsimage.h"

NsImage::NsImage(const QString& _name)
    : name(_name), image(nullptr)
{
}

NsImage::~NsImage()
{
}

void NsImage::setImage(Image_* img)
{
    image = img;
}

Image_* NsImage::getImage() const
{
    return image;
}

bool NsImage::equals(const NsImage* other) const
{
    return equals(other->name);
}

bool NsImage::equals(const QString& otherName) const
{
    return name == otherName;
}

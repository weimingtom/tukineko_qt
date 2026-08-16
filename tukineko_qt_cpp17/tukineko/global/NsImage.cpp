#include "NsImage.h"

namespace tukineko {

NsImage::NsImage(const QString &name)
    : name(name), image(nullptr)
{
}

void NsImage::setImage(QImage *image) {
    this->image = image;
}

QImage* NsImage::getImage() const {
    return this->image;
}

bool NsImage::operator==(const NsImage &other) const {
    return this->name == other.name;
}

bool NsImage::operator!=(const NsImage &other) const {
    return this->name != other.name;
}

}

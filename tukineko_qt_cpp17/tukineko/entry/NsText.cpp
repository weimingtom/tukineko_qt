#include "NsText.h"

NsText::NsText(int width, int height)
    : width(width)
    , height(height)
    , curX(0)
    , curY(0)
{
    mess.resize(height);
    color.resize(height);
    attr.resize(height);
    cls();
}

void NsText::cls()
{
    this->curX = 0;
    this->curY = 0;
    for (int i = 0; i < this->height; i++) {
        this->mess[i] = QString();
        this->color[i] = NsColor::white;
        this->attr[i] = false;
    }
}

void NsText::clearY()
{
}

int NsText::getY() const
{
    return this->curY;
}

QString NsText::getMess(int k) const
{
    if (k < this->height) {
        return this->mess[k];
    }
    return QString();
}

NsColor NsText::getColor(int k) const
{
    if (k < this->height) {
        return this->color[k];
    }
    return NsColor::white;
}

bool NsText::getAttr(int k) const
{
    if (k < this->height) {
        return this->attr[k];
    }
    return true;
}

void NsText::setAttr(int k, bool v)
{
    this->attr[k] = v;
}

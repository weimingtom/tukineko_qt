#include "nstext.h"

NsText::NsText(int w, int h)
    : curX(0), curY(0), width(w), height(h)
{
    mess = new QString[height];
    color = new NsColor*[height];
    attr = new bool[height];
    cls();
}

NsText::~NsText()
{
    delete[] mess;
    delete[] color;
    delete[] attr;
}

void NsText::cls()
{
    curX = 0;
    curY = 0;
    for (int i = 0; i < height; ++i) {
        mess[i] = "";
        color[i] = NsColor::white;
        attr[i] = false;
    }
}

void NsText::clearY()
{
    // Not implemented
}

QString NsText::getMess(int k) const
{
    if (k >= 0 && k < height) {
        return mess[k];
    }
    return QString();
}

NsColor* NsText::getColor(int k) const
{
    if (k >= 0 && k < height) {
        return color[k];
    }
    return NsColor::white;
}

bool NsText::getAttr(int k) const
{
    if (k >= 0 && k < height) {
        return attr[k];
    }
    return true;
}

void NsText::setAttr(int k, bool v)
{
    if (k >= 0 && k < height) {
        attr[k] = v;
    }
}

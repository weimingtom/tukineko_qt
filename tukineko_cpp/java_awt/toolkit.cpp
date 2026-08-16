#include "toolkit.h"
#include <QApplication>
#include <QScreen>

Toolkit* Toolkit::s_instance = nullptr;

Toolkit::Toolkit()
{
}

Toolkit* Toolkit::getDefaultToolkit()
{
    if (!s_instance) {
        s_instance = new Toolkit();
    }
    return s_instance;
}

Image_* Toolkit::createImage(const QString& fileName)
{
    return Image_::createImage(fileName);
}

Image_* Toolkit::createImage(int width, int height)
{
    return Image_::createImage(width, height);
}

Dimension Toolkit::getScreenSize()
{
    QScreen* screen = QApplication::primaryScreen();
    if (screen) {
        QSize size = screen->size();
        return Dimension(size.width(), size.height());
    }
    return Dimension(800, 600);
}

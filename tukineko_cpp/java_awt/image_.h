#ifndef IMAGE__H
#define IMAGE__H

#include <QImage>
#include <QPixmap>
#include <QString>

class Graphics_;

class Image_
{
public:
    Image_();
    Image_(int width, int height);
    Image_(const QString& filePath);
    Image_(const QImage& image);
    ~Image_();
    
    int getWidth() const;
    int getHeight() const;
    QImage* getImage() const;
    QPixmap* getPixmap() const;
    Graphics_* getGraphics();
    void flush();
    bool isNull() const;
    void setPixel(int x, int y, uint pixel);
    uint pixel(int x, int y) const;
    void fill(uint color);
    
    static Image_* createImage(const QString& filePath);
    static Image_* createImage(int width, int height);

private:
    QImage* m_image;
    QPixmap* m_pixmap;
    Graphics_* m_graphics;
};

#endif // IMAGE__H

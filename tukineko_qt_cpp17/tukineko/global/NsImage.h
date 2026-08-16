#ifndef NSIMAGE_H
#define NSIMAGE_H

#include <QString>
#include <QImage>

namespace tukineko {

class NsImage {
public:
    QString name;
    QImage *image;

    NsImage(const QString &name);

    void setImage(QImage *image);
    QImage* getImage() const;

    bool operator==(const NsImage &other) const;
    bool operator!=(const NsImage &other) const;
};

}

#endif // NSIMAGE_H

#ifndef MEDIATRACKER_H
#define MEDIATRACKER_H

//#include <QObject>
#include <QVector>
#include "component.h"
#include "image.h"

class MediaTracker //: public QObject
{
//    Q_OBJECT

public:
    explicit MediaTracker(Component* comp/*, QObject* parent = nullptr*/);
    virtual ~MediaTracker();

    void addImage(Image_* image, int id);
    void removeImage(Image_* image, int id);
    int waitForID(int id, bool waitForAll = true);
    void run();

//signals:
//    void statusChanged(int id);

private:
    Component* m_component;
    QVector<QPair<Image_*, int>> m_images;
};

#endif // MEDIATRACKER_H

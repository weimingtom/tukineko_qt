#include "mediatracker.h"
#include <QDebug>

MediaTracker::MediaTracker(Component* comp/*, QObject* parent*/)
    : //QObject(parent),
      m_component(comp)
{
}

MediaTracker::~MediaTracker()
{
}

void MediaTracker::addImage(Image_* image, int id)
{
    m_images.append(qMakePair(image, id));
}

void MediaTracker::removeImage(Image_* image, int id)
{
    Q_UNUSED(id);
    for (int i = 0; i < m_images.size(); ++i) {
        if (m_images[i].first == image) {
            m_images.removeAt(i);
            break;
        }
    }
}

int MediaTracker::waitForID(int id, bool waitForAll)
{
    Q_UNUSED(id);
    Q_UNUSED(waitForAll);
    // In Qt, images are loaded synchronously, so just return 0 (COMPLETE)
    return 0;
}

void MediaTracker::run()
{
    // Nothing to do - Qt handles this synchronously
}

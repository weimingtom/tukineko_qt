#include "MediaTracker.h"

namespace java {
namespace awt {

MediaTracker::MediaTracker()
{
}

MediaTracker::MediaTracker(Component* c)
{
    Q_UNUSED(c)
}

void MediaTracker::addImage(Image_* img, int id)
{
    Q_UNUSED(img)
    Q_UNUSED(id)
}

void MediaTracker::waitForID(int id)
{
    Q_UNUSED(id)
}

void MediaTracker::removeImage(Image_* img, int id)
{
    Q_UNUSED(img)
    Q_UNUSED(id)
}

} // namespace awt
} // namespace java

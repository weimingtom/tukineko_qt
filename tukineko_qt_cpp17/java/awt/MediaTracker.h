#ifndef JAVA_AWT_MEDIATRACKER_H
#define JAVA_AWT_MEDIATRACKER_H

#include "Image_.h"
#include "Component.h"

namespace java {
namespace awt {

class MediaTracker {
public:
    MediaTracker();
    explicit MediaTracker(Component* c);

    void addImage(Image_* img, int id);
    void waitForID(int id);
    void removeImage(Image_* img, int id);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_MEDIATRACKER_H

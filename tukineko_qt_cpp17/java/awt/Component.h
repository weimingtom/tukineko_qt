#ifndef JAVA_AWT_COMPONENT_H
#define JAVA_AWT_COMPONENT_H

#include <QObject>

namespace java {
namespace awt {

class Component : public QObject {
    Q_OBJECT
public:
    explicit Component(QObject* parent = nullptr);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_COMPONENT_H

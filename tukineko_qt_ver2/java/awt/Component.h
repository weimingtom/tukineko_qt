#ifndef JAVA_AWT_COMPONENT_H
#define JAVA_AWT_COMPONENT_H

#include <QWidget>
#include <QObject>

namespace java {
namespace awt {

class Component : public QWidget {
    Q_OBJECT
public:
    explicit Component(QWidget* parent = nullptr);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_COMPONENT_H

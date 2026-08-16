#ifndef JAVA_LANG_RUNTIME_H
#define JAVA_LANG_RUNTIME_H

#include <QtGlobal>

namespace java {
namespace lang {

class Runtime {
private:
    Runtime();

    static Runtime* m_instance;

public:
    static Runtime* getRuntime();

    qint64 freeMemory();
    qint64 totalMemory();
    void runFinalization();
    void gc();
};

} // namespace lang
} // namespace java

#endif // JAVA_LANG_RUNTIME_H

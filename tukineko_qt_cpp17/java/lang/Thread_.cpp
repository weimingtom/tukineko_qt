#include "Thread_.h"

namespace java {
namespace lang {

Thread_::Thread_()
    : m_name(QString())
{
}

Thread_::Thread_(const QString& name)
    : m_name(name)
{
    setObjectName(name);
}

Thread_::~Thread_()
{
    quit();
    wait();
}

void Thread_::start()
{
    QThread::start();
}

void Thread_::run()
{
    // Override in subclasses
}

void Thread_::join()
{
    wait();
}

} // namespace lang
} // namespace java

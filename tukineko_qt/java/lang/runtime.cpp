#include "runtime.h"
#include <QDebug>

Runtime::Runtime(/*QObject* parent*/)
    //: QObject(parent)
{
}

Runtime* Runtime::s_instance = nullptr;

Runtime* Runtime::getRuntime()
{
    if (!s_instance) {
        s_instance = new Runtime();
    }
    return s_instance;
}

void Runtime::gc()
{
    qDebug() << "gc() called";
//    emit gcEvent();
}

void Runtime::runFinalization()
{
    qDebug() << "runFinalization() called";
}

long Runtime::freeMemory()
{
    // Simplified - in real implementation would track memory
    return 1024 * 1024 * 100; // 100MB
}

long Runtime::totalMemory()
{
    return 1024 * 1024 * 256; // 256MB
}

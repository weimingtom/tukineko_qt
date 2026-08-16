#include "runtime.h"
#include <QCoreApplication>

Runtime* Runtime::s_instance = nullptr;

Runtime::Runtime()
{
}

Runtime* Runtime::getRuntime()
{
    if (!s_instance) {
        s_instance = new Runtime();
    }
    return s_instance;
}

void Runtime::gc()
{
    // QML/C++ automatic garbage collection handles this
}

void Runtime::exit(int status)
{
    QCoreApplication::exit(status);
}

long Runtime::maxMemory()
{
    return 128 * 1024 * 1024; // 128MB
}

long Runtime::totalMemory()
{
    return 64 * 1024 * 1024; // 64MB
}

long Runtime::freeMemory()
{
    return 32 * 1024 * 1024; // 32MB
}

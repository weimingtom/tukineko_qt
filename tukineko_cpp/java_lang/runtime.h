#ifndef RUNTIME_H
#define RUNTIME_H

#include <QString>

class Runtime
{
public:
    static Runtime* getRuntime();
    
    void gc();
    void exit(int status);
    long maxMemory();
    long totalMemory();
    long freeMemory();

private:
    Runtime();
    static Runtime* s_instance;
};

#endif // RUNTIME_H

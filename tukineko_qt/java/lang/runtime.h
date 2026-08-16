#ifndef RUNTIME_H
#define RUNTIME_H

#include <QObject>

class Runtime //: public QObject
{
//    Q_OBJECT

public:
    static Runtime* getRuntime();

    void gc();
    void runFinalization();
    long freeMemory();
    long totalMemory();

private:
    //Runtime();
    Runtime(/*QObject *parent = nullptr*/);

//signals:
//    void gcEvent();

private:
    static Runtime* s_instance;
};

#endif // RUNTIME_H

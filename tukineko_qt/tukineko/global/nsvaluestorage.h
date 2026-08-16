#ifndef NSVALUESTORAGE_H
#define NSVALUESTORAGE_H

#include "java/io/inputstream.h"
#include "java/io/outputstream.h"

class NsValueStorage
{
public:
    static void load(InputStream* is, int* values, QString* strings, int start, int end);
    static void save(OutputStream* os, int* values, QString* strings, int start, int end);
};

#endif // NSVALUESTORAGE_H

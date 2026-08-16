#ifndef NSVALUESTORAGE_H
#define NSVALUESTORAGE_H

#include <QDataStream>
#include <QString>
#include <QVector>

namespace tukineko {

class NsValueStorage {
public:
    static void save(QDataStream &out, const QVector<int> &paramArrayOfInt,
                     const QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2);
    static void load(QDataStream &in, QVector<int> &paramArrayOfInt,
                     QVector<QString> &paramArrayOfString, int paramInt1, int paramInt2);
};

}

#endif // NSVALUESTORAGE_H

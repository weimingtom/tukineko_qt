#include "nsdata.h"
#include "../java_io/file_.h"
#include <QDebug>

NsData::NsData()
    : currentBG(nullptr)
    , currentFG(nullptr)
    , twinLx(0), twinLy(400), twinRx(640), twinRy(80)
    , twinCol(new Color_(255, 255, 255))
    , twinFontSize(20)
    , scriptPos(0)
    , textOn(true)
    , clickWait(false)
    , skipMode(false)
    , autoMode(false)
{
}

NsData::~NsData()
{
    qDeleteAll(sprites);
    qDeleteAll(buttons);
    qDeleteAll(textLines);
    
    if (currentBG) delete currentBG;
    if (currentFG) delete currentFG;
    if (twinCol) delete twinCol;
}

int NsData::getVariable(const QString& name)
{
    return valueNum.value(name, 0);
}

void NsData::setVariable(const QString& name, int value)
{
    valueNum[name] = value;
}

QString NsData::getString(const QString& name)
{
    return valueStr.value(name, QString());
}

void NsData::setString(const QString& name, const QString& value)
{
    valueStr[name] = value;
}

void NsData::saveToFile(const QString& filename)
{
    // Save game state to file
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        
        // Save variables
        out << valueNum.size();
        for (auto it = valueNum.begin(); it != valueNum.end(); ++it) {
            out << it.key() << it.value();
        }
        
        out << valueStr.size();
        for (auto it = valueStr.begin(); it != valueStr.end(); ++it) {
            out << it.key() << it.value();
        }
        
        // Save script position
        out << scriptPos;
        
        file.close();
        qDebug() << "Game saved to" << filename;
    }
}

void NsData::loadFromFile(const QString& filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        
        // Load variables
        int numCount;
        in >> numCount;
        for (int i = 0; i < numCount; ++i) {
            QString key;
            int value;
            in >> key >> value;
            valueNum[key] = value;
        }
        
        int strCount;
        in >> strCount;
        for (int i = 0; i < strCount; ++i) {
            QString key;
            QString value;
            in >> key >> value;
            valueStr[key] = value;
        }
        
        // Load script position
        in >> scriptPos;
        
        file.close();
        qDebug() << "Game loaded from" << filename;
    }
}

#ifndef NSDATA_H
#define NSDATA_H

#include <QString>
#include <QMap>
#include <QVector>
#include "nstext.h"
#include "nsbutton.h"
#include "nssprite.h"
#include "../java_awt/image_.h"
#include "../java_awt/color_.h"

class NsData
{
public:
    NsData();
    ~NsData();
    
    // Variables
    QMap<QString, int> valueNum;
    QMap<QString, QString> valueStr;
    
    // Labels
    QMap<QString, int> labels;  // label name -> script position
    
    // Display state
    Image_* currentBG;
    Image_* currentFG;
    QVector<NsSprite*> sprites;
    QVector<NsButton*> buttons;
    QVector<NsText*> textLines;
    
    // Text window state
    int twinLx, twinLy, twinRx, twinRy;
    Color_* twinCol;
    int twinFontSize;
    
    // Script position
    int scriptPos;
    QString currentScript;
    
    // Flags
    bool textOn;
    bool clickWait;
    bool skipMode;
    bool autoMode;
    
    // Save data
    void saveToFile(const QString& filename);
    void loadFromFile(const QString& filename);
    
    // Variable operations
    int getVariable(const QString& name);
    void setVariable(const QString& name, int value);
    QString getString(const QString& name);
    void setString(const QString& name, const QString& value);
};

#endif // NSDATA_H

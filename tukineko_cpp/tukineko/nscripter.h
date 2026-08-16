#ifndef NSCRIPTER_H
#define NSCRIPTER_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <QVector>

class NsData;
class NsResource;

class NScripter
{
public:
    NScripter(NsData* data, NsResource* resource);
    ~NScripter();
    
    void init(const QStringList& argv);
    void loadScript(const QString& filename);
    void execute();
    void processCommand(const QString& cmd, const QStringList& args);
    
    // Goto and gosub
    void gotoLabel(const QString& label);
    void gosubLabel(const QString& label);
    void return_();
    
    // Variable operations
    int getVariable(const QString& name);
    void setVariable(const QString& name, int value);
    void addVariable(const QString& name, int value);
    
    // Script control
    void setCurrentScript(const QString& script);
    int getScriptPosition();
    void setScriptPosition(int pos);
    bool hasLabel(const QString& label);

private:
    NsData* m_data;
    NsResource* m_resource;
    QStringList m_scriptLines;
    QStringList m_labels;
    QMap<QString, int> m_labelMap;
    QVector<QStringList> m_gosubStack;
    
    int m_pc;  // Program counter
    bool m_running;
    
    void parseLabels();
    void executeLine(const QString& line);
};

#endif // NSCRIPTER_H

#ifndef QTPROCESS_PLUGIN_H
#define QTPROCESS_PLUGIN_H

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class QtProcessPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
    
public:
    void registerTypes(const char *uri);
};

#endif // QTPROCESS_PLUGIN_H


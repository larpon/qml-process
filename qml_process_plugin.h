#ifndef QML_PROCESS_PLUGIN_H
#define QML_PROCESS_PLUGIN_H

#ifdef QT5_BUILD

#include <QtQml/QQmlExtensionPlugin>

class QmlProcessPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

#else // QT4

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class QmlProcessPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

#endif

public:
    void registerTypes(const char *uri);
};

#endif // QML_PROCESS_PLUGIN_H

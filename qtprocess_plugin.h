#ifndef QTPROCESS_PLUGIN_H
#define QTPROCESS_PLUGIN_H

#ifdef QT5_BUILD

#include <QtQml/QQmlExtensionPlugin>

class QtProcessPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

#else // QT4

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class QtProcessPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

#endif

public:
    void registerTypes(const char *uri);
};

#endif // QTPROCESS_PLUGIN_H


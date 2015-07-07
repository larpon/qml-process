#include "qml_process_plugin.h"
#include "qml_process.h"

#ifdef QT5_BUILD
#include <QtQml/qqml.h>
#else
#include <QtDeclarative/qdeclarative.h>
QML_DECLARE_TYPE(QmlProcess)
#endif

void QmlProcessPlugin::registerTypes(const char *uri)
{
    // @uri QtProcess
    qmlRegisterType<QmlProcess>(uri, 0, 1, "Process");
}

#ifndef QT5_BUILD
Q_EXPORT_PLUGIN2(QmlProcess, QmlProcessPlugin)
#endif


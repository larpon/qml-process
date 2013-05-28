#include "qtprocess_plugin.h"
#include "process.h"

#ifdef QT5_BUILD
#include <QtQml/qqml.h>
#else
#include <QtDeclarative/qdeclarative.h>
QML_DECLARE_TYPE(Process)
#endif

void QtProcessPlugin::registerTypes(const char *uri)
{
    // @uri QtProcess
    qmlRegisterType<Process>(uri, 0, 1, "Process");
}

#ifndef QT5_BUILD
Q_EXPORT_PLUGIN2(QtProcess, QtProcessPlugin)
#endif


#include "qtprocess_plugin.h"
#include "process.h"

#include <QtDeclarative/qdeclarative.h>

QML_DECLARE_TYPE(Process)

void QtProcessPlugin::registerTypes(const char *uri)
{
    // @uri QtProcess
    qmlRegisterType<Process>(uri, 0, 1, "Process");
}

Q_EXPORT_PLUGIN2(QtProcess, QtProcessPlugin)


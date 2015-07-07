#include "qml_process.h"

#include <QtCore/QProcess>

class QmlProcess::Private : public QProcess
{
    Q_OBJECT
public:
    Private(QmlProcess *parent);

    QString shell;
    QString command;
    //QString program;
    //QStringList arguments;
private:
    QmlProcess *q;
};

QmlProcess::Private::Private(QmlProcess *parent)
    : QProcess(parent)
    , q(parent)
{
    connect(this, SIGNAL(started()), q, SIGNAL(started()));
    connect(this, SIGNAL(finished(int,QProcess::ExitStatus)), q, SIGNAL(finished(int)));
    connect(this, SIGNAL(readyReadStandardOutput()), q, SIGNAL(readyReadStandardOutput()));
    connect(this, SIGNAL(readyReadStandardError()), q, SIGNAL(readyReadStandardError()));
}

QmlProcess::QmlProcess(QObject *parent)
    : QObject(parent)
    , d(new Private(this))
{
   d->shell = "bash";
}

QmlProcess::~QmlProcess()
{
}
/*
const QString &QmlProcess::program() const
{
    return d->program;
}

void QmlProcess::setProgram(const QString &program)
{
    if (program == d->program) return;
    d->program = program;
    emit programChanged(d->program);
}

const QStringList &QmlProcess::arguments() const
{
    return d->arguments;
}

void QmlProcess::setArguments(const QStringList &arguments)
{
    if (arguments == d->arguments) return;
    d->arguments = arguments;
    emit argumentsChanged(d->arguments);
}
*/

const QString &QmlProcess::shell() const
{
    return d->shell;
}

void QmlProcess::setShell(const QString &shell)
{
    if (shell == d->shell) return;
    d->shell = shell;
    emit shellChanged(d->shell);
}

const QString &QmlProcess::command() const
{
    return d->command;
}

void QmlProcess::setCommand(const QString &command)
{
    if (command == d->command) return;
    d->command = command;
    emit commandChanged(d->command);
}

void QmlProcess::start()
{
    d->start(d->shell);
    
    d->write(d->command.toUtf8().constData());
    d->closeWriteChannel();

    //d->waitForStarted();
    //d->waitForFinished();
    
    /*
    sh.waitForFinished();
    QByteArray output = sh.readAll();
    sh.close();
    d->start(d->program, d->arguments);
    */
}

void QmlProcess::terminate()
{
    d->terminate();
}

void QmlProcess::kill()
{
    d->kill();
}

QByteArray QmlProcess::readAllStandardError()
{
    return d->readAllStandardError();
}

QByteArray QmlProcess::readAllStandardOutput()
{
    return d->readAllStandardOutput();
}

#include "qml_process.moc"

#include "process.h"

#include <QtCore/QProcess>

class Process::Private : public QProcess
{
    Q_OBJECT
public:
    Private(Process *parent);

    QString shell;
    QString command;
    //QString program;
    //QStringList arguments;
private:
    Process *q;
};

Process::Private::Private(Process *parent)
    : QProcess(parent)
    , q(parent)
{
    connect(this, SIGNAL(started()), q, SIGNAL(started()));
    connect(this, SIGNAL(finished(int,QProcess::ExitStatus)), q, SIGNAL(finished(int)));
    connect(this, SIGNAL(readyReadStandardOutput()), q, SIGNAL(readyReadStandardOutput()));
    connect(this, SIGNAL(readyReadStandardError()), q, SIGNAL(readyReadStandardError()));
}

Process::Process(QObject *parent)
    : QObject(parent)
    , d(new Private(this))
{
   d->shell = "bash";
}

Process::~Process()
{
}
/*
const QString &Process::program() const
{
    return d->program;
}

void Process::setProgram(const QString &program)
{
    if (program == d->program) return;
    d->program = program;
    emit programChanged(d->program);
}

const QStringList &Process::arguments() const
{
    return d->arguments;
}

void Process::setArguments(const QStringList &arguments)
{
    if (arguments == d->arguments) return;
    d->arguments = arguments;
    emit argumentsChanged(d->arguments);
}
*/

const QString &Process::shell() const
{
    return d->shell;
}

void Process::setShell(const QString &shell)
{
    if (shell == d->shell) return;
    d->shell = shell;
    emit shellChanged(d->shell);
}

const QString &Process::command() const
{
    return d->command;
}

void Process::setCommand(const QString &command)
{
    if (command == d->command) return;
    d->command = command;
    emit commandChanged(d->command);
}

void Process::start()
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

void Process::terminate()
{
    d->terminate();
}

void Process::kill()
{
    d->kill();
}

QByteArray Process::readAllStandardError()
{
    return d->readAllStandardError();
}

QByteArray Process::readAllStandardOutput()
{
    return d->readAllStandardOutput();
}

#include "process.moc"

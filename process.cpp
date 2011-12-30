#include "process.h"

#include <QtCore/QProcess>

class Process::Private : public QProcess
{
    Q_OBJECT
public:
    Private(Process *parent);

    QString program;
    QStringList arguments;
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
}

Process::~Process()
{
}

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

void Process::start()
{
    d->start(d->program, d->arguments);
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

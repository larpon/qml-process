#ifndef PROCESS_H
#define PROCESS_H

#include <QtCore/QObject>
#include <QtCore/QStringList>

class Process : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Process)
    //Q_PROPERTY(QString program READ program WRITE setProgram NOTIFY programChanged)
    //Q_PROPERTY(QStringList arguments READ arguments WRITE setArguments NOTIFY argumentsChanged)
    Q_PROPERTY(QString shell READ shell WRITE setShell NOTIFY shellChanged)
    Q_PROPERTY(QString command READ command WRITE setCommand NOTIFY commandChanged)
public:
    Process(QObject *parent = 0);
    ~Process();
/*
    const QString &program() const;
    const QStringList &arguments() const;
*/
    const QString &shell() const;
    const QString &command() const;
    
    Q_INVOKABLE QByteArray readAllStandardError();
    Q_INVOKABLE QByteArray readAllStandardOutput();

public slots:
    //void setProgram(const QString &program);
    //void setArguments(const QStringList &arguments);
    void setShell(const QString &shell);
    void setCommand(const QString &command);
    
    void start();
    void terminate();
    void kill();

signals:
    //void programChanged(const QString &program);
    //void argumentsChanged(const QStringList &arguments);
    void shellChanged(const QString &shell);
    void commandChanged(const QString &command);

//    void error(QProcess::ProcessError error )
    void finished(int exitCode);
    void readyReadStandardError();
    void readyReadStandardOutput();
    void started();
//    void stateChanged(QProcess::ProcessState newState);

private:
    class Private;
    Private *d;
};

#endif // PROCESS_H


#ifndef SERVERSREACH_H
#define SERVERSREACH_H

#include <QObject>

class ServerSreach : public QObject
{
    Q_OBJECT
public:
    explicit ServerSreach(QObject *parent = nullptr);
    void ServerIPSreach(QString);
    void PrintfServer(QString);
signals:
    void SerachOver();
    void SreachIPArdress(QString);
};

#endif // SERVERSREACH_H

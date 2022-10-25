#ifndef ANALYSIS_DOOR_H
#define ANALYSIS_DOOR_H

#include <QObject>
#include <QTimer>
#include <QMultiMap>
#include <QDebug>

class Analysis_Door : public QObject
{
    Q_OBJECT
public:
    explicit Analysis_Door(QObject *parent = nullptr);
    ~Analysis_Door();
public slots:
    void Receive_Data(QMultiMap<int,QString> Data);
signals:

};

#endif // ANALYSIS_DOOR_H

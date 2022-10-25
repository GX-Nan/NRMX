#ifndef ANALYSIS_LIGHT_H
#define ANALYSIS_LIGHT_H

#include <QObject>
#include <QTimer>
#include <QMultiMap>
#include <QDebug>

class Analysis_Light : public QObject
{
    Q_OBJECT
public:
    explicit Analysis_Light(QObject *parent = nullptr);
    ~Analysis_Light();
public slots:
    void Receive_Data(QMultiMap<int,QString> Data);
    void Handle_Data(QString Data);
signals:
    void StatusSignals(int Function,int Sub,int Value);
};

#endif // ANALYSIS_LIGHT_H

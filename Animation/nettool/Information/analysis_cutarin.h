#ifndef ANALYSIS_CUTARIN_H
#define ANALYSIS_CUTARIN_H

#include <QObject>
#include <QTimer>
#include <QMultiMap>
#include <QDebug>

class Analysis_Cutarin : public QObject
{
    Q_OBJECT
public:
    explicit Analysis_Cutarin(QObject *parent = nullptr);
    ~Analysis_Cutarin();

public slots:
    void Receive_Data(QMultiMap<int,QString> Data);
    void Handle_Data(QString Data);
    void Handle_Data_Esp(QString Data);
signals:
    void StatusSignals(int,int);
    void BrightnessSignals(QString);
};

#endif // ANALYSIS_CUTARIN_H

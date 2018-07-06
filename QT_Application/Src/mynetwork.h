#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>
#include <QUdpSocket>

#define enable_debug_udp true

class MyNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MyNetwork(QObject *parent = nullptr);

signals:

public slots:
    void sendUDP(QString msg);
    void setDigit(int index, int value) ;
private slots:
    void readyReadUDP();

private:
    int udpPort = 7456 ;
    QUdpSocket *m_udpSocket = nullptr;
    QString currentValue = "0000";

};

#endif // MYNETWORK_H

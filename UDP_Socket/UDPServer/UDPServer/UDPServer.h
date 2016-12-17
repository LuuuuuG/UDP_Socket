#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QtWidgets/QWidget>
#include <QtNetwork/QUdpSocket>  

class UDPServer :public QObject
{
	Q_OBJECT
public:
	UDPServer(QObject *parent = NULL);
	~UDPServer();

	private slots:
	void readPendingDatagrams();
private:
	QUdpSocket *udpSocket;

};

#endif // UDPSERVER_H

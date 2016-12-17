#include "UDPServer.h"

UDPServer::UDPServer(QObject *parent ) :QObject(parent)
{
	udpSocket = new QUdpSocket(this);
	udpSocket->bind(QHostAddress::LocalHost, 7755);
	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

UDPServer::~UDPServer()
{

}

void UDPServer::readPendingDatagrams()
{
	QHostAddress sender;
	quint16 senderPort;
	while (udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

	}
	QString text = "hello ...";
	QByteArray datagram = text.toLocal8Bit();
	udpSocket->writeDatagram(datagram.data(), datagram.size(), sender, senderPort);
}

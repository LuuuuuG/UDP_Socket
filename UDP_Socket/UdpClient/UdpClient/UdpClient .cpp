#include "UdpClient .h"

UdpClient::UdpClient(QWidget *parent)
: QWidget(parent)
{
	m_pLEdit = new QLineEdit(this);
	m_pSendMesBtn = new QPushButton(tr("Sending"), this);
	udpSocket = new QUdpSocket(this);
	m_pMessage = new QLabel(this);
	QHostAddress sender = udpSocket->localAddress();
	quint16 senderPort = udpSocket->localPort();
	udpSocket->bind(sender, senderPort);
	m_pLEdit->setGeometry(5, 5, 100, 20);
	m_pSendMesBtn->setGeometry(110, 5, 50, 20);
	m_pMessage->setGeometry(5, 30, 150, 20);
	m_pLEdit->setStyleSheet("QLineEdit{color:red}");
	connect(m_pSendMesBtn, SIGNAL(clicked()), this, SLOT(sendMessageSlot()));
	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));

}

UdpClient::~UdpClient()
{

}

void UdpClient::sendMessageSlot()
{
	QString text = m_pLEdit->text();
	QByteArray datagram = text.toLocal8Bit();
	udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::LocalHost, 7755);
}

void UdpClient::readPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		QHostAddress sender;
		quint16 senderPort;
		udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
		QString text = QString(datagram);
		m_pMessage->setText(text);
	}
}
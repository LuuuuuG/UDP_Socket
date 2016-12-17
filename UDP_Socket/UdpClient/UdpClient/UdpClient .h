#ifndef UDPCLIENT__H
#define UDPCLIENT__H

#include <QtWidgets/QWidget>
#include <QtNetwork/QUdpSocket>  
#include <QPushButton>
#include <qlabel.h>
#include <QLineEdit>

class UdpClient : public QWidget
{
	Q_OBJECT

public:
	UdpClient(QWidget *parent = 0);
	~UdpClient();

	private slots:
	void sendMessageSlot();
	void readPendingDatagrams();
private:
	QUdpSocket     *udpSocket;
	QLineEdit      *m_pLEdit;
	QPushButton    *m_pSendMesBtn;
	QLabel         *m_pMessage;
	//Ui::UdpClientClass ui;  
};

#endif // UDPCLIENT__H

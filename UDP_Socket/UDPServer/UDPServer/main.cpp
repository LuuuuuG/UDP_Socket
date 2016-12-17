#include "UDPServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UDPServer w;

	return a.exec();
}

#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(8000);

    connect(socket, SIGNAL(readyRead()), this, SLOT(SocketReadReady()));
}

void MyWidget::SocketReadReady()
{
    char buf[1024];
    socket->readDatagram(buf, sizeof(buf));
    qDebug() << buf;


}

#include "mywidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
//#include <QtGui>
#include <QApplication>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 8900);

    connect(server, SIGNAL(newConnection()), this, SLOT(slotConnect()));

    edit1 = new QTextEdit();
    edit2 = new QTextEdit();
    button = new QPushButton("Send");

    quit = new  QPushButton("Quit");
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    #if 1
    QVBoxLayout* rightLayout = new QVBoxLayout();
    rightLayout->addWidget(button);
    rightLayout->addWidget(quit);

    QHBoxLayout* downLayout = new QHBoxLayout();
    downLayout->addWidget(edit1, 10);
    downLayout->addLayout(rightLayout);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(edit2, 1);
    layout->addLayout(downLayout);
    #endif

    #if 0
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(edit2, 10);
    layout->addWidget(edit1, 1);
    layout->addWidget(button);
    layout->addWidget(quit);
    #endif

    setLayout(layout);
    setWindowTitle(tr("Dialog"));
    //setFixedHeight(sizeHint().height());

    connect(button, SIGNAL(clicked()), this, SLOT(slotSendMessage()));

}

void MyWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(Qt::Key_Return == event->key())
    //if(event->key() == Qt::Key_Return)
    {
        QString str = edit1->toPlainText();
        str = str.left(str.length()-1);
        if (str.length() == 0) 
        {
            edit2->append("\nCannot send blank message !\n");
            qDebug() << "\nCannot send blank message !\n";
            edit1->clear();
            return ;
        }
        // textEdit->setHtml("<font color='red'>hello,wo</font><font
        // color='blue'>rld!</color>");
        //
        // edit2->append("\nNavy say:\n");
        str = "<font color='red'>" + str + "</font>";
        edit2->append(str);
        qDebug() << "\nNavy say:\n";
        qDebug() << str;
        edit1->clear();
        socket->write(str.toAscii());
    }
}

void MyWidget::slotSendMessage()
{
    QString str = edit1->toPlainText();
    if (str.length() == 0) 
    {
        edit2->append("\nCannot send blank message !\n");
        qDebug() << "\nCannot send blank message !\n";
        return ;
    }
    edit2->append("\nNavy say:\n");
    edit2->append(str);
    qDebug() << "\nNavy say:\n";
    qDebug() << str;
    edit1->clear();
    socket->write(str.toAscii());
}

void MyWidget::slotConnect()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadReady()));

    qDebug() << "Client connected";
}

void MyWidget::slotReadReady()
{
    QByteArray str = socket->read(1024);
    qDebug() << str;
    edit2->append("\nPeer say:\n");
    edit2->append(str);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget win;
    win.show();

    return app.exec();
}

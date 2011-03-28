#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QPushButton>
#include <QTextEdit>
#include <QKeyEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    QTcpServer* server;
    QTcpSocket* socket;

    QPushButton* button;
    QPushButton* quit;
    QTextEdit* edit1;
    QTextEdit* edit2;
    void keyReleaseEvent(QKeyEvent *);

signals:

public slots:
    void slotConnect();
    void slotReadReady();

    void slotSendMessage();

};

#endif // MYWIDGET_H

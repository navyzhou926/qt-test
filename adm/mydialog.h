#ifndef MYDIALOG_H
#define MYDIALOG_H
#include "ui_mydialog.h"
#include <QDialog>
#include <QLabel>
#include <QLCDNumber>
#include <QString>
//#include <QTcpSocket>
#include <QTextBrowser>
#include <QTime>

#if 0
QT_BEGIN_NAMESPACE

//class QTcpServer;
class QTcpSocket;
QT_END_NAMESPACE
#endif

// int paint_pos;
enum direction{LTR, RTL};

class MyDialog:public QDialog, public Ui_Form 
{
    Q_OBJECT
    public:
        explicit MyDialog(QWidget *parent = 0);
        void setDirection(direction d){dirvalue = d;}
        direction getDiretion(){return dirvalue;}
        void changeRate(int value);
        void changeContent(const QString &str){contentstr = str;}
        void draw(QPainter *painter);
        void sendMsgTime(); 
    private slots:
        void enter();
        void showTime();
        void timeoutslot();
        void showPicture();
        void sendMsg();
        void recvMsg();
        void error();
    private:
        void resizeEvent(QResizeEvent *event);
        QString buf;
        void paintEvent(QPaintEvent *event);
        int juge;
        QString contentstr;
        QString anotherstr;
        QLabel *background;
        QLabel *imageLabel;
        QLCDNumber *lcd;
        QLCDNumber *ymdlcd;
        QString *picPath[50];
        direction dirvalue;
        QString msgBuffer;
        //QTcpSocket *tcpSocket;
        QTextBrowser *txtB;
        QTime time;
};


#endif


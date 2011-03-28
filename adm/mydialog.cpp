#include <QtGui>
#include <iostream>
#include <fstream>
#include <QImage>
#include <QPixmap>
#include <QWidget>
#include <QMovie>
//#include <QHostAddress>
#include <QMessageBox>
#include <QByteArray>
#include <QDate>
#include <stdlib.h>
#include "mydialog.h"

#define SER_IP "10.1.14.30"

using namespace std;

int paint_pos;
int paint_txt_len;
int pic_no = 0;
int pic_num = 0;

MyDialog::MyDialog(QWidget *parent)
{
    parent = NULL;
    setupUi(this);
    cout << "MyDialog constor" << endl;
    Qt::WindowFlags flags = 0;
    flags |= Qt::FramelessWindowHint;

    QPalette plt = palette();
    plt.setColor(QPalette::Background, QColor(0, 0, 0, 255));
    setPalette(plt);
    //showFullScreen();
    //setSegmentStyle(Filled);
    //setGeometry(0, 0, 720, 576);
    setGeometry(0, 0, 800, 480);

    /*显示背景图片
    background = new QLabel(this);
    //background->setGeometry(QRect(565, 0, 140, 480));
    background->setGeometry(QRect(0, 0, 512, 512));
    QPixmap pix("logo/ground.png");
    background->setPixmap(pix);
    */

//LOG
    QMovie *movie = new QMovie("logo/love.gif");
    movie->setCacheMode(QMovie::CacheAll);
    movie->setSpeed(100);
    movie->start();

    QLabel *movieLabel = new QLabel(this);
    /*
    movieLabel->setAlignment(Qt::AlignCenter);
    movieLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    movieLabel->setAutoFillBackground(true);
    */
    //movieLabel->setGeometry(QRect(565, 0, 140, 100));
    movieLabel->setGeometry(QRect(560, 90, 800, 350));
    //movieLabel->setColor(QPalette::Normal, QPalette::Background, Qt::white);
    movieLabel->setMovie(movie);

/*
    background = new QLabel(this);
    background->setGeometry(QRect(565, 0, 140, 480);)
    background->setColor(QPalette::Normal, QPalette::Background, Qt::white);
    */

    //CLOCK
    ymdlcd = new QLCDNumber(10, this);
    ymdlcd->setSegmentStyle(QLCDNumber::Filled);
    //ymdlcd->setGeometry(QRect(100, 100, 200, 180));
    ymdlcd->setGeometry(QRect(425, 3, 505, 43));
    ymdlcd->setFrameShape(QFrame::NoFrame);
    QPalette plt2 = ymdlcd->palette();
    plt2.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);
    ymdlcd->setPalette(plt2);

    lcd = new QLCDNumber(5, this);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    //lcd->setGeometry(QRect(165, 130, 140, 50));
    lcd->setGeometry(QRect(445, 47, 475, 57));
    //lcd->setForegroundRole(QPalette::Window);
    //lcd->setBackgroundRole(QPalette::Dark);
    lcd->setFrameShape(QFrame::NoFrame);
    //lcd->setStyle();
    QPalette plt1 = lcd->palette();
    //plt1.setColor(QPalette::Background, QColor(Qt::blue));
    //plt1.setColor(QPalette::Normal, QPalette::Background, Qt::white);
    plt1.setColor(QPalette::Normal, QPalette::WindowText, Qt::black);
    lcd->setPalette(plt1);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    //connect(timer, SIGNAL(timeout()), this, SLOT(enter()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslot()));
    //connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));
    //contentstr = QString::fromLocal8Bit("你好 !!!");
    #if 1
    char str[1024];
    memset(str, 0, 1024);
    ifstream infile("txts/data.txt");
    for (int i = 0; i < 1024; i++) 
    {
        if (infile) 
        {
            infile.get(str[i]);
        }
        else
            break;
    }
    contentstr = QString::fromLocal8Bit(str);
    paint_txt_len = contentstr.length() *(fontMetrics().maxWidth());
    cout << "len:" << paint_txt_len << endl;
    dirvalue = RTL;

    imageLabel = new QLabel(this);
    imageLabel->setScaledContents(true);
    char picStr[1024];
    memset(picStr, 0, 1024);
    pic_num = 0;
    ifstream infile_pic("txts/picpath.txt");
    while (infile_pic)
    {
        infile_pic.getline(picStr, 1024);
        if (strcmp(picStr, "") == 0) 
        {
            continue;
        }
        picPath[pic_num++] = new QString(picStr);
    }

    QImage initimage(*picPath[pic_num-1]);
    imageLabel->setPixmap(QPixmap::fromImage(initimage));
    QTimer *timerPic = new QTimer(this);
    connect(timerPic, SIGNAL(timeout()), this, SLOT(showPicture()));
    imageLabel->setGeometry(QRect(0, 0, 140, 300));
    #endif
    //imageLabel->setGeometry(QRect(0, 0, 512, 512));

    //TCPSOCKET
    #if 0
    tcpSocket = new QTcpSocket(this);
    connect(timerPic, SIGNAL(timeout()), this, SLOT(sendMsg()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMsg()));
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error()));
    tcpSocket->connectToHost(QHostAddress("10.1.14.30"), 8000);
    #endif
    //time = QTime(12, 0);
    //time.start();
    sendMsgTime();
    timer->start(200);
    timerPic->start(30000);
}

void MyDialog::sendMsg()
{
    #if 0
    QTextStream out(tcpSocket);
    out << *picPath[pic_no % pic_num] + "|0|1" << endl;
    #endif
}

void MyDialog::sendMsgTime()
{
    #if 0
    QTextStream out(tcpSocket);
    out << "gettime" << endl;
    #endif
}

void MyDialog::recvMsg()
{
    #if 0
    QString t("date");
    //long It;
    if (!tcpSocket->canReadLine()) 
        return ;
    //do
    //responseLine += tcpSocket->readLine();
    //while(tcpSocket->canReadLine());
    msgBuffer = tcpSocket->readLine();
    //t = msgBuffer.toStdString();
    //cout << "recv:" << t << endl;
    //system(t.c_str());
    //It = msgBuffer.toLong(); 
    //printf("It:%ld\n",It);
    t += msgBuffer;
    QByteArray ba = t.toLatin1();
    const char *c_str2 = ba.data();
    printf("str2: %s", c_str2);
    system(c_str2);
    //stime(&It);
    //textBrowser->setText(msgBuffer);
    //textBrowser->moveCursor(QTextCursor::End);
    #endif
}

void MyDialog::error()
{
    #if 0
    QMessageBox::critical(this, "Socket error", tcpSocket->errorString());
    tcpSocket->close();
    #endif
}

void MyDialog::showTime()
{
    time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2)  == 0) 
        text[2] = ' ';
    lcd->display(text);
    QDate date = QDate::currentDate();
    QString date_text;
    date_text.sprintf("%d-%02d-%02d", date.year(), date.month(), date.day());
    ymdlcd->display(date_text);
}

void MyDialog::showPicture()
{
    QImage image(*picPath[pic_no % pic_num]);
    imageLabel->setPixmap(QPixmap::fromImage(image));
    pic_no++;
}

void MyDialog::paintEvent(QPaintEvent *event)
{
    event = NULL;
    QPainter painter(this);
    painter.setFont(QFont("simsun", 22, QFont::Bold));
    painter.setPen(QColor(Qt::red));
    if (dirvalue == LTR) 
        //painter.drawText(paint_pos, 520, contentstr);
        painter.drawText(paint_pos, 420, contentstr);
    else if(dirvalue == RTL)
        //painter.drawText(width()-paint_pos, 540, contentstr);
        painter.drawText(width()-paint_pos, 460, contentstr);
        //painter.drawPixmap(event->rect().topLeft(), pixmap_new);
    painter.end();
    //bitBlt(this, event->rect().topLeft(), &pixmap);
}

void MyDialog::timeoutslot()
{
    int firstValue = fontMetrics().maxWidth();
    //cout << "firstvalue:" << firstValue << endl;
    paint_pos += firstValue;
    if (paint_pos > (width() + paint_txt_len)) 
    {
        paint_pos = 0;
    }
    update();
    //repaint(FALSE);
}

void MyDialog::resizeEvent(QResizeEvent *event)
{
    event = NULL;
    #if 0
    QRegion maskedRegion1(0, 0, width(), height());
    QRegion maskedRegion2(0, 0, 400, 300);
    setMask(maskedRegion1.subtracted(maskedRegion2));
    #endif
}

void MyDialog::enter()
{
    /*
    QTime time = QTime::currentTimeTime();
    QString text = "hello" + '\n';
    QString text = time.toString("hh:mm:ss.zzz");
    lineEdit->setText(text);
    timer->stop();
    */
}


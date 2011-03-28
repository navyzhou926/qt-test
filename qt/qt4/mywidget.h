#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QKeyEvent>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);

    QTextEdit* edit1;
    QTextEdit* edit2;

    void keyReleaseEvent(QKeyEvent *);

signals:

public slots:

};

#endif // MYWIDGET_H

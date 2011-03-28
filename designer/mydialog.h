#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <ui_mydialog.h>

namespace Ui {
    class MyDialog;
}

class MyDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
private:
    void enter();
private:
    QString buf;

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H

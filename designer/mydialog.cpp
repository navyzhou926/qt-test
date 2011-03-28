#include "mydialog.h"
#include "ui_mydialog.h"

MyDialog::MyDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    //connect(pushButton, SIGNAL(clicked()), this, SLOT(enter()));
}

/*
void MyDialog::enter()
{
    buf += lineEdit->text + '\n';
    lineEdit->clear;
    textBrowser->setText(buf);
    textBrowser->moveCursor(QTextCursor::End);
}
*/

MyDialog::~MyDialog()
{
    delete ui;
}

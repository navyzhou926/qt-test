#include <QApplication>
#include <QtCore/QTextCodec>
#include <QWidget>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));


    QFont font;
    font.setPointSize(12);
    font.setFamily("wenquanyi");
    app.setFont(font);
    MyDialog d;

    d.show();
    return app.exec();
    
    return 0;
}

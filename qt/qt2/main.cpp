#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QPushButton *button = new QPushButton("Quit");
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
    button->show();

    qDebug("a = %d",5);
    qDebug() << "aaa";
    cout << "hello world" << endl;
    return app.exec();
}

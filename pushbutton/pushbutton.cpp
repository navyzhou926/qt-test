#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton *button = new QPushButton("Quit");
    button->resize(75, 50);
    button->setFont(QFont("Times", 28, QFont::Bold));
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
    button->show();

    return app.exec();
}

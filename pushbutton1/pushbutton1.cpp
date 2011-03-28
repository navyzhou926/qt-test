#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    //QWidget *window = NULL;
    window->resize(200, 120);

    //QPushButton *button = new QPushButton("Quit");
    QPushButton button("Quit", window);
    button.setFont(QFont("Times", 18, QFont::Bold));
    button.setGeometry(10, 40, 180, 40);
    QObject::connect(&button, SIGNAL(clicked()), &app, SLOT(quit()));

    window->show();

    return app.exec();
}

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget win;

    win.show();
    QVBoxLayout *layout = new QVBoxLayout(&win);

    QTextEdit EditLeftTop(&win);
  //  EditLeftTop.show();

    QTextEdit EditLeftDown;
  //  EditLeftDown.show();

    layout->addWidget(&EditLeftTop, 8);
    layout->addWidget(&EditLeftDown, 1);

    return app.exec();
}



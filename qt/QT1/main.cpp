#include <QApplication>
#include <QWidget>
#include <QLabel>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QLabel win;

    //QWidget win;
    win.setWindowTitle("Hello Navy");
    win.setText("This is content!");
    win.show();

    return app.exec();
}


#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label1 = new QLabel("Navy Zhou");
    QLabel *label2 = new QLabel("<h2><font color='red'>hello</font>,world<h2>");
    label1->show();
    label2->show();

    return app.exec();
}

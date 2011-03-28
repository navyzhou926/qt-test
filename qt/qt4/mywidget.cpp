#include "mywidget.h"
#include <QApplication>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    edit1 = new QTextEdit();
    edit2 = new QTextEdit();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(edit1, 8);
    layout->addWidget(edit2, 2);
}

void MyWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return)
    {
        QString str = edit2->toPlainText();

        str = str.left(str.length()-1);

        edit1->append(str);

        edit2->clear();
    }
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyWidget win;
    win.show();

    return app.exec();
}

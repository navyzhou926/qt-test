#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <lcdrange.h>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent) 
    :QWidget(parent)
{
    setFixedSize(500, 320);

    QPushButton *quit = new QPushButton(tr("Quit"), this);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    //quit->setGeometry(62, 40, 75, 30);
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QGridLayout *grid = new QGridLayout;
    LCDRange *previousRange = NULL;
    for(int row = 0; row < 3; ++row)
    {
        for(int column = 0; column < 3; ++column)
        {
            LCDRange *lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, column);
            if (previousRange) 
            {
                connect(lcdRange, SIGNAL(valueChanged(int)), previousRange, SLOT(setValue(int)));
                previousRange = lcdRange;
            }
        }
    }

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}


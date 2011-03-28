#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>

class LCDRange : public QWidget
{
public:
    LCDRange(QWidget *parent = 0);
};

LCDRange::LCDRange(QWidget *parent) 
    :QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    //lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setNumDigits(3);
    lcd->display(5);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 199);
    slider->setValue(5);
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

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
    for(int row = 0; row < 3; ++row)
    {
        for(int column = 0; column < 3; ++column)
        {
            LCDRange *lcdRange = new LCDRange;
            grid->addWidget(lcdRange, row, column);
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


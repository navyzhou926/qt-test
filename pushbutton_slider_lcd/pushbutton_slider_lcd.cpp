#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent) 
    :QWidget(parent)
{
    setFixedSize(200, 120);  //set window size

    QPushButton *quit = new QPushButton(tr("Quit"), this);
    //quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QLCDNumber *lcd = new QLCDNumber(2);
    //lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    //lcd->setRange(0, 99);
    lcd->setNumDigits(3);
    lcd->display(5);
    //lcd->setBinMode();
    //lcd->setHexMode();

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 199);
    //slider->sizeHint();
    //slider->minimumSizeHint();
    slider->setValue(5);
    //slider->setTickInterval(0);

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyWidget widget;
    widget.show();

    return app.exec();
}


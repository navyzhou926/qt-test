#include <QLCDNumber>
#include <QSlider>
#include <QVBoxLayout>
#include <lcdrange.h>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

LCDRange::LCDRange(QWidget *parent) 
    :QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    //lcd->setSegmentStyle(QLCDNumber::Filled);
    lcd->setNumDigits(3);
    lcd->display(5);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 199);
    //slider->sizeHint();
    //slider->minimumSizeHint();
    slider->setValue(5);

    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setValue(int value)
{
    slider->setValue(value);
}


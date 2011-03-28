#include <QFile>
#include <QDebug>

int main()
{
    QFile file("hello");
    file.open(QFile::ReadOnly);
    QByteArray ba =file.readAll();
    qDebug() << ba;
    file.close();
}

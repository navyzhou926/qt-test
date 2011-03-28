#include <QFile>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>

int main()
{
    QDir dir(".");
    QFileInfoList list = dir.entryInfoList();
    QList<QFileInfo>::Iterator it;
    //QFileInfo fi;
    for (it = list.begin(); it != list.end(); it++) 
    {
        qDebug() << (*it).filePath();
    }
}

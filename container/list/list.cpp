#include <QList>
#include <QVector>
#include <QDebug>
#include <QStack>

int main()
{
    #if 0
    QList<int> ints;
    QList<int>::Iterator it;
    ints.append(10);
    ints.append(20);
    ints.append(30);
    #endif

    #if 0
    QVector<int> ints;
    QVector<int>::Iterator it;
    ints.push_back(40);
    ints.push_back(50);
    ints.push_back(60);
    #endif

    #if 1
    QStack<int> ints;
    QStack<int>::Iterator it;
    ints.push_back(70);
    ints.push_back(80);
    ints.push_back(90);
    #endif

    for(it = ints.begin(); it != ints.end(); it++)
    {
        qDebug() << *it;
    }
}


#include <QApplication>
#include <QWidget>
#include <stdio.h>

using namespace std;

class Employee : public QObject
{
    Q_OBJECT
public:
    Employee()
    {
        mySalary = 0;
    }
    int salary() const 
    {
        return mySalary;
    }
public slots:
    void setSalary(int newSalary);

signals:
    void salaryChanged(int newSalary);
private:
    int mySalary;
};
void Employee::salaryChanged(int newSalary)
{
    mySalary = newSalary;
    //cout << "salaryChanged" << endl;
    printf("salaryChanged\n");
}

void Employee::setSalary(int newSalary)
{
    if (newSalary != mySalary) 
    {
        mySalary = newSalary;
        emit salaryChanged(mySalary);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;

    Employee *salary = new Employee;
    salary->setSalary(100000);

    widget.show();

    return app.exec();
}


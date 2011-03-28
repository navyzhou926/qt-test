#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

class Ui_Form
{
public:
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty()) 
        {
            Form->setObjectName(QString::fromUtf8("Form"));
        }
        Form->resize(400, 300);
        /*
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(400, 50, 113, 26));
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(100, 100, 256, 192));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 300, 92, 28));
        */
        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    }

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        //pushButton->setText(QApplication::translate("Form", "确 定", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Form);
    }
};

namespace Ui
{
    class Form: public Ui_Form{};
}

#endif 


/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created: Fri Mar 11 21:00:57 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyDialog
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QPushButton *Enter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyDialog)
    {
        if (MyDialog->objectName().isEmpty())
            MyDialog->setObjectName(QString::fromUtf8("MyDialog"));
        MyDialog->resize(443, 454);
        centralWidget = new QWidget(MyDialog);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        Enter = new QPushButton(centralWidget);
        Enter->setObjectName(QString::fromUtf8("Enter"));

        gridLayout->addWidget(Enter, 1, 1, 1, 1);

        MyDialog->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyDialog);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 443, 25));
        MyDialog->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyDialog);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyDialog->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyDialog);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyDialog->setStatusBar(statusBar);

        retranslateUi(MyDialog);

        QMetaObject::connectSlotsByName(MyDialog);
    } // setupUi

    void retranslateUi(QMainWindow *MyDialog)
    {
        MyDialog->setWindowTitle(QApplication::translate("MyDialog", "MyDialog", 0, QApplication::UnicodeUTF8));
        Enter->setText(QApplication::translate("MyDialog", "Enter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyDialog: public Ui_MyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *appNameEdit;
    QLineEdit *formatsEdit;
    QPushButton *registerButton;
    QLineEdit *filePathEdit;
    QPushButton *openButton;
    QPushButton *showAppsButton;
    QPushButton *showFormatsButton;
    QTextBrowser *textBrowser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        appNameEdit = new QLineEdit(centralwidget);
        appNameEdit->setObjectName("appNameEdit");

        verticalLayout->addWidget(appNameEdit);

        formatsEdit = new QLineEdit(centralwidget);
        formatsEdit->setObjectName("formatsEdit");

        verticalLayout->addWidget(formatsEdit);

        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);

        filePathEdit = new QLineEdit(centralwidget);
        filePathEdit->setObjectName("filePathEdit");

        verticalLayout->addWidget(filePathEdit);

        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");

        verticalLayout->addWidget(openButton);

        showAppsButton = new QPushButton(centralwidget);
        showAppsButton->setObjectName("showAppsButton");

        verticalLayout->addWidget(showAppsButton);

        showFormatsButton = new QPushButton(centralwidget);
        showFormatsButton->setObjectName("showFormatsButton");

        verticalLayout->addWidget(showFormatsButton);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "Register Application", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        showAppsButton->setText(QCoreApplication::translate("MainWindow", "Show Registered Applications", nullptr));
        showFormatsButton->setText(QCoreApplication::translate("MainWindow", "Show Registered Formats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

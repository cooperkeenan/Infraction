/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QPushButton *btn_continue;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btn_connectDB;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_7;
    QLabel *lbl_username;
    QLineEdit *usernameLineEdit;
    QLabel *lbl_password;
    QLineEdit *passwordLineEdit;
    QSpacerItem *verticalSpacer_8;
    QPushButton *loginButton;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(878, 617);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #2B2B2B;"));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName("gridLayout_3");
        btn_continue = new QPushButton(page);
        btn_continue->setObjectName("btn_continue");
        btn_continue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	\n"
"	background-color: rgb(111, 111, 111);\n"
"	color: rgb(110, 111, 110);\n"
"    color: #FFFFFF;  /* White text */\n"
"    border: 1px solid #3E8E41;  /* Slightly darker green border */\n"
"    border-radius: 4px;  /* Rounded corners */\n"
"    padding: 6px;  /* Padding */\n"
"    text-align: center;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45A049;  /* Lighter green on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;  /* Darker green on press */\n"
"}"));

        gridLayout_3->addWidget(btn_continue, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 5, 0, 1, 1);

        btn_connectDB = new QPushButton(page);
        btn_connectDB->setObjectName("btn_connectDB");
        sizePolicy.setHeightForWidth(btn_connectDB->sizePolicy().hasHeightForWidth());
        btn_connectDB->setSizePolicy(sizePolicy);
        btn_connectDB->setMaximumSize(QSize(150, 50));
        btn_connectDB->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* Green background */\n"
"    color: #FFFFFF;  /* White text */\n"
"    border: 1px solid #3E8E41;  /* Slightly darker green border */\n"
"    border-radius: 4px;  /* Rounded corners */\n"
"    padding: 6px;  /* Padding */\n"
"    text-align: center;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45A049;  /* Lighter green on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;  /* Darker green on press */\n"
"}"));

        gridLayout_3->addWidget(btn_connectDB, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;  /* White text */\n"
"    font-size: 14px;\n"
"    font-weight: normal;\n"
"}"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        lbl_username = new QLabel(page_2);
        lbl_username->setObjectName("lbl_username");
        lbl_username->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;  /* White text */\n"
"    font-size: 18px;\n"
"    font-weight: normal;\n"
"	font: 700 18pt \"Arial\";\n"
"}\n"
""));

        verticalLayout_2->addWidget(lbl_username);

        usernameLineEdit = new QLineEdit(page_2);
        usernameLineEdit->setObjectName("usernameLineEdit");
        sizePolicy.setHeightForWidth(usernameLineEdit->sizePolicy().hasHeightForWidth());
        usernameLineEdit->setSizePolicy(sizePolicy);
        usernameLineEdit->setMaximumSize(QSize(275, 40));
        usernameLineEdit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;  /* White text */\n"
"    font-size: 14px;\n"
"    font-weight: normal;\n"
"}\n"
""));

        verticalLayout_2->addWidget(usernameLineEdit);

        lbl_password = new QLabel(page_2);
        lbl_password->setObjectName("lbl_password");
        lbl_password->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;  /* White text */\n"
"    font-size: 18px;\n"
"    font-weight: normal;\n"
"	font: 700 18pt \"Arial\";\n"
"}\n"
""));

        verticalLayout_2->addWidget(lbl_password);

        passwordLineEdit = new QLineEdit(page_2);
        passwordLineEdit->setObjectName("passwordLineEdit");
        sizePolicy.setHeightForWidth(passwordLineEdit->sizePolicy().hasHeightForWidth());
        passwordLineEdit->setSizePolicy(sizePolicy);
        passwordLineEdit->setMaximumSize(QSize(275, 40));
        passwordLineEdit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #FFFFFF;  /* White text */\n"
"    font-size: 14px;\n"
"    font-weight: normal;\n"
"}\n"
""));

        verticalLayout_2->addWidget(passwordLineEdit);

        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_8);

        loginButton = new QPushButton(page_2);
        loginButton->setObjectName("loginButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy1);
        loginButton->setMaximumSize(QSize(275, 50));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* Green background */\n"
"    color: #FFFFFF;  /* White text */\n"
"    border: 1px solid #3E8E41;  /* Slightly darker green border */\n"
"    border-radius: 4px;  /* Rounded corners */\n"
"    padding: 6px;  /* Padding */\n"
"    text-align: center;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45A049;  /* Lighter green on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;  /* Darker green on press */\n"
"}\n"
""));

        verticalLayout_2->addWidget(loginButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        gridLayout_5->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_4->addWidget(stackedWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 878, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_continue->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        btn_connectDB->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Database Connection", nullptr));
        lbl_username->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        lbl_password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

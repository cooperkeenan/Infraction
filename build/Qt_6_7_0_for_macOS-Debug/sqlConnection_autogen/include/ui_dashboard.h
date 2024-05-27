/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dashboard
{
public:
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *page_2;

    void setupUi(QWidget *dashboard)
    {
        if (dashboard->objectName().isEmpty())
            dashboard->setObjectName("dashboard");
        dashboard->resize(1007, 605);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(dashboard->sizePolicy().hasHeightForWidth());
        dashboard->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(dashboard);
        gridLayout_2->setObjectName("gridLayout_2");
        stackedWidget = new QStackedWidget(dashboard);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #303030;"));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(page);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 1, 3, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(dashboard);

        QMetaObject::connectSlotsByName(dashboard);
    } // setupUi

    void retranslateUi(QWidget *dashboard)
    {
        dashboard->setWindowTitle(QCoreApplication::translate("dashboard", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dashboard: public Ui_dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H

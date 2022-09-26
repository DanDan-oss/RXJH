/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *procListWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *dllNameLineEdit;
    QToolButton *browserFileToolButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *newButton;
    QPushButton *injectButton;
    QPushButton *uninjectButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(335, 537);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        procListWidget = new QListWidget(centralWidget);
        procListWidget->setObjectName("procListWidget");
        procListWidget->setGeometry(QRect(30, 120, 271, 361));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(13, 40, 291, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        dllNameLineEdit = new QLineEdit(layoutWidget);
        dllNameLineEdit->setObjectName("dllNameLineEdit");

        horizontalLayout->addWidget(dllNameLineEdit);

        browserFileToolButton = new QToolButton(layoutWidget);
        browserFileToolButton->setObjectName("browserFileToolButton");

        horizontalLayout->addWidget(browserFileToolButton);

        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 80, 239, 25));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        newButton = new QPushButton(widget);
        newButton->setObjectName("newButton");

        horizontalLayout_2->addWidget(newButton);

        injectButton = new QPushButton(widget);
        injectButton->setObjectName("injectButton");

        horizontalLayout_2->addWidget(injectButton);

        uninjectButton = new QPushButton(widget);
        uninjectButton->setObjectName("uninjectButton");

        horizontalLayout_2->addWidget(uninjectButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 335, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200:", nullptr));
        browserFileToolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        newButton->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
        injectButton->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\205\245", nullptr));
        uninjectButton->setText(QCoreApplication::translate("MainWindow", "\345\215\270\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

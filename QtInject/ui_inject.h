/********************************************************************************
** Form generated from reading UI file 'inject.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INJECT_H
#define UI_INJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inject
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *EDIT_DLLPATH;
    QPushButton *BTN_FILE;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *BTN_REFRESH;
    QPushButton *BTN_LOAD;
    QPushButton *BTN_UNLOAD;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QTextEdit *EDIT_USER;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QTextEdit *EDIT_PASS;
    QPushButton *BTN_LOGIN;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *Inject)
    {
        if (Inject->objectName().isEmpty())
            Inject->setObjectName("Inject");
        Inject->resize(513, 578);
        Inject->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayoutWidget = new QWidget(Inject);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 490, 391, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        EDIT_DLLPATH = new QTextEdit(horizontalLayoutWidget);
        EDIT_DLLPATH->setObjectName("EDIT_DLLPATH");
        EDIT_DLLPATH->setMaximumSize(QSize(300, 26));

        horizontalLayout->addWidget(EDIT_DLLPATH);

        BTN_FILE = new QPushButton(horizontalLayoutWidget);
        BTN_FILE->setObjectName("BTN_FILE");
        BTN_FILE->setMaximumSize(QSize(40, 30));

        horizontalLayout->addWidget(BTN_FILE);

        horizontalLayoutWidget_2 = new QWidget(Inject);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(40, 530, 391, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(1, 1, 1, 1);
        BTN_REFRESH = new QPushButton(horizontalLayoutWidget_2);
        BTN_REFRESH->setObjectName("BTN_REFRESH");
        BTN_REFRESH->setMaximumSize(QSize(150, 30));

        horizontalLayout_3->addWidget(BTN_REFRESH);

        BTN_LOAD = new QPushButton(horizontalLayoutWidget_2);
        BTN_LOAD->setObjectName("BTN_LOAD");
        BTN_LOAD->setMaximumSize(QSize(150, 30));

        horizontalLayout_3->addWidget(BTN_LOAD);

        BTN_UNLOAD = new QPushButton(horizontalLayoutWidget_2);
        BTN_UNLOAD->setObjectName("BTN_UNLOAD");
        BTN_UNLOAD->setMaximumSize(QSize(150, 30));

        horizontalLayout_3->addWidget(BTN_UNLOAD);

        horizontalLayoutWidget_3 = new QWidget(Inject);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(29, 410, 291, 32));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName("label_2");

        horizontalLayout_4->addWidget(label_2);

        EDIT_USER = new QTextEdit(horizontalLayoutWidget_3);
        EDIT_USER->setObjectName("EDIT_USER");
        EDIT_USER->setMaximumSize(QSize(250, 26));

        horizontalLayout_4->addWidget(EDIT_USER);

        horizontalLayoutWidget_4 = new QWidget(Inject);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(30, 450, 361, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        EDIT_PASS = new QTextEdit(horizontalLayoutWidget_4);
        EDIT_PASS->setObjectName("EDIT_PASS");
        EDIT_PASS->setMaximumSize(QSize(250, 26));

        horizontalLayout_5->addWidget(EDIT_PASS);

        BTN_LOGIN = new QPushButton(horizontalLayoutWidget_4);
        BTN_LOGIN->setObjectName("BTN_LOGIN");
        BTN_LOGIN->setMaximumSize(QSize(70, 25));

        horizontalLayout_5->addWidget(BTN_LOGIN);

        horizontalLayoutWidget_5 = new QWidget(Inject);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(10, 10, 461, 391));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(horizontalLayoutWidget_5);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setMaximumSize(QSize(450, 380));

        horizontalLayout_6->addWidget(treeWidget);


        retranslateUi(Inject);

        QMetaObject::connectSlotsByName(Inject);
    } // setupUi

    void retranslateUi(QWidget *Inject)
    {
        Inject->setWindowTitle(QCoreApplication::translate("Inject", "Form", nullptr));
        label->setText(QCoreApplication::translate("Inject", "\346\211\223\345\274\200:", nullptr));
        BTN_FILE->setText(QCoreApplication::translate("Inject", "...", nullptr));
        BTN_REFRESH->setText(QCoreApplication::translate("Inject", "\345\210\267  \346\226\260", nullptr));
        BTN_LOAD->setText(QCoreApplication::translate("Inject", "\346\263\250  \345\205\245", nullptr));
        BTN_UNLOAD->setText(QCoreApplication::translate("Inject", "\345\215\270  \350\275\275", nullptr));
        label_2->setText(QCoreApplication::translate("Inject", "\350\264\246 \346\210\267:   ", nullptr));
        label_3->setText(QCoreApplication::translate("Inject", "\345\257\206 \347\240\201:  ", nullptr));
        BTN_LOGIN->setText(QCoreApplication::translate("Inject", " \350\207\252 \345\212\250 \347\231\273 \345\275\225 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inject: public Ui_Inject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INJECT_H

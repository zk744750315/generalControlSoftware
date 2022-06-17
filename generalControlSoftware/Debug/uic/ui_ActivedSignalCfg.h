/********************************************************************************
** Form generated from reading UI file 'ActivedSignalCfg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVEDSIGNALCFG_H
#define UI_ACTIVEDSIGNALCFG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActivedSignalCfg
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCfgChannel;
    QComboBox *combCfgChannel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCfgApplyToAll;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *spinBoxVoltage;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QDoubleSpinBox *spinBoxCurrent;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnOpen;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSaveAs;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnCancel;

    void setupUi(QWidget *ActivedSignalCfg)
    {
        if (ActivedSignalCfg->objectName().isEmpty())
            ActivedSignalCfg->setObjectName(QString::fromUtf8("ActivedSignalCfg"));
        ActivedSignalCfg->resize(539, 564);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActivedSignalCfg->setWindowIcon(icon);
        ActivedSignalCfg->setStyleSheet(QString::fromUtf8("QWidget{\n"
"font: 12pt \"SimSun\";\n"
"}\n"
"QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
"	font: 11pt \"SimSun\";\n"
"	border: 1px solid rgb(150,150,150);\n"
"	\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(200, 200, 200);\n"
"}\n"
"\n"
" QPushButton:pressed\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        pushButton = new QPushButton(ActivedSignalCfg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 500, 111, 28));
        label = new QLabel(ActivedSignalCfg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 510, 72, 15));
        layoutWidget = new QWidget(ActivedSignalCfg);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 41, 428, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel = new QLabel(layoutWidget);
        labelCfgChannel->setObjectName(QString::fromUtf8("labelCfgChannel"));

        horizontalLayout->addWidget(labelCfgChannel);

        combCfgChannel = new QComboBox(layoutWidget);
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->setObjectName(QString::fromUtf8("combCfgChannel"));
        combCfgChannel->setMinimumSize(QSize(160, 28));

        horizontalLayout->addWidget(combCfgChannel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCfgApplyToAll = new QPushButton(layoutWidget);
        btnCfgApplyToAll->setObjectName(QString::fromUtf8("btnCfgApplyToAll"));
        btnCfgApplyToAll->setMinimumSize(QSize(0, 28));

        horizontalLayout->addWidget(btnCfgApplyToAll);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 2);
        layoutWidget1 = new QWidget(ActivedSignalCfg);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(32, 79, 431, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBoxVoltage = new QDoubleSpinBox(layoutWidget1);
        spinBoxVoltage->setObjectName(QString::fromUtf8("spinBoxVoltage"));
        spinBoxVoltage->setMinimumSize(QSize(0, 28));
        spinBoxVoltage->setMinimum(25.000000000000000);
        spinBoxVoltage->setMaximum(35.000000000000000);

        horizontalLayout_2->addWidget(spinBoxVoltage);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBoxCurrent = new QDoubleSpinBox(layoutWidget1);
        spinBoxCurrent->setObjectName(QString::fromUtf8("spinBoxCurrent"));
        spinBoxCurrent->setMinimumSize(QSize(0, 28));
        spinBoxCurrent->setMaximum(10.000000000000000);

        horizontalLayout_2->addWidget(spinBoxCurrent);

        layoutWidget2 = new QWidget(ActivedSignalCfg);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 420, 441, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnOpen = new QPushButton(layoutWidget2);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnOpen);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnSaveAs = new QPushButton(layoutWidget2);
        btnSaveAs->setObjectName(QString::fromUtf8("btnSaveAs"));
        btnSaveAs->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnSaveAs);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnSave = new QPushButton(layoutWidget2);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnSave);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btnCancel = new QPushButton(layoutWidget2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(2, 3);
        horizontalLayout_3->setStretch(4, 3);
        horizontalLayout_3->setStretch(6, 3);

        retranslateUi(ActivedSignalCfg);

        QMetaObject::connectSlotsByName(ActivedSignalCfg);
    } // setupUi

    void retranslateUi(QWidget *ActivedSignalCfg)
    {
        ActivedSignalCfg->setWindowTitle(QApplication::translate("ActivedSignalCfg", "\346\277\200\346\264\273\346\250\241\345\235\227\351\205\215\347\275\256", nullptr));
        pushButton->setText(QApplication::translate("ActivedSignalCfg", "PushButton", nullptr));
        label->setText(QApplication::translate("ActivedSignalCfg", "TextLabel", nullptr));
        labelCfgChannel->setText(QApplication::translate("ActivedSignalCfg", "\351\205\215\347\275\256\351\200\232\351\201\223\357\274\232", nullptr));
        combCfgChannel->setItemText(0, QApplication::translate("ActivedSignalCfg", "\347\254\2541\350\267\257\346\277\200\346\264\273\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(1, QApplication::translate("ActivedSignalCfg", "\347\254\2542\350\267\257\346\277\200\346\264\273\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(2, QApplication::translate("ActivedSignalCfg", "\347\254\2543\350\267\257\346\277\200\346\264\273\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));

        btnCfgApplyToAll->setText(QApplication::translate("ActivedSignalCfg", "\345\272\224\347\224\250\345\210\260\346\211\200\346\234\211", nullptr));
        label_2->setText(QApplication::translate("ActivedSignalCfg", "\347\224\265\345\216\213\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ActivedSignalCfg", "\347\224\265\346\265\201\357\274\232", nullptr));
        btnOpen->setText(QApplication::translate("ActivedSignalCfg", "\346\211\223\345\274\200", nullptr));
        btnSaveAs->setText(QApplication::translate("ActivedSignalCfg", "\345\217\246\345\255\230\344\270\272", nullptr));
        btnSave->setText(QApplication::translate("ActivedSignalCfg", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QApplication::translate("ActivedSignalCfg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActivedSignalCfg: public Ui_ActivedSignalCfg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVEDSIGNALCFG_H

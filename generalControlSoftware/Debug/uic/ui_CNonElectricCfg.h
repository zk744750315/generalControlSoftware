/********************************************************************************
** Form generated from reading UI file 'CNonElectricCfg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNONELECTRICCFG_H
#define UI_CNONELECTRICCFG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CNonElectricCfg
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCfgChannel;
    QComboBox *combCfgChannel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCfgApplyToAll;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnOpen;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSaveAs;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnCancel;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QSpinBox *spinLadderwaveFreshPer;
    QLabel *labelCfgChannel_4;
    QLabel *labelCfgChannel_5;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpinBox *spinNoEleCheckSampPer;
    QWidget *widgetChannelData;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelCfgChannel_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QComboBox *combCVaveform;
    QHBoxLayout *LayoutDCOutput;
    QWidget *widget1DCOutput;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelCfgChannel_3;
    QWidget *widget2DCOutput;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *spinDCAmplitude;
    QHBoxLayout *LayoutLadderOutput;
    QWidget *widget1LadderOutput;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget2LadderOutput;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *spinLadderOutH;
    QDoubleSpinBox *spinLadderOutL;
    QSpinBox *spinLadderOutStartValue;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CNonElectricCfg)
    {
        if (CNonElectricCfg->objectName().isEmpty())
            CNonElectricCfg->setObjectName(QString::fromUtf8("CNonElectricCfg"));
        CNonElectricCfg->resize(602, 564);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        CNonElectricCfg->setWindowIcon(icon);
        CNonElectricCfg->setStyleSheet(QString::fromUtf8("QWidget{\n"
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
        layoutWidget = new QWidget(CNonElectricCfg);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(31, 41, 501, 30));
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
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->addItem(QString());
        combCfgChannel->setObjectName(QString::fromUtf8("combCfgChannel"));
        combCfgChannel->setMinimumSize(QSize(230, 28));

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
        layoutWidget1 = new QWidget(CNonElectricCfg);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 490, 441, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnOpen = new QPushButton(layoutWidget1);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnOpen);

        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnSaveAs = new QPushButton(layoutWidget1);
        btnSaveAs->setObjectName(QString::fromUtf8("btnSaveAs"));
        btnSaveAs->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnSaveAs);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnSave = new QPushButton(layoutWidget1);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnSave);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btnCancel = new QPushButton(layoutWidget1);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 28));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(2, 3);
        horizontalLayout_3->setStretch(4, 3);
        horizontalLayout_3->setStretch(6, 3);
        layoutWidget2 = new QWidget(CNonElectricCfg);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 360, 501, 59));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        spinLadderwaveFreshPer = new QSpinBox(layoutWidget2);
        spinLadderwaveFreshPer->setObjectName(QString::fromUtf8("spinLadderwaveFreshPer"));
        spinLadderwaveFreshPer->setMinimum(1);
        spinLadderwaveFreshPer->setMaximum(100);
        spinLadderwaveFreshPer->setSingleStep(1);

        gridLayout_2->addWidget(spinLadderwaveFreshPer, 1, 2, 1, 1);

        labelCfgChannel_4 = new QLabel(layoutWidget2);
        labelCfgChannel_4->setObjectName(QString::fromUtf8("labelCfgChannel_4"));

        gridLayout_2->addWidget(labelCfgChannel_4, 0, 0, 1, 1);

        labelCfgChannel_5 = new QLabel(layoutWidget2);
        labelCfgChannel_5->setObjectName(QString::fromUtf8("labelCfgChannel_5"));

        gridLayout_2->addWidget(labelCfgChannel_5, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 1, 1, 1);

        spinNoEleCheckSampPer = new QSpinBox(layoutWidget2);
        spinNoEleCheckSampPer->setObjectName(QString::fromUtf8("spinNoEleCheckSampPer"));
        spinNoEleCheckSampPer->setMaximum(1000000);
        spinNoEleCheckSampPer->setValue(1);

        gridLayout_2->addWidget(spinNoEleCheckSampPer, 0, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 3);
        gridLayout_2->setColumnStretch(2, 2);
        widgetChannelData = new QWidget(CNonElectricCfg);
        widgetChannelData->setObjectName(QString::fromUtf8("widgetChannelData"));
        widgetChannelData->setGeometry(QRect(30, 80, 511, 273));
        verticalLayout_7 = new QVBoxLayout(widgetChannelData);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_2 = new QWidget(widgetChannelData);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_6 = new QVBoxLayout(widget_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, -1, -1);
        labelCfgChannel_2 = new QLabel(widget_2);
        labelCfgChannel_2->setObjectName(QString::fromUtf8("labelCfgChannel_2"));

        verticalLayout_6->addWidget(labelCfgChannel_2);


        horizontalLayout_2->addWidget(widget_2);

        widget = new QWidget(widgetChannelData);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(-1, -1, 0, -1);
        combCVaveform = new QComboBox(widget);
        combCVaveform->addItem(QString());
        combCVaveform->addItem(QString());
        combCVaveform->setObjectName(QString::fromUtf8("combCVaveform"));
        combCVaveform->setMinimumSize(QSize(230, 28));

        verticalLayout_5->addWidget(combCVaveform);


        horizontalLayout_2->addWidget(widget);


        verticalLayout_7->addLayout(horizontalLayout_2);

        LayoutDCOutput = new QHBoxLayout();
        LayoutDCOutput->setSpacing(6);
        LayoutDCOutput->setObjectName(QString::fromUtf8("LayoutDCOutput"));
        widget1DCOutput = new QWidget(widgetChannelData);
        widget1DCOutput->setObjectName(QString::fromUtf8("widget1DCOutput"));
        verticalLayout_3 = new QVBoxLayout(widget1DCOutput);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        labelCfgChannel_3 = new QLabel(widget1DCOutput);
        labelCfgChannel_3->setObjectName(QString::fromUtf8("labelCfgChannel_3"));

        verticalLayout_3->addWidget(labelCfgChannel_3);


        LayoutDCOutput->addWidget(widget1DCOutput);

        widget2DCOutput = new QWidget(widgetChannelData);
        widget2DCOutput->setObjectName(QString::fromUtf8("widget2DCOutput"));
        verticalLayout_4 = new QVBoxLayout(widget2DCOutput);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 0, -1);
        spinDCAmplitude = new QDoubleSpinBox(widget2DCOutput);
        spinDCAmplitude->setObjectName(QString::fromUtf8("spinDCAmplitude"));
        spinDCAmplitude->setMaximum(5.000000000000000);

        verticalLayout_4->addWidget(spinDCAmplitude);


        LayoutDCOutput->addWidget(widget2DCOutput);


        verticalLayout_7->addLayout(LayoutDCOutput);

        LayoutLadderOutput = new QHBoxLayout();
        LayoutLadderOutput->setSpacing(6);
        LayoutLadderOutput->setObjectName(QString::fromUtf8("LayoutLadderOutput"));
        widget1LadderOutput = new QWidget(widgetChannelData);
        widget1LadderOutput->setObjectName(QString::fromUtf8("widget1LadderOutput"));
        verticalLayout = new QVBoxLayout(widget1LadderOutput);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label = new QLabel(widget1LadderOutput);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget1LadderOutput);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget1LadderOutput);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        LayoutLadderOutput->addWidget(widget1LadderOutput);

        widget2LadderOutput = new QWidget(widgetChannelData);
        widget2LadderOutput->setObjectName(QString::fromUtf8("widget2LadderOutput"));
        verticalLayout_2 = new QVBoxLayout(widget2LadderOutput);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 0, -1);
        spinLadderOutH = new QDoubleSpinBox(widget2LadderOutput);
        spinLadderOutH->setObjectName(QString::fromUtf8("spinLadderOutH"));
        spinLadderOutH->setMaximum(5.000000000000000);

        verticalLayout_2->addWidget(spinLadderOutH);

        spinLadderOutL = new QDoubleSpinBox(widget2LadderOutput);
        spinLadderOutL->setObjectName(QString::fromUtf8("spinLadderOutL"));
        spinLadderOutL->setMaximum(5.000000000000000);

        verticalLayout_2->addWidget(spinLadderOutL);

        spinLadderOutStartValue = new QSpinBox(widget2LadderOutput);
        spinLadderOutStartValue->setObjectName(QString::fromUtf8("spinLadderOutStartValue"));
        spinLadderOutStartValue->setMinimum(1);
        spinLadderOutStartValue->setMaximum(64);

        verticalLayout_2->addWidget(spinLadderOutStartValue);


        LayoutLadderOutput->addWidget(widget2LadderOutput);


        verticalLayout_7->addLayout(LayoutLadderOutput);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        retranslateUi(CNonElectricCfg);

        QMetaObject::connectSlotsByName(CNonElectricCfg);
    } // setupUi

    void retranslateUi(QWidget *CNonElectricCfg)
    {
        CNonElectricCfg->setWindowTitle(QApplication::translate("CNonElectricCfg", "\351\235\236\347\224\265\351\207\217\346\250\241\345\235\227\351\205\215\347\275\256", nullptr));
        labelCfgChannel->setText(QApplication::translate("CNonElectricCfg", "\351\205\215\347\275\256\351\200\232\351\201\223\357\274\232", nullptr));
        combCfgChannel->setItemText(0, QApplication::translate("CNonElectricCfg", "\347\254\2541\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(1, QApplication::translate("CNonElectricCfg", "\347\254\2542\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(2, QApplication::translate("CNonElectricCfg", "\347\254\2543\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(3, QApplication::translate("CNonElectricCfg", "\347\254\2544\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(4, QApplication::translate("CNonElectricCfg", "\347\254\2545\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(5, QApplication::translate("CNonElectricCfg", "\347\254\2546\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(6, QApplication::translate("CNonElectricCfg", "\347\254\2547\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(7, QApplication::translate("CNonElectricCfg", "\347\254\2549\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(8, QApplication::translate("CNonElectricCfg", "\347\254\25410\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(9, QApplication::translate("CNonElectricCfg", "\347\254\25411\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(10, QApplication::translate("CNonElectricCfg", "\347\254\25412\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(11, QApplication::translate("CNonElectricCfg", "\347\254\25413\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(12, QApplication::translate("CNonElectricCfg", "\347\254\25414\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(13, QApplication::translate("CNonElectricCfg", "\347\254\25415\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(14, QApplication::translate("CNonElectricCfg", "\347\254\25416\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(15, QApplication::translate("CNonElectricCfg", "\347\254\25417\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(16, QApplication::translate("CNonElectricCfg", "\347\254\25418\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(17, QApplication::translate("CNonElectricCfg", "\347\254\25419\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(18, QApplication::translate("CNonElectricCfg", "\347\254\25420\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(19, QApplication::translate("CNonElectricCfg", "\347\254\25421\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(20, QApplication::translate("CNonElectricCfg", "\347\254\25422\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(21, QApplication::translate("CNonElectricCfg", "\347\254\25423\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(22, QApplication::translate("CNonElectricCfg", "\347\254\25424\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(23, QApplication::translate("CNonElectricCfg", "\347\254\25425\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(24, QApplication::translate("CNonElectricCfg", "\347\254\25426\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(25, QApplication::translate("CNonElectricCfg", "\347\254\25427\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(26, QApplication::translate("CNonElectricCfg", "\347\254\25428\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(27, QApplication::translate("CNonElectricCfg", "\347\254\25429\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(28, QApplication::translate("CNonElectricCfg", "\347\254\25430\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(29, QApplication::translate("CNonElectricCfg", "\347\254\25431\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(30, QApplication::translate("CNonElectricCfg", "\347\254\25432\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(31, QApplication::translate("CNonElectricCfg", "\347\254\25433\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(32, QApplication::translate("CNonElectricCfg", "\347\254\25434\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(33, QApplication::translate("CNonElectricCfg", "\347\254\25435\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(34, QApplication::translate("CNonElectricCfg", "\347\254\25436\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(35, QApplication::translate("CNonElectricCfg", "\347\254\25437\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(36, QApplication::translate("CNonElectricCfg", "\347\254\25438\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(37, QApplication::translate("CNonElectricCfg", "\347\254\25439\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(38, QApplication::translate("CNonElectricCfg", "\347\254\25440\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(39, QApplication::translate("CNonElectricCfg", "\347\254\25441\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(40, QApplication::translate("CNonElectricCfg", "\347\254\25442\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(41, QApplication::translate("CNonElectricCfg", "\347\254\25443\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(42, QApplication::translate("CNonElectricCfg", "\347\254\25444\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(43, QApplication::translate("CNonElectricCfg", "\347\254\25445\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(44, QApplication::translate("CNonElectricCfg", "\347\254\25446\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(45, QApplication::translate("CNonElectricCfg", "\347\254\25447\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));
        combCfgChannel->setItemText(46, QApplication::translate("CNonElectricCfg", "\347\254\25448\350\267\257\351\235\236\347\224\265\351\207\217\344\277\241\345\217\267\351\200\232\351\201\223", nullptr));

        btnCfgApplyToAll->setText(QApplication::translate("CNonElectricCfg", "\345\272\224\347\224\250\345\210\260\346\211\200\346\234\211", nullptr));
        btnOpen->setText(QApplication::translate("CNonElectricCfg", "\346\211\223\345\274\200", nullptr));
        btnSaveAs->setText(QApplication::translate("CNonElectricCfg", "\345\217\246\345\255\230\344\270\272", nullptr));
        btnSave->setText(QApplication::translate("CNonElectricCfg", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QApplication::translate("CNonElectricCfg", "\345\217\226\346\266\210", nullptr));
        spinLadderwaveFreshPer->setSuffix(QApplication::translate("CNonElectricCfg", "ms", nullptr));
        labelCfgChannel_4->setText(QApplication::translate("CNonElectricCfg", "\351\235\236\347\224\265\351\207\217\350\207\252\346\243\200\351\207\207\346\240\267\345\221\250\346\234\237\357\274\232", nullptr));
        labelCfgChannel_5->setText(QApplication::translate("CNonElectricCfg", "\351\230\266\346\242\257\346\263\242\345\275\242\345\210\267\346\226\260\345\221\250\346\234\237\357\274\232", nullptr));
        spinNoEleCheckSampPer->setSuffix(QApplication::translate("CNonElectricCfg", "ms", nullptr));
        labelCfgChannel_2->setText(QApplication::translate("CNonElectricCfg", "\346\263\242\345\275\242\350\276\223\345\207\272\347\261\273\345\236\213\357\274\232", nullptr));
        combCVaveform->setItemText(0, QApplication::translate("CNonElectricCfg", "\347\233\264\346\265\201\350\276\223\345\207\272", nullptr));
        combCVaveform->setItemText(1, QApplication::translate("CNonElectricCfg", "\351\230\266\346\242\257\346\263\242\350\276\223\345\207\272", nullptr));

        labelCfgChannel_3->setText(QApplication::translate("CNonElectricCfg", "\347\233\264\346\265\201\344\277\241\345\217\267\350\276\223\345\207\272\345\271\205\345\200\274\357\274\232", nullptr));
        label->setText(QApplication::translate("CNonElectricCfg", "\351\230\266\346\242\257\346\263\242\345\275\242\350\276\223\345\207\272\351\253\230\345\271\205\345\200\274(H)\357\274\232", nullptr));
        label_2->setText(QApplication::translate("CNonElectricCfg", "\351\230\266\346\242\257\346\263\242\345\275\242\350\276\223\345\207\272\344\275\216\345\271\205\345\200\274(L)\357\274\232", nullptr));
        label_3->setText(QApplication::translate("CNonElectricCfg", "\351\230\266\346\242\257\346\263\242\345\275\242\350\276\223\345\207\272\345\210\235\345\247\213\345\272\217\345\210\227\345\200\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CNonElectricCfg: public Ui_CNonElectricCfg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNONELECTRICCFG_H

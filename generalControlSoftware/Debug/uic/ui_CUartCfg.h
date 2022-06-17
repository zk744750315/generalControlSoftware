/********************************************************************************
** Form generated from reading UI file 'CUartCfg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUARTCFG_H
#define UI_CUARTCFG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CUartCfg
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
    QWidget *widgetChannelData;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelCfgChannel_2;
    QLabel *labelCfgChannel_3;
    QLabel *labelCfgChannel_5;
    QLabel *labelCfgChannel_8;
    QLabel *labelCfgChannel_9;
    QLabel *label;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QComboBox *combInterfaceType;
    QComboBox *combWorkMode;
    QComboBox *combBaudRate;
    QComboBox *combCheckType;
    QComboBox *combStopBitLen;
    QRadioButton *radioDoubleRedundancy;
    QWidget *widget1SendPause_SendCmd_Send_ReceiveCmd;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelCfgChannel_7;
    QSpinBox *spinSendDataLen;
    QWidget *widget2SendPause_SendCmd_Send;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelCfgChannel_6;
    QSpinBox *spinFrameNumPos;
    QWidget *widget3SendPause_SendCmd_Send;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelCfgChannel_11;
    QPushButton *pushDigitalEditor;
    QWidget *widget4SendPause_Receive;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelCfgChannel_12;
    QComboBox *comboPauseType;
    QWidget *widget5SendPause_ReceivePause;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelCfgChannel_13;
    QSpinBox *spinPauseWidth;
    QWidget *widget6SendCmd;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelCfgChannel_14;
    QLineEdit *lineCMDHeaderFormat;
    QWidget *widget7Send;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelCfgChannel_15;
    QSpinBox *spinDigitOutPer;
    QWidget *widget8ReceivePause;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelCfgChannel_16;
    QSpinBox *spinPauseOutPer;
    QWidget *widget9ReceiveCmd;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelCfgChannel_17;
    QSpinBox *spinCmdOutPer;
    QWidget *widget10ReceiveCmd;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelCfgChannel_18;
    QSpinBox *spinCmdOutCount;
    QWidget *widget11ReceiveCmd;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelCfgChannel_19;
    QPushButton *pushCmdEditor1;
    QWidget *widget12ReceiveCmd;
    QHBoxLayout *horizontalLayout_15;
    QLabel *labelCfgChannel_20;
    QPushButton *pushCmdEditor2;
    QWidget *widget13ReceivePause_ReceiveCmd_Receive;
    QHBoxLayout *horizontalLayout_16;
    QLabel *labelCfgChannel_21;
    QSpinBox *spinReceiveDataLen;
    QWidget *widget14ReceivePause;
    QHBoxLayout *horizontalLayout_17;
    QLabel *labelCfgChannel_10;
    QSpinBox *spinPauseOutCount;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CUartCfg)
    {
        if (CUartCfg->objectName().isEmpty())
            CUartCfg->setObjectName(QString::fromUtf8("CUartCfg"));
        CUartCfg->resize(627, 835);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        CUartCfg->setWindowIcon(icon);
        CUartCfg->setStyleSheet(QString::fromUtf8("QWidget{\n"
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
        layoutWidget = new QWidget(CUartCfg);
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
        layoutWidget1 = new QWidget(CUartCfg);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 780, 441, 30));
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
        widgetChannelData = new QWidget(CUartCfg);
        widgetChannelData->setObjectName(QString::fromUtf8("widgetChannelData"));
        widgetChannelData->setGeometry(QRect(30, 80, 551, 661));
        verticalLayout = new QVBoxLayout(widgetChannelData);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_2 = new QWidget(widgetChannelData);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_6 = new QVBoxLayout(widget_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_2 = new QLabel(widget_2);
        labelCfgChannel_2->setObjectName(QString::fromUtf8("labelCfgChannel_2"));

        verticalLayout_6->addWidget(labelCfgChannel_2);

        labelCfgChannel_3 = new QLabel(widget_2);
        labelCfgChannel_3->setObjectName(QString::fromUtf8("labelCfgChannel_3"));

        verticalLayout_6->addWidget(labelCfgChannel_3);

        labelCfgChannel_5 = new QLabel(widget_2);
        labelCfgChannel_5->setObjectName(QString::fromUtf8("labelCfgChannel_5"));

        verticalLayout_6->addWidget(labelCfgChannel_5);

        labelCfgChannel_8 = new QLabel(widget_2);
        labelCfgChannel_8->setObjectName(QString::fromUtf8("labelCfgChannel_8"));

        verticalLayout_6->addWidget(labelCfgChannel_8);

        labelCfgChannel_9 = new QLabel(widget_2);
        labelCfgChannel_9->setObjectName(QString::fromUtf8("labelCfgChannel_9"));

        verticalLayout_6->addWidget(labelCfgChannel_9);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label);


        horizontalLayout_2->addWidget(widget_2);

        widget = new QWidget(widgetChannelData);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(7);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        combInterfaceType = new QComboBox(widget);
        combInterfaceType->addItem(QString());
        combInterfaceType->addItem(QString());
        combInterfaceType->setObjectName(QString::fromUtf8("combInterfaceType"));
        combInterfaceType->setMinimumSize(QSize(230, 28));

        verticalLayout_5->addWidget(combInterfaceType);

        combWorkMode = new QComboBox(widget);
        combWorkMode->addItem(QString());
        combWorkMode->addItem(QString());
        combWorkMode->addItem(QString());
        combWorkMode->addItem(QString());
        combWorkMode->addItem(QString());
        combWorkMode->addItem(QString());
        combWorkMode->addItem(QString());
        combWorkMode->setObjectName(QString::fromUtf8("combWorkMode"));
        combWorkMode->setMinimumSize(QSize(230, 28));

        verticalLayout_5->addWidget(combWorkMode);

        combBaudRate = new QComboBox(widget);
        combBaudRate->addItem(QString());
        combBaudRate->addItem(QString());
        combBaudRate->addItem(QString());
        combBaudRate->addItem(QString());
        combBaudRate->setObjectName(QString::fromUtf8("combBaudRate"));
        combBaudRate->setMinimumSize(QSize(230, 28));

        verticalLayout_5->addWidget(combBaudRate);

        combCheckType = new QComboBox(widget);
        combCheckType->addItem(QString());
        combCheckType->addItem(QString());
        combCheckType->addItem(QString());
        combCheckType->setObjectName(QString::fromUtf8("combCheckType"));
        combCheckType->setMinimumSize(QSize(230, 28));

        verticalLayout_5->addWidget(combCheckType);

        combStopBitLen = new QComboBox(widget);
        combStopBitLen->addItem(QString());
        combStopBitLen->addItem(QString());
        combStopBitLen->addItem(QString());
        combStopBitLen->setObjectName(QString::fromUtf8("combStopBitLen"));
        combStopBitLen->setMinimumSize(QSize(230, 28));

        verticalLayout_5->addWidget(combStopBitLen);

        radioDoubleRedundancy = new QRadioButton(widget);
        radioDoubleRedundancy->setObjectName(QString::fromUtf8("radioDoubleRedundancy"));

        verticalLayout_5->addWidget(radioDoubleRedundancy);


        horizontalLayout_2->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout_2);

        widget1SendPause_SendCmd_Send_ReceiveCmd = new QWidget(widgetChannelData);
        widget1SendPause_SendCmd_Send_ReceiveCmd->setObjectName(QString::fromUtf8("widget1SendPause_SendCmd_Send_ReceiveCmd"));
        horizontalLayout_4 = new QHBoxLayout(widget1SendPause_SendCmd_Send_ReceiveCmd);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_7 = new QLabel(widget1SendPause_SendCmd_Send_ReceiveCmd);
        labelCfgChannel_7->setObjectName(QString::fromUtf8("labelCfgChannel_7"));

        horizontalLayout_4->addWidget(labelCfgChannel_7);

        spinSendDataLen = new QSpinBox(widget1SendPause_SendCmd_Send_ReceiveCmd);
        spinSendDataLen->setObjectName(QString::fromUtf8("spinSendDataLen"));
        spinSendDataLen->setMinimum(1);
        spinSendDataLen->setMaximum(576);

        horizontalLayout_4->addWidget(spinSendDataLen);


        verticalLayout->addWidget(widget1SendPause_SendCmd_Send_ReceiveCmd);

        widget2SendPause_SendCmd_Send = new QWidget(widgetChannelData);
        widget2SendPause_SendCmd_Send->setObjectName(QString::fromUtf8("widget2SendPause_SendCmd_Send"));
        horizontalLayout_5 = new QHBoxLayout(widget2SendPause_SendCmd_Send);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_6 = new QLabel(widget2SendPause_SendCmd_Send);
        labelCfgChannel_6->setObjectName(QString::fromUtf8("labelCfgChannel_6"));

        horizontalLayout_5->addWidget(labelCfgChannel_6);

        spinFrameNumPos = new QSpinBox(widget2SendPause_SendCmd_Send);
        spinFrameNumPos->setObjectName(QString::fromUtf8("spinFrameNumPos"));
        spinFrameNumPos->setMinimum(1);
        spinFrameNumPos->setMaximum(1024);

        horizontalLayout_5->addWidget(spinFrameNumPos);


        verticalLayout->addWidget(widget2SendPause_SendCmd_Send);

        widget3SendPause_SendCmd_Send = new QWidget(widgetChannelData);
        widget3SendPause_SendCmd_Send->setObjectName(QString::fromUtf8("widget3SendPause_SendCmd_Send"));
        horizontalLayout_6 = new QHBoxLayout(widget3SendPause_SendCmd_Send);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_11 = new QLabel(widget3SendPause_SendCmd_Send);
        labelCfgChannel_11->setObjectName(QString::fromUtf8("labelCfgChannel_11"));

        horizontalLayout_6->addWidget(labelCfgChannel_11);

        pushDigitalEditor = new QPushButton(widget3SendPause_SendCmd_Send);
        pushDigitalEditor->setObjectName(QString::fromUtf8("pushDigitalEditor"));
        pushDigitalEditor->setMinimumSize(QSize(0, 28));

        horizontalLayout_6->addWidget(pushDigitalEditor);


        verticalLayout->addWidget(widget3SendPause_SendCmd_Send);

        widget4SendPause_Receive = new QWidget(widgetChannelData);
        widget4SendPause_Receive->setObjectName(QString::fromUtf8("widget4SendPause_Receive"));
        horizontalLayout_7 = new QHBoxLayout(widget4SendPause_Receive);
        horizontalLayout_7->setSpacing(7);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_12 = new QLabel(widget4SendPause_Receive);
        labelCfgChannel_12->setObjectName(QString::fromUtf8("labelCfgChannel_12"));

        horizontalLayout_7->addWidget(labelCfgChannel_12);

        comboPauseType = new QComboBox(widget4SendPause_Receive);
        comboPauseType->addItem(QString());
        comboPauseType->addItem(QString());
        comboPauseType->setObjectName(QString::fromUtf8("comboPauseType"));

        horizontalLayout_7->addWidget(comboPauseType);


        verticalLayout->addWidget(widget4SendPause_Receive);

        widget5SendPause_ReceivePause = new QWidget(widgetChannelData);
        widget5SendPause_ReceivePause->setObjectName(QString::fromUtf8("widget5SendPause_ReceivePause"));
        horizontalLayout_8 = new QHBoxLayout(widget5SendPause_ReceivePause);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_13 = new QLabel(widget5SendPause_ReceivePause);
        labelCfgChannel_13->setObjectName(QString::fromUtf8("labelCfgChannel_13"));

        horizontalLayout_8->addWidget(labelCfgChannel_13);

        spinPauseWidth = new QSpinBox(widget5SendPause_ReceivePause);
        spinPauseWidth->setObjectName(QString::fromUtf8("spinPauseWidth"));
        spinPauseWidth->setMinimum(1);
        spinPauseWidth->setMaximum(1000);

        horizontalLayout_8->addWidget(spinPauseWidth);


        verticalLayout->addWidget(widget5SendPause_ReceivePause);

        widget6SendCmd = new QWidget(widgetChannelData);
        widget6SendCmd->setObjectName(QString::fromUtf8("widget6SendCmd"));
        horizontalLayout_9 = new QHBoxLayout(widget6SendCmd);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_14 = new QLabel(widget6SendCmd);
        labelCfgChannel_14->setObjectName(QString::fromUtf8("labelCfgChannel_14"));

        horizontalLayout_9->addWidget(labelCfgChannel_14);

        lineCMDHeaderFormat = new QLineEdit(widget6SendCmd);
        lineCMDHeaderFormat->setObjectName(QString::fromUtf8("lineCMDHeaderFormat"));

        horizontalLayout_9->addWidget(lineCMDHeaderFormat);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);

        verticalLayout->addWidget(widget6SendCmd);

        widget7Send = new QWidget(widgetChannelData);
        widget7Send->setObjectName(QString::fromUtf8("widget7Send"));
        horizontalLayout_10 = new QHBoxLayout(widget7Send);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_15 = new QLabel(widget7Send);
        labelCfgChannel_15->setObjectName(QString::fromUtf8("labelCfgChannel_15"));

        horizontalLayout_10->addWidget(labelCfgChannel_15);

        spinDigitOutPer = new QSpinBox(widget7Send);
        spinDigitOutPer->setObjectName(QString::fromUtf8("spinDigitOutPer"));
        spinDigitOutPer->setMinimum(1);
        spinDigitOutPer->setMaximum(10000);

        horizontalLayout_10->addWidget(spinDigitOutPer);


        verticalLayout->addWidget(widget7Send);

        widget8ReceivePause = new QWidget(widgetChannelData);
        widget8ReceivePause->setObjectName(QString::fromUtf8("widget8ReceivePause"));
        horizontalLayout_11 = new QHBoxLayout(widget8ReceivePause);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_16 = new QLabel(widget8ReceivePause);
        labelCfgChannel_16->setObjectName(QString::fromUtf8("labelCfgChannel_16"));

        horizontalLayout_11->addWidget(labelCfgChannel_16);

        spinPauseOutPer = new QSpinBox(widget8ReceivePause);
        spinPauseOutPer->setObjectName(QString::fromUtf8("spinPauseOutPer"));
        spinPauseOutPer->setMinimum(1);
        spinPauseOutPer->setMaximum(10000);

        horizontalLayout_11->addWidget(spinPauseOutPer);


        verticalLayout->addWidget(widget8ReceivePause);

        widget9ReceiveCmd = new QWidget(widgetChannelData);
        widget9ReceiveCmd->setObjectName(QString::fromUtf8("widget9ReceiveCmd"));
        horizontalLayout_12 = new QHBoxLayout(widget9ReceiveCmd);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_17 = new QLabel(widget9ReceiveCmd);
        labelCfgChannel_17->setObjectName(QString::fromUtf8("labelCfgChannel_17"));

        horizontalLayout_12->addWidget(labelCfgChannel_17);

        spinCmdOutPer = new QSpinBox(widget9ReceiveCmd);
        spinCmdOutPer->setObjectName(QString::fromUtf8("spinCmdOutPer"));
        spinCmdOutPer->setMinimum(1);
        spinCmdOutPer->setMaximum(10000);

        horizontalLayout_12->addWidget(spinCmdOutPer);


        verticalLayout->addWidget(widget9ReceiveCmd);

        widget10ReceiveCmd = new QWidget(widgetChannelData);
        widget10ReceiveCmd->setObjectName(QString::fromUtf8("widget10ReceiveCmd"));
        horizontalLayout_13 = new QHBoxLayout(widget10ReceiveCmd);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_18 = new QLabel(widget10ReceiveCmd);
        labelCfgChannel_18->setObjectName(QString::fromUtf8("labelCfgChannel_18"));

        horizontalLayout_13->addWidget(labelCfgChannel_18);

        spinCmdOutCount = new QSpinBox(widget10ReceiveCmd);
        spinCmdOutCount->setObjectName(QString::fromUtf8("spinCmdOutCount"));
        spinCmdOutCount->setMinimum(1);
        spinCmdOutCount->setMaximum(100000);

        horizontalLayout_13->addWidget(spinCmdOutCount);


        verticalLayout->addWidget(widget10ReceiveCmd);

        widget11ReceiveCmd = new QWidget(widgetChannelData);
        widget11ReceiveCmd->setObjectName(QString::fromUtf8("widget11ReceiveCmd"));
        horizontalLayout_14 = new QHBoxLayout(widget11ReceiveCmd);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_19 = new QLabel(widget11ReceiveCmd);
        labelCfgChannel_19->setObjectName(QString::fromUtf8("labelCfgChannel_19"));

        horizontalLayout_14->addWidget(labelCfgChannel_19);

        pushCmdEditor1 = new QPushButton(widget11ReceiveCmd);
        pushCmdEditor1->setObjectName(QString::fromUtf8("pushCmdEditor1"));
        pushCmdEditor1->setMinimumSize(QSize(0, 28));

        horizontalLayout_14->addWidget(pushCmdEditor1);


        verticalLayout->addWidget(widget11ReceiveCmd);

        widget12ReceiveCmd = new QWidget(widgetChannelData);
        widget12ReceiveCmd->setObjectName(QString::fromUtf8("widget12ReceiveCmd"));
        horizontalLayout_15 = new QHBoxLayout(widget12ReceiveCmd);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_20 = new QLabel(widget12ReceiveCmd);
        labelCfgChannel_20->setObjectName(QString::fromUtf8("labelCfgChannel_20"));

        horizontalLayout_15->addWidget(labelCfgChannel_20);

        pushCmdEditor2 = new QPushButton(widget12ReceiveCmd);
        pushCmdEditor2->setObjectName(QString::fromUtf8("pushCmdEditor2"));
        pushCmdEditor2->setMinimumSize(QSize(0, 28));

        horizontalLayout_15->addWidget(pushCmdEditor2);


        verticalLayout->addWidget(widget12ReceiveCmd);

        widget13ReceivePause_ReceiveCmd_Receive = new QWidget(widgetChannelData);
        widget13ReceivePause_ReceiveCmd_Receive->setObjectName(QString::fromUtf8("widget13ReceivePause_ReceiveCmd_Receive"));
        horizontalLayout_16 = new QHBoxLayout(widget13ReceivePause_ReceiveCmd_Receive);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_21 = new QLabel(widget13ReceivePause_ReceiveCmd_Receive);
        labelCfgChannel_21->setObjectName(QString::fromUtf8("labelCfgChannel_21"));

        horizontalLayout_16->addWidget(labelCfgChannel_21);

        spinReceiveDataLen = new QSpinBox(widget13ReceivePause_ReceiveCmd_Receive);
        spinReceiveDataLen->setObjectName(QString::fromUtf8("spinReceiveDataLen"));
        spinReceiveDataLen->setMinimum(1);
        spinReceiveDataLen->setMaximum(1024);

        horizontalLayout_16->addWidget(spinReceiveDataLen);


        verticalLayout->addWidget(widget13ReceivePause_ReceiveCmd_Receive);

        widget14ReceivePause = new QWidget(widgetChannelData);
        widget14ReceivePause->setObjectName(QString::fromUtf8("widget14ReceivePause"));
        horizontalLayout_17 = new QHBoxLayout(widget14ReceivePause);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        labelCfgChannel_10 = new QLabel(widget14ReceivePause);
        labelCfgChannel_10->setObjectName(QString::fromUtf8("labelCfgChannel_10"));

        horizontalLayout_17->addWidget(labelCfgChannel_10);

        spinPauseOutCount = new QSpinBox(widget14ReceivePause);
        spinPauseOutCount->setObjectName(QString::fromUtf8("spinPauseOutCount"));
        spinPauseOutCount->setMinimum(1);
        spinPauseOutCount->setMaximum(100000);

        horizontalLayout_17->addWidget(spinPauseOutCount);


        verticalLayout->addWidget(widget14ReceivePause);

        verticalSpacer = new QSpacerItem(20, 9, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CUartCfg);

        QMetaObject::connectSlotsByName(CUartCfg);
    } // setupUi

    void retranslateUi(QWidget *CUartCfg)
    {
        CUartCfg->setWindowTitle(QApplication::translate("CUartCfg", "\346\225\260\345\255\227\351\207\217\346\250\241\345\235\227\351\205\215\347\275\256", nullptr));
        labelCfgChannel->setText(QApplication::translate("CUartCfg", "\351\205\215\347\275\256\351\200\232\351\201\223\357\274\232", nullptr));
        combCfgChannel->setItemText(0, QApplication::translate("CUartCfg", "\347\254\2541\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(1, QApplication::translate("CUartCfg", "\347\254\2542\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(2, QApplication::translate("CUartCfg", "\347\254\2543\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(3, QApplication::translate("CUartCfg", "\347\254\2544\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(4, QApplication::translate("CUartCfg", "\347\254\2545\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(5, QApplication::translate("CUartCfg", "\347\254\2546\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(6, QApplication::translate("CUartCfg", "\347\254\2547\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));
        combCfgChannel->setItemText(7, QApplication::translate("CUartCfg", "\347\254\2548\350\267\257\345\270\247\346\240\274\345\274\217", nullptr));

        btnCfgApplyToAll->setText(QApplication::translate("CUartCfg", "\345\272\224\347\224\250\345\210\260\346\211\200\346\234\211", nullptr));
        btnOpen->setText(QApplication::translate("CUartCfg", "\346\211\223\345\274\200", nullptr));
        btnSaveAs->setText(QApplication::translate("CUartCfg", "\345\217\246\345\255\230\344\270\272", nullptr));
        btnSave->setText(QApplication::translate("CUartCfg", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QApplication::translate("CUartCfg", "\345\217\226\346\266\210", nullptr));
        labelCfgChannel_2->setText(QApplication::translate("CUartCfg", "\346\225\260\345\255\227\351\207\217\346\216\245\345\217\243\347\261\273\345\236\213\357\274\232", nullptr));
        labelCfgChannel_3->setText(QApplication::translate("CUartCfg", "\346\216\245\345\217\243\345\267\245\344\275\234\346\250\241\345\274\217\357\274\232", nullptr));
        labelCfgChannel_5->setText(QApplication::translate("CUartCfg", "\346\216\245\345\217\243\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        labelCfgChannel_8->setText(QApplication::translate("CUartCfg", "\346\216\245\345\217\243\346\240\241\351\252\214\347\261\273\345\236\213\357\274\232", nullptr));
        labelCfgChannel_9->setText(QApplication::translate("CUartCfg", "\346\216\245\345\217\243\345\201\234\346\255\242\344\275\215\351\225\277\357\274\232", nullptr));
        label->setText(QString());
        combInterfaceType->setItemText(0, QApplication::translate("CUartCfg", "\345\267\256\345\210\206\345\217\221\351\200\201/\345\267\256\345\210\206\346\216\245\346\224\266", nullptr));
        combInterfaceType->setItemText(1, QApplication::translate("CUartCfg", "\345\267\256\345\210\206\345\217\221\351\200\201/\345\205\211\350\200\246\346\216\245\346\224\266", nullptr));

        combWorkMode->setItemText(0, QApplication::translate("CUartCfg", "\350\204\211\345\206\262\345\223\215\345\272\224\345\217\221\351\200\201\346\250\241\345\274\217", nullptr));
        combWorkMode->setItemText(1, QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\223\215\345\272\224\345\217\221\351\200\201\346\250\241\345\274\217", nullptr));
        combWorkMode->setItemText(2, QApplication::translate("CUartCfg", "\345\221\250\346\234\237\345\217\221\351\200\201\346\250\241\345\274\217", nullptr));
        combWorkMode->setItemText(3, QApplication::translate("CUartCfg", "\350\204\211\345\206\262\345\217\226\346\225\260\346\250\241\345\274\217", nullptr));
        combWorkMode->setItemText(4, QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\217\226\346\225\260\346\250\241\345\274\217", nullptr));
        combWorkMode->setItemText(5, QApplication::translate("CUartCfg", "\350\242\253\345\212\250\346\216\245\346\224\266\345\267\245\344\275\234\346\250\241\345\274\217", nullptr));
        combWorkMode->setItemText(6, QApplication::translate("CUartCfg", "\344\270\215\345\267\245\344\275\234", nullptr));

        combBaudRate->setItemText(0, QApplication::translate("CUartCfg", "921.6 kbs", nullptr));
        combBaudRate->setItemText(1, QApplication::translate("CUartCfg", "460.8 kbs", nullptr));
        combBaudRate->setItemText(2, QApplication::translate("CUartCfg", "230.4 kbs", nullptr));
        combBaudRate->setItemText(3, QApplication::translate("CUartCfg", "115.2 kbs", nullptr));

        combCheckType->setItemText(0, QApplication::translate("CUartCfg", "\346\227\240\346\240\241\351\252\214", nullptr));
        combCheckType->setItemText(1, QApplication::translate("CUartCfg", "\345\245\207\346\240\241\351\252\214", nullptr));
        combCheckType->setItemText(2, QApplication::translate("CUartCfg", "\345\201\266\346\240\241\351\252\214", nullptr));

        combStopBitLen->setItemText(0, QApplication::translate("CUartCfg", "1 \344\275\215", nullptr));
        combStopBitLen->setItemText(1, QApplication::translate("CUartCfg", "1.5 \344\275\215", nullptr));
        combStopBitLen->setItemText(2, QApplication::translate("CUartCfg", "2 \344\275\215", nullptr));

        radioDoubleRedundancy->setText(QApplication::translate("CUartCfg", "\345\217\214\345\206\227\344\275\231\347\203\255\345\244\207\344\273\275", nullptr));
        labelCfgChannel_7->setText(QApplication::translate("CUartCfg", "\345\217\221\351\200\201\346\225\260\346\215\256\351\225\277\345\272\246\357\274\232", nullptr));
        labelCfgChannel_6->setText(QApplication::translate("CUartCfg", "\345\270\247\350\256\241\346\225\260\344\275\215\347\275\256\357\274\232", nullptr));
        labelCfgChannel_11->setText(QApplication::translate("CUartCfg", "\346\225\260\345\255\227\351\207\217\344\277\241\346\201\257\347\261\273\345\236\213\357\274\232", nullptr));
        pushDigitalEditor->setText(QApplication::translate("CUartCfg", "\347\274\226\350\276\221", nullptr));
        labelCfgChannel_12->setText(QApplication::translate("CUartCfg", "\345\217\226\346\225\260\350\204\211\345\206\262\345\275\242\345\274\217\357\274\232", nullptr));
        comboPauseType->setItemText(0, QApplication::translate("CUartCfg", "\346\255\243\350\204\211\345\206\262", nullptr));
        comboPauseType->setItemText(1, QApplication::translate("CUartCfg", "\350\264\237\350\204\211\345\206\262", nullptr));

        labelCfgChannel_13->setText(QApplication::translate("CUartCfg", "\345\217\226\346\225\260\350\204\211\345\206\262\345\256\275\345\272\246\357\274\232", nullptr));
        spinPauseWidth->setSuffix(QApplication::translate("CUartCfg", "\316\274s", nullptr));
        labelCfgChannel_14->setText(QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\270\247\345\270\247\345\244\264\344\277\241\346\201\257\357\274\232", nullptr));
        lineCMDHeaderFormat->setText(QApplication::translate("CUartCfg", "00000000", nullptr));
        labelCfgChannel_15->setText(QApplication::translate("CUartCfg", "\346\225\260\345\255\227\351\207\217\350\276\223\345\207\272\345\221\250\346\234\237\357\274\232", nullptr));
        spinDigitOutPer->setSuffix(QApplication::translate("CUartCfg", "ms", nullptr));
        labelCfgChannel_16->setText(QApplication::translate("CUartCfg", "\345\217\226\346\225\260\350\204\211\345\206\262\350\276\223\345\207\272\351\227\264\351\232\224\357\274\232", nullptr));
        spinPauseOutPer->setSuffix(QApplication::translate("CUartCfg", "ms", nullptr));
        spinPauseOutPer->setPrefix(QString());
        labelCfgChannel_17->setText(QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\270\247\346\227\266\351\227\264\351\227\264\351\232\224\357\274\232", nullptr));
        spinCmdOutPer->setSuffix(QApplication::translate("CUartCfg", "ms", nullptr));
        labelCfgChannel_18->setText(QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\270\247\345\217\221\351\200\201\346\254\241\346\225\260\357\274\232", nullptr));
        labelCfgChannel_19->setText(QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\270\2471\344\277\241\346\201\257\357\274\232", nullptr));
        pushCmdEditor1->setText(QApplication::translate("CUartCfg", "\347\274\226\350\276\221", nullptr));
        labelCfgChannel_20->setText(QApplication::translate("CUartCfg", "\345\221\275\344\273\244\345\270\2472\344\277\241\346\201\257\357\274\232", nullptr));
        pushCmdEditor2->setText(QApplication::translate("CUartCfg", "\347\274\226\350\276\221", nullptr));
        labelCfgChannel_21->setText(QApplication::translate("CUartCfg", "\346\216\245\346\224\266\346\225\260\346\215\256\351\225\277\345\272\246\357\274\232", nullptr));
        labelCfgChannel_10->setText(QApplication::translate("CUartCfg", "\345\217\226\346\225\260\350\204\211\345\206\262\345\217\221\351\200\201\346\254\241\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CUartCfg: public Ui_CUartCfg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUARTCFG_H

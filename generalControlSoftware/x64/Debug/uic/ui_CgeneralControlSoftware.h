/********************************************************************************
** Form generated from reading UI file 'CgeneralControlSoftware.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGENERALCONTROLSOFTWARE_H
#define UI_CGENERALCONTROLSOFTWARE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CgeneralControlSoftwareClass
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_27;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_23;
    QTabWidget *tabWidget;
    QWidget *tabMainWindow;
    QGroupBox *groupBox;
    QPushButton *BtnNoElecCtlCfg;
    QPushButton *BtnNoElecCtlOpen;
    QPushButton *BtnNoElecCtlClose;
    QGroupBox *groupBox_2;
    QPushButton *BtnElecCtlCfg;
    QPushButton *BtnElecCtlOpen;
    QPushButton *BtnElecCtlClose;
    QGroupBox *groupBox_3;
    QPushButton *BtnUartCtlCfg;
    QPushButton *BtnUartCtlOpen;
    QPushButton *BtnUartCtlClose;
    QPushButton *BtnUartCtlShowData;
    QPushButton *BtnUartCtlSaveData;
    QGroupBox *groupBox_4;
    QPushButton *BtnActiveSignalCfg;
    QPushButton *BtnActiveSignalOpen;
    QPushButton *BtnActiveSignalClose;
    QLabel *label_4;
    QPushButton *BtnSelfCheck;
    QWidget *tabAutoTestWindow;
    QTabWidget *tabWidget_2;
    QWidget *timelyCmp;
    QWidget *widget_4;
    QGroupBox *groupBox_8;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_24;
    QPushButton *pushButton_27;
    QGroupBox *groupBox_9;
    QTableWidget *tableWidget_3;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QPushButton *btnTimelyLoadRule;
    QPushButton *btnTimelyStartCmp;
    QPushButton *btnTimelyEndCmp;
    QPushButton *btnTimelyResultDir;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinbtnTimelyDataFreshTime;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *spinbtnTimelyCircleLastTime;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *spinbtnTimelyIntervalTime;
    QGroupBox *groupBoxCmpTip;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_2;
    QComboBox *combFileSelect;
    QPushButton *btnFileSelect;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *spinFrameSelect;
    QPushButton *btnDataPlayback;
    QWidget *fileCmp;
    QTableWidget *tableFileCmpLogWindow;
    QTableWidget *tablebtnFileCmpDataShow;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnFileCmpLoadRule;
    QPushButton *btnFileCmpStartCmp;
    QPushButton *btnFileCmpEndCmp;
    QPushButton *btnFileCmpSetRule;
    QPushButton *btnFileSaveLog;
    QPushButton *btnFileCmpClearLog;
    QWidget *widget_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CgeneralControlSoftwareClass)
    {
        if (CgeneralControlSoftwareClass->objectName().isEmpty())
            CgeneralControlSoftwareClass->setObjectName(QString::fromUtf8("CgeneralControlSoftwareClass"));
        CgeneralControlSoftwareClass->resize(1495, 856);
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        CgeneralControlSoftwareClass->setWindowIcon(icon);
        centralwidget = new QWidget(CgeneralControlSoftwareClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_22 = new QHBoxLayout(centralwidget);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setSpacing(0);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(83, 125, 179, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0.011, stop:0.305085 rgba(151, 142, 248, 255), stop:1 rgba(0, 199, 255, 250));}"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(80, 60));
        widget_2->setMaximumSize(QSize(80, 60));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/\346\226\260\345\211\215\347\274\200/img/logo.png);"));

        horizontalLayout_2->addWidget(widget_2);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(198, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout_27->addWidget(widget);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font2;
        font2.setPointSize(12);
        tabWidget->setFont(font2);
        tabWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(250, 250, 250);\n"
""));
        tabMainWindow = new QWidget();
        tabMainWindow->setObjectName(QString::fromUtf8("tabMainWindow"));
        groupBox = new QGroupBox(tabMainWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(300, 200, 261, 121));
        QFont font3;
        font3.setPointSize(11);
        groupBox->setFont(font3);
        groupBox->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        BtnNoElecCtlCfg = new QPushButton(groupBox);
        BtnNoElecCtlCfg->setObjectName(QString::fromUtf8("BtnNoElecCtlCfg"));
        BtnNoElecCtlCfg->setGeometry(QRect(30, 80, 201, 28));
        BtnNoElecCtlCfg->setFont(font3);
        BtnNoElecCtlOpen = new QPushButton(groupBox);
        BtnNoElecCtlOpen->setObjectName(QString::fromUtf8("BtnNoElecCtlOpen"));
        BtnNoElecCtlOpen->setGeometry(QRect(30, 20, 201, 28));
        BtnNoElecCtlOpen->setFont(font3);
        BtnNoElecCtlClose = new QPushButton(groupBox);
        BtnNoElecCtlClose->setObjectName(QString::fromUtf8("BtnNoElecCtlClose"));
        BtnNoElecCtlClose->setGeometry(QRect(30, 50, 201, 28));
        BtnNoElecCtlClose->setFont(font3);
        groupBox_2 = new QGroupBox(tabMainWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 200, 261, 121));
        groupBox_2->setFont(font3);
        groupBox_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        BtnElecCtlCfg = new QPushButton(groupBox_2);
        BtnElecCtlCfg->setObjectName(QString::fromUtf8("BtnElecCtlCfg"));
        BtnElecCtlCfg->setGeometry(QRect(30, 80, 201, 28));
        BtnElecCtlCfg->setFont(font3);
        BtnElecCtlOpen = new QPushButton(groupBox_2);
        BtnElecCtlOpen->setObjectName(QString::fromUtf8("BtnElecCtlOpen"));
        BtnElecCtlOpen->setGeometry(QRect(30, 20, 201, 28));
        BtnElecCtlOpen->setFont(font3);
        BtnElecCtlClose = new QPushButton(groupBox_2);
        BtnElecCtlClose->setObjectName(QString::fromUtf8("BtnElecCtlClose"));
        BtnElecCtlClose->setGeometry(QRect(30, 50, 201, 28));
        BtnElecCtlClose->setFont(font3);
        groupBox_3 = new QGroupBox(tabMainWindow);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 360, 261, 201));
        groupBox_3->setFont(font3);
        groupBox_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        BtnUartCtlCfg = new QPushButton(groupBox_3);
        BtnUartCtlCfg->setObjectName(QString::fromUtf8("BtnUartCtlCfg"));
        BtnUartCtlCfg->setGeometry(QRect(30, 80, 201, 28));
        BtnUartCtlCfg->setFont(font3);
        BtnUartCtlOpen = new QPushButton(groupBox_3);
        BtnUartCtlOpen->setObjectName(QString::fromUtf8("BtnUartCtlOpen"));
        BtnUartCtlOpen->setGeometry(QRect(30, 20, 201, 28));
        BtnUartCtlOpen->setFont(font3);
        BtnUartCtlClose = new QPushButton(groupBox_3);
        BtnUartCtlClose->setObjectName(QString::fromUtf8("BtnUartCtlClose"));
        BtnUartCtlClose->setGeometry(QRect(30, 50, 201, 28));
        BtnUartCtlClose->setFont(font3);
        BtnUartCtlShowData = new QPushButton(groupBox_3);
        BtnUartCtlShowData->setObjectName(QString::fromUtf8("BtnUartCtlShowData"));
        BtnUartCtlShowData->setGeometry(QRect(30, 110, 201, 28));
        BtnUartCtlShowData->setFont(font3);
        BtnUartCtlSaveData = new QPushButton(groupBox_3);
        BtnUartCtlSaveData->setObjectName(QString::fromUtf8("BtnUartCtlSaveData"));
        BtnUartCtlSaveData->setGeometry(QRect(30, 140, 201, 28));
        BtnUartCtlSaveData->setFont(font3);
        groupBox_4 = new QGroupBox(tabMainWindow);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 40, 391, 121));
        groupBox_4->setFont(font3);
        groupBox_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        BtnActiveSignalCfg = new QPushButton(groupBox_4);
        BtnActiveSignalCfg->setObjectName(QString::fromUtf8("BtnActiveSignalCfg"));
        BtnActiveSignalCfg->setGeometry(QRect(30, 80, 201, 28));
        BtnActiveSignalCfg->setFont(font3);
        BtnActiveSignalOpen = new QPushButton(groupBox_4);
        BtnActiveSignalOpen->setObjectName(QString::fromUtf8("BtnActiveSignalOpen"));
        BtnActiveSignalOpen->setGeometry(QRect(30, 20, 201, 28));
        BtnActiveSignalOpen->setFont(font3);
        BtnActiveSignalOpen->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(200, 200, 200);\n"
"}\n"
"\n"
" QPushButton:pressed\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        BtnActiveSignalClose = new QPushButton(groupBox_4);
        BtnActiveSignalClose->setObjectName(QString::fromUtf8("BtnActiveSignalClose"));
        BtnActiveSignalClose->setGeometry(QRect(30, 50, 201, 28));
        BtnActiveSignalClose->setFont(font3);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 70, 72, 15));
        BtnSelfCheck = new QPushButton(tabMainWindow);
        BtnSelfCheck->setObjectName(QString::fromUtf8("BtnSelfCheck"));
        BtnSelfCheck->setGeometry(QRect(540, 90, 93, 28));
        tabWidget->addTab(tabMainWindow, QString());
        tabAutoTestWindow = new QWidget();
        tabAutoTestWindow->setObjectName(QString::fromUtf8("tabAutoTestWindow"));
        tabWidget_2 = new QTabWidget(tabAutoTestWindow);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 10, 1051, 641));
        tabWidget_2->setFont(font2);
        timelyCmp = new QWidget();
        timelyCmp->setObjectName(QString::fromUtf8("timelyCmp"));
        widget_4 = new QWidget(timelyCmp);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(290, 10, 741, 511));
        groupBox_8 = new QGroupBox(widget_4);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 10, 361, 261));
        tableWidget_2 = new QTableWidget(groupBox_8);
        if (tableWidget_2->columnCount() < 10)
            tableWidget_2->setColumnCount(10);
        if (tableWidget_2->rowCount() < 10)
            tableWidget_2->setRowCount(10);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 20, 256, 192));
        tableWidget_2->setRowCount(10);
        tableWidget_2->setColumnCount(10);
        pushButton_24 = new QPushButton(groupBox_8);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setGeometry(QRect(280, 30, 61, 28));
        pushButton_27 = new QPushButton(groupBox_8);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        pushButton_27->setGeometry(QRect(280, 70, 61, 28));
        groupBox_9 = new QGroupBox(widget_4);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(390, 20, 351, 251));
        tableWidget_3 = new QTableWidget(groupBox_9);
        if (tableWidget_3->columnCount() < 10)
            tableWidget_3->setColumnCount(10);
        if (tableWidget_3->rowCount() < 10)
            tableWidget_3->setRowCount(10);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(10, 20, 256, 192));
        tableWidget_3->setRowCount(10);
        tableWidget_3->setColumnCount(10);
        pushButton_28 = new QPushButton(groupBox_9);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
        pushButton_28->setGeometry(QRect(280, 30, 61, 28));
        pushButton_29 = new QPushButton(groupBox_9);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setGeometry(QRect(280, 70, 61, 28));
        layoutWidget = new QWidget(timelyCmp);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 261, 561));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_5 = new QGroupBox(layoutWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setFont(font3);
        groupBox_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnTimelyLoadRule = new QPushButton(groupBox_5);
        btnTimelyLoadRule->setObjectName(QString::fromUtf8("btnTimelyLoadRule"));
        btnTimelyLoadRule->setMinimumSize(QSize(0, 28));
        btnTimelyLoadRule->setFont(font3);

        verticalLayout->addWidget(btnTimelyLoadRule);

        btnTimelyStartCmp = new QPushButton(groupBox_5);
        btnTimelyStartCmp->setObjectName(QString::fromUtf8("btnTimelyStartCmp"));
        btnTimelyStartCmp->setMinimumSize(QSize(0, 28));
        btnTimelyStartCmp->setFont(font3);

        verticalLayout->addWidget(btnTimelyStartCmp);

        btnTimelyEndCmp = new QPushButton(groupBox_5);
        btnTimelyEndCmp->setObjectName(QString::fromUtf8("btnTimelyEndCmp"));
        btnTimelyEndCmp->setMinimumSize(QSize(0, 28));
        btnTimelyEndCmp->setFont(font3);

        verticalLayout->addWidget(btnTimelyEndCmp);

        btnTimelyResultDir = new QPushButton(groupBox_5);
        btnTimelyResultDir->setObjectName(QString::fromUtf8("btnTimelyResultDir"));
        btnTimelyResultDir->setMinimumSize(QSize(0, 28));
        btnTimelyResultDir->setFont(font3);

        verticalLayout->addWidget(btnTimelyResultDir);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font3);

        horizontalLayout_3->addWidget(label_3);

        spinbtnTimelyDataFreshTime = new QSpinBox(groupBox_5);
        spinbtnTimelyDataFreshTime->setObjectName(QString::fromUtf8("spinbtnTimelyDataFreshTime"));
        spinbtnTimelyDataFreshTime->setValue(50);

        horizontalLayout_3->addWidget(spinbtnTimelyDataFreshTime);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font3);

        horizontalLayout_5->addWidget(label_5);

        spinbtnTimelyCircleLastTime = new QSpinBox(groupBox_5);
        spinbtnTimelyCircleLastTime->setObjectName(QString::fromUtf8("spinbtnTimelyCircleLastTime"));
        spinbtnTimelyCircleLastTime->setValue(60);

        horizontalLayout_5->addWidget(spinbtnTimelyCircleLastTime);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font3);

        horizontalLayout_7->addWidget(label_7);

        spinbtnTimelyIntervalTime = new QSpinBox(groupBox_5);
        spinbtnTimelyIntervalTime->setObjectName(QString::fromUtf8("spinbtnTimelyIntervalTime"));
        spinbtnTimelyIntervalTime->setMaximum(500000);
        spinbtnTimelyIntervalTime->setValue(2000);

        horizontalLayout_7->addWidget(spinbtnTimelyIntervalTime);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupBox_5);

        groupBoxCmpTip = new QGroupBox(layoutWidget);
        groupBoxCmpTip->setObjectName(QString::fromUtf8("groupBoxCmpTip"));
        groupBoxCmpTip->setMinimumSize(QSize(0, 100));
        groupBoxCmpTip->setFont(font3);

        verticalLayout_3->addWidget(groupBoxCmpTip);

        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setFont(font3);
        groupBox_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        verticalLayout_2 = new QVBoxLayout(groupBox_6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        combFileSelect = new QComboBox(groupBox_6);
        combFileSelect->setObjectName(QString::fromUtf8("combFileSelect"));
        combFileSelect->setMinimumSize(QSize(0, 28));

        verticalLayout_2->addWidget(combFileSelect);

        btnFileSelect = new QPushButton(groupBox_6);
        btnFileSelect->setObjectName(QString::fromUtf8("btnFileSelect"));
        btnFileSelect->setMinimumSize(QSize(0, 28));
        btnFileSelect->setFont(font3);

        verticalLayout_2->addWidget(btnFileSelect);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);

        horizontalLayout_8->addWidget(label_8);

        spinFrameSelect = new QSpinBox(groupBox_6);
        spinFrameSelect->setObjectName(QString::fromUtf8("spinFrameSelect"));
        spinFrameSelect->setMinimumSize(QSize(0, 28));
        spinFrameSelect->setMaximum(100000);
        spinFrameSelect->setValue(1);

        horizontalLayout_8->addWidget(spinFrameSelect);


        verticalLayout_2->addLayout(horizontalLayout_8);

        btnDataPlayback = new QPushButton(groupBox_6);
        btnDataPlayback->setObjectName(QString::fromUtf8("btnDataPlayback"));
        btnDataPlayback->setMinimumSize(QSize(0, 28));
        btnDataPlayback->setFont(font3);

        verticalLayout_2->addWidget(btnDataPlayback);


        verticalLayout_3->addWidget(groupBox_6);

        tabWidget_2->addTab(timelyCmp, QString());
        fileCmp = new QWidget();
        fileCmp->setObjectName(QString::fromUtf8("fileCmp"));
        tableFileCmpLogWindow = new QTableWidget(fileCmp);
        if (tableFileCmpLogWindow->columnCount() < 2)
            tableFileCmpLogWindow->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableFileCmpLogWindow->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableFileCmpLogWindow->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableFileCmpLogWindow->setObjectName(QString::fromUtf8("tableFileCmpLogWindow"));
        tableFileCmpLogWindow->setGeometry(QRect(260, 40, 701, 221));
        tablebtnFileCmpDataShow = new QTableWidget(fileCmp);
        if (tablebtnFileCmpDataShow->columnCount() < 10)
            tablebtnFileCmpDataShow->setColumnCount(10);
        if (tablebtnFileCmpDataShow->rowCount() < 10)
            tablebtnFileCmpDataShow->setRowCount(10);
        tablebtnFileCmpDataShow->setObjectName(QString::fromUtf8("tablebtnFileCmpDataShow"));
        tablebtnFileCmpDataShow->setGeometry(QRect(20, 300, 941, 221));
        tablebtnFileCmpDataShow->setRowCount(10);
        tablebtnFileCmpDataShow->setColumnCount(10);
        groupBox_12 = new QGroupBox(fileCmp);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(11, 11, 221, 245));
        groupBox_12->setFont(font3);
        groupBox_12->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	\n"
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
"}"));
        verticalLayout_4 = new QVBoxLayout(groupBox_12);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnFileCmpLoadRule = new QPushButton(groupBox_12);
        btnFileCmpLoadRule->setObjectName(QString::fromUtf8("btnFileCmpLoadRule"));
        btnFileCmpLoadRule->setMinimumSize(QSize(0, 28));
        btnFileCmpLoadRule->setFont(font3);

        verticalLayout_4->addWidget(btnFileCmpLoadRule);

        btnFileCmpStartCmp = new QPushButton(groupBox_12);
        btnFileCmpStartCmp->setObjectName(QString::fromUtf8("btnFileCmpStartCmp"));
        btnFileCmpStartCmp->setMinimumSize(QSize(0, 28));
        btnFileCmpStartCmp->setFont(font3);

        verticalLayout_4->addWidget(btnFileCmpStartCmp);

        btnFileCmpEndCmp = new QPushButton(groupBox_12);
        btnFileCmpEndCmp->setObjectName(QString::fromUtf8("btnFileCmpEndCmp"));
        btnFileCmpEndCmp->setMinimumSize(QSize(0, 28));
        btnFileCmpEndCmp->setFont(font3);

        verticalLayout_4->addWidget(btnFileCmpEndCmp);

        btnFileCmpSetRule = new QPushButton(groupBox_12);
        btnFileCmpSetRule->setObjectName(QString::fromUtf8("btnFileCmpSetRule"));
        btnFileCmpSetRule->setMinimumSize(QSize(0, 28));
        btnFileCmpSetRule->setFont(font3);

        verticalLayout_4->addWidget(btnFileCmpSetRule);

        btnFileSaveLog = new QPushButton(groupBox_12);
        btnFileSaveLog->setObjectName(QString::fromUtf8("btnFileSaveLog"));
        btnFileSaveLog->setMinimumSize(QSize(0, 28));
        btnFileSaveLog->setFont(font3);

        verticalLayout_4->addWidget(btnFileSaveLog);

        btnFileCmpClearLog = new QPushButton(groupBox_12);
        btnFileCmpClearLog->setObjectName(QString::fromUtf8("btnFileCmpClearLog"));
        btnFileCmpClearLog->setMinimumSize(QSize(0, 28));
        btnFileCmpClearLog->setFont(font3);

        verticalLayout_4->addWidget(btnFileCmpClearLog);

        tabWidget_2->addTab(fileCmp, QString());
        widget_3 = new QWidget(tabAutoTestWindow);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(1056, 11, 16, 632));
        tabWidget->addTab(tabAutoTestWindow, QString());

        horizontalLayout_23->addWidget(tabWidget);


        verticalLayout_27->addLayout(horizontalLayout_23);

        verticalLayout_27->setStretch(0, 2);
        verticalLayout_27->setStretch(1, 15);

        horizontalLayout_22->addLayout(verticalLayout_27);

        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 246, 235);"));
        verticalLayout_5 = new QVBoxLayout(widget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(widget_5);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFont(font2);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);

        verticalLayout_5->addWidget(tableWidget);


        horizontalLayout_22->addWidget(widget_5);

        horizontalLayout_22->setStretch(0, 7);
        horizontalLayout_22->setStretch(1, 2);
        CgeneralControlSoftwareClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CgeneralControlSoftwareClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1495, 26));
        CgeneralControlSoftwareClass->setMenuBar(menubar);
        statusbar = new QStatusBar(CgeneralControlSoftwareClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CgeneralControlSoftwareClass->setStatusBar(statusbar);

        retranslateUi(CgeneralControlSoftwareClass);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CgeneralControlSoftwareClass);
    } // setupUi

    void retranslateUi(QMainWindow *CgeneralControlSoftwareClass)
    {
        CgeneralControlSoftwareClass->setWindowTitle(QApplication::translate("CgeneralControlSoftwareClass", "\345\234\260\351\235\242\351\200\232\347\224\250\347\273\274\346\216\247\345\217\260\350\275\257\344\273\266", nullptr));
        label->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\234\260\351\235\242\351\200\232\347\224\250\347\273\274\346\216\247\345\217\260\350\275\257\344\273\266", nullptr));
        label_2->setText(QApplication::translate("CgeneralControlSoftwareClass", "19:25:36", nullptr));
        groupBox->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\351\235\236\347\224\265\351\207\217\346\216\247\345\210\266", nullptr));
        BtnNoElecCtlCfg->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\205\215\347\275\256", nullptr));
        BtnNoElecCtlOpen->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\220\257", nullptr));
        BtnNoElecCtlClose->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\205\263\351\227\255", nullptr));
        groupBox_2->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\347\224\265\351\207\217\346\216\247\345\210\266", nullptr));
        BtnElecCtlCfg->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\205\215\347\275\256", nullptr));
        BtnElecCtlOpen->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\220\257", nullptr));
        BtnElecCtlClose->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\205\263\351\227\255", nullptr));
        groupBox_3->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "RS422\346\216\247\345\210\266", nullptr));
        BtnUartCtlCfg->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\205\215\347\275\256", nullptr));
        BtnUartCtlOpen->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\220\257", nullptr));
        BtnUartCtlClose->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\205\263\351\227\255", nullptr));
        BtnUartCtlShowData->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        BtnUartCtlSaveData->setText(QApplication::translate("CgeneralControlSoftwareClass", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        groupBox_4->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\277\200\346\264\273\344\277\241\345\217\267", nullptr));
        BtnActiveSignalCfg->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\205\215\347\275\256", nullptr));
        BtnActiveSignalOpen->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\220\257", nullptr));
        BtnActiveSignalClose->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\205\263\351\227\255", nullptr));
        label_4->setText(QApplication::translate("CgeneralControlSoftwareClass", "TextLabel", nullptr));
        BtnSelfCheck->setText(QApplication::translate("CgeneralControlSoftwareClass", "\350\207\252\346\243\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMainWindow), QApplication::translate("CgeneralControlSoftwareClass", "\344\270\273\347\225\214\351\235\242", nullptr));
        groupBox_8->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\225\260\346\215\256\346\272\2201", nullptr));
        pushButton_24->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\205\215\347\275\256", nullptr));
        pushButton_27->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\230\276\345\233\276", nullptr));
        groupBox_9->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\225\260\346\215\256\346\272\2202", nullptr));
        pushButton_28->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\205\215\347\275\256", nullptr));
        pushButton_29->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\230\276\345\233\276", nullptr));
        groupBox_5->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\223\215\344\275\234\345\214\272", nullptr));
        btnTimelyLoadRule->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\212\240\350\275\275\350\247\204\345\210\231", nullptr));
        btnTimelyStartCmp->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\247\213\346\257\224\345\257\271", nullptr));
        btnTimelyEndCmp->setText(QApplication::translate("CgeneralControlSoftwareClass", "\347\273\223\346\235\237\346\257\224\345\257\271", nullptr));
        btnTimelyResultDir->setText(QApplication::translate("CgeneralControlSoftwareClass", "\347\273\223\346\236\234\347\233\256\345\275\225", nullptr));
        label_3->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\225\260\346\215\256\345\210\267\346\226\260\345\221\250\346\234\237\357\274\232", nullptr));
        spinbtnTimelyDataFreshTime->setSuffix(QApplication::translate("CgeneralControlSoftwareClass", " ms", nullptr));
        spinbtnTimelyDataFreshTime->setPrefix(QString());
        label_5->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\257\217\350\275\256\346\214\201\347\273\255\346\227\266\351\227\264\357\274\232", nullptr));
        spinbtnTimelyCircleLastTime->setSuffix(QApplication::translate("CgeneralControlSoftwareClass", " s", nullptr));
        spinbtnTimelyCircleLastTime->setPrefix(QString());
        label_7->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\257\217\350\275\256\351\227\264\351\232\224\346\227\266\351\227\264\357\274\232", nullptr));
        spinbtnTimelyIntervalTime->setSuffix(QApplication::translate("CgeneralControlSoftwareClass", " ms", nullptr));
        spinbtnTimelyIntervalTime->setPrefix(QString());
        groupBoxCmpTip->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\257\224\345\257\271\346\265\201\347\250\213\346\217\220\347\244\272", nullptr));
        groupBox_6->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\225\260\346\215\256\345\233\236\346\224\276", nullptr));
        btnFileSelect->setText(QApplication::translate("CgeneralControlSoftwareClass", "\351\200\211\346\213\251\345\233\236\346\224\276\346\226\207\344\273\266", nullptr));
        label_8->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\233\236\346\224\276\345\270\247\346\225\260\357\274\232", nullptr));
        spinFrameSelect->setSuffix(QApplication::translate("CgeneralControlSoftwareClass", "\345\270\247", nullptr));
        spinFrameSelect->setPrefix(QApplication::translate("CgeneralControlSoftwareClass", "\347\254\254", nullptr));
        btnDataPlayback->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\247\213\345\233\236\346\224\276", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(timelyCmp), QApplication::translate("CgeneralControlSoftwareClass", "\345\256\236\346\227\266\346\257\224\345\257\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableFileCmpLogWindow->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableFileCmpLogWindow->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CgeneralControlSoftwareClass", "\344\277\241\346\201\257", nullptr));
        groupBox_12->setTitle(QApplication::translate("CgeneralControlSoftwareClass", "\346\223\215\344\275\234\345\214\272", nullptr));
        btnFileCmpLoadRule->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\212\240\350\275\275\350\247\204\345\210\231", nullptr));
        btnFileCmpStartCmp->setText(QApplication::translate("CgeneralControlSoftwareClass", "\345\274\200\345\247\213\346\257\224\345\257\271", nullptr));
        btnFileCmpEndCmp->setText(QApplication::translate("CgeneralControlSoftwareClass", "\347\273\223\346\235\237\346\257\224\345\257\271", nullptr));
        btnFileCmpSetRule->setText(QApplication::translate("CgeneralControlSoftwareClass", "\350\256\276\347\275\256\350\247\204\345\210\231", nullptr));
        btnFileSaveLog->setText(QApplication::translate("CgeneralControlSoftwareClass", "\344\277\235\345\255\230\346\227\245\345\277\227", nullptr));
        btnFileCmpClearLog->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\270\205\347\251\272\346\227\245\345\277\227", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(fileCmp), QApplication::translate("CgeneralControlSoftwareClass", "\346\226\207\344\273\266\346\257\224\345\257\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAutoTestWindow), QApplication::translate("CgeneralControlSoftwareClass", "\350\207\252\345\212\250\345\214\226\346\265\213\350\257\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("CgeneralControlSoftwareClass", "\346\227\245\345\277\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CgeneralControlSoftwareClass: public Ui_CgeneralControlSoftwareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGENERALCONTROLSOFTWARE_H

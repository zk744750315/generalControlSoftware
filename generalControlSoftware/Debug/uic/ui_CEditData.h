/********************************************************************************
** Form generated from reading UI file 'CEditData.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CEDITDATA_H
#define UI_CEDITDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CEditData
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinRow;
    QLabel *label_2;
    QSpinBox *spinCol;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioAddOne;
    QRadioButton *radioSubOne;
    QRadioButton *radioBConstant;
    QSpinBox *spinConstant;
    QRadioButton *radioReadFile;
    QTableWidget *tableWidget;

    void setupUi(QWidget *CEditData)
    {
        if (CEditData->objectName().isEmpty())
            CEditData->setObjectName(QString::fromUtf8("CEditData"));
        CEditData->resize(883, 513);
        CEditData->setStyleSheet(QString::fromUtf8("QWidget{\n"
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
        verticalLayout = new QVBoxLayout(CEditData);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CEditData);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("SimSun"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        spinRow = new QSpinBox(CEditData);
        spinRow->setObjectName(QString::fromUtf8("spinRow"));
        spinRow->setReadOnly(true);

        horizontalLayout->addWidget(spinRow);

        label_2 = new QLabel(CEditData);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        spinCol = new QSpinBox(CEditData);
        spinCol->setObjectName(QString::fromUtf8("spinCol"));
        spinCol->setReadOnly(true);

        horizontalLayout->addWidget(spinCol);

        pushButton = new QPushButton(CEditData);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(70, 25));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioAddOne = new QRadioButton(CEditData);
        radioAddOne->setObjectName(QString::fromUtf8("radioAddOne"));
        radioAddOne->setChecked(true);

        horizontalLayout->addWidget(radioAddOne);

        radioSubOne = new QRadioButton(CEditData);
        radioSubOne->setObjectName(QString::fromUtf8("radioSubOne"));

        horizontalLayout->addWidget(radioSubOne);

        radioBConstant = new QRadioButton(CEditData);
        radioBConstant->setObjectName(QString::fromUtf8("radioBConstant"));

        horizontalLayout->addWidget(radioBConstant);

        spinConstant = new QSpinBox(CEditData);
        spinConstant->setObjectName(QString::fromUtf8("spinConstant"));
        spinConstant->setMaximum(255);
        spinConstant->setDisplayIntegerBase(16);

        horizontalLayout->addWidget(spinConstant);

        radioReadFile = new QRadioButton(CEditData);
        radioReadFile->setObjectName(QString::fromUtf8("radioReadFile"));

        horizontalLayout->addWidget(radioReadFile);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(CEditData);
        if (tableWidget->columnCount() < 16)
            tableWidget->setColumnCount(16);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem16);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->horizontalHeader()->setDefaultSectionSize(45);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(CEditData);

        QMetaObject::connectSlotsByName(CEditData);
    } // setupUi

    void retranslateUi(QWidget *CEditData)
    {
        CEditData->setWindowTitle(QApplication::translate("CEditData", "\346\225\260\346\215\256", nullptr));
        label->setText(QApplication::translate("CEditData", "\350\241\214", nullptr));
        label_2->setText(QApplication::translate("CEditData", "\345\210\227", nullptr));
        pushButton->setText(QApplication::translate("CEditData", "\351\225\277\345\272\246", nullptr));
        radioAddOne->setText(QApplication::translate("CEditData", "\345\242\236\344\270\200\347\240\201", nullptr));
        radioSubOne->setText(QApplication::translate("CEditData", "\345\207\217\344\270\200\347\240\201", nullptr));
        radioBConstant->setText(QApplication::translate("CEditData", "\345\270\270\346\225\260", nullptr));
        radioReadFile->setText(QApplication::translate("CEditData", "\350\257\273\345\217\226\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CEditData", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CEditData", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CEditData", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CEditData", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CEditData", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CEditData", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("CEditData", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("CEditData", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("CEditData", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("CEditData", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("CEditData", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("CEditData", "12", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("CEditData", "13", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("CEditData", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("CEditData", "15", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("CEditData", "16", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("CEditData", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CEditData: public Ui_CEditData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CEDITDATA_H

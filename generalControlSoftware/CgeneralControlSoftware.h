#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CgeneralControlSoftware.h"
#include "Cconfig.h"
#include<QMessageBox>
#include<QCloseEvent>

#pragma execution_character_set("utf-8") 
class CGeneralControlSoftware : public QMainWindow
{
    Q_OBJECT

public:
    CGeneralControlSoftware(QWidget *parent = Q_NULLPTR);

private:
	void Init();/*��ʼ��*/
	void SignalSlotInit();/*�źŲ����ӳ�ʼ��*/
	void closeEvent(QCloseEvent *event);
	CConfig m_ocfg;

	Ui::CgeneralControlSoftwareClass ui;

private slots:
	void test();//���ԣ��Ȳ���ɾ
	void OpenActiveSignalCfg();
	void OpenNoElecSignalCfg();
	void OpenElecSignalCfg();
	void OpenUartSignalCfg();
};


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
	void Init();/*初始化*/
	void SignalSlotInit();/*信号槽连接初始化*/
	void closeEvent(QCloseEvent *event);
	CConfig m_ocfg;

	Ui::CgeneralControlSoftwareClass ui;

private slots:
	void test();//测试，先不用删
	void OpenActiveSignalCfg();
	void OpenNoElecSignalCfg();
	void OpenElecSignalCfg();
	void OpenUartSignalCfg();
};


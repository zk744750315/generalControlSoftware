#include "CgeneralControlSoftware.h"

CGeneralControlSoftware::CGeneralControlSoftware(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	/*初始化*/
	Init();
}
/*
CgeneralControlSoftware初始化
*/
void CGeneralControlSoftware::Init()
{
	SignalSlotInit();
}

void CGeneralControlSoftware::SignalSlotInit()
{

	connect(ui.BtnSelfCheck, SIGNAL(clicked()), this, SLOT(test()));
	/*有效的信号槽链接*/
	connect(ui.BtnActiveSignalCfg, SIGNAL(clicked()), this, SLOT(OpenActiveSignalCfg()));
	connect(ui.BtnNoElecCtlCfg, SIGNAL(clicked()), this, SLOT(OpenNoElecSignalCfg()));
	connect(ui.BtnElecCtlCfg, SIGNAL(clicked()), this, SLOT(OpenElecSignalCfg()));
	connect(ui.BtnUartCtlCfg, SIGNAL(clicked()), this, SLOT(OpenUartSignalCfg()));
}
void CGeneralControlSoftware::test()
{
	stActDataUnit  *p= NULL;
	p = m_ocfg.GetAvtiveSignalData();
	stElecFullData *a = NULL;
	a = m_ocfg.GetElecSignalData();
	stNoElecFullData *b = NULL; 
	b = m_ocfg.GetNoElecSignalData();
	stUartFullData *d = NULL;
	d = m_ocfg.GetUartSignalData();
	qDebug() << "2";

}

void CGeneralControlSoftware::OpenActiveSignalCfg()
{
	m_ocfg.CreateActiveSignalCfg();
}
void CGeneralControlSoftware::OpenNoElecSignalCfg()
{
	m_ocfg.CreateNoElecSignalCfg();
}
void CGeneralControlSoftware::OpenElecSignalCfg()
{
	m_ocfg.CreateElecSignalCfg();
}
void CGeneralControlSoftware::OpenUartSignalCfg()
{
	m_ocfg.CreateUartSignalCfg();
}
void CGeneralControlSoftware::closeEvent(QCloseEvent *event)
{
	int result = QMessageBox::information(this, tr("提示"),
		tr("确定要退出程序?"),
		tr("Yes"), tr("No"), 0, 1);
	switch (result)
	{
	case 0:
		event->accept();
		break;
	case 1:
		event->ignore();
		break;
	default:
		break;
		event->ignore();
	}
}
 
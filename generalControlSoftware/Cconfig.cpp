#include "Cconfig.h"

CConfig::CConfig()
{
	Init();
}
CConfig::~CConfig()
{
	/*释放数据内存*/
	if (NULL != m_pStActiveSignalData)
	{
		delete[] m_pStActiveSignalData;
		m_pStActiveSignalData = NULL;
	}
	if (NULL != m_pStNoElecData)
	{
		delete m_pStNoElecData;
		m_pStNoElecData = NULL;
	}
	if (NULL != m_pStElecData)
	{
		delete m_pStElecData;
		m_pStElecData = NULL;
	}
	/*配置对象已经设置为关闭其窗口自动释放*/ 
	if (NULL != m_oActiveCfg)
	{
		m_oActiveCfg = NULL;
	}
	if (NULL != m_oNonElecCfg)
	{
		m_oNonElecCfg = NULL;
	}
	if (NULL != m_oElecCfg)
	{
		m_oElecCfg = NULL;
	}
}

void CConfig::Init()
{
	/*各类配置对象指针初始化*/
	m_oActiveCfg = NULL;
	m_oNonElecCfg = NULL;
	m_oElecCfg = NULL;
	/*各类配置数据存储的内存指针初始化*/
	m_pStActiveSignalData = NULL;
	m_pStNoElecData = NULL;
	m_pStElecData = NULL;
	/*初始化配置信息*/
	InitCfg();
}

/*创建激活信号配置对象*/
void CConfig::CreateActiveSignalCfg()
{
	/*先为数据申请存储区，在用其指针区建立配置对象*/
	if(NULL == m_pStActiveSignalData)
		m_pStActiveSignalData = new stActDataUnit[u1ACTIVE_SIGNAL_CHANNEL_COUNT];
	m_oActiveCfg = new CActivedSignalCfg(m_pStActiveSignalData);
	m_oActiveCfg->show();
}

void CConfig::CreateNoElecSignalCfg()
{
	if (NULL == m_pStNoElecData)
		m_pStNoElecData = new noElectricCfg::stNoElecFullData;
	m_oNonElecCfg = new noElectricCfg::CNonElectricCfg(m_pStNoElecData);
	m_oNonElecCfg->show();
}

void CConfig::CreateElecSignalCfg()
{
	if (NULL == m_pStElecData)
		m_pStElecData = new stElecFullData;
	m_oElecCfg = new CElectricCfg(m_pStElecData);
	m_oElecCfg->show();
}

void CConfig::CreateUartSignalCfg()
{
	if (NULL == m_pStUartData)
		m_pStUartData = new stUartFullData;
	m_oUartCfg = new CUartCfg(m_pStUartData);
	m_oUartCfg->show();
}
/*获取激活信号的配置数据信息*/
stActDataUnit *CConfig::GetAvtiveSignalData()
{
	if (NULL != m_pStActiveSignalData)
	{
		for(int i=0;i<4;i++)
		{
			m_pStActiveSignalData++;
		}
		m_pStActiveSignalData;
		return m_pStActiveSignalData;
	}
	else
	{
		return NULL;
	}
}
stElecFullData *CConfig::GetElecSignalData()
{
	m_pStElecData;
	return m_pStElecData;
}
stNoElecFullData *CConfig::GetNoElecSignalData()
{
	m_pStNoElecData;
	return m_pStNoElecData;
}
stUartFullData *CConfig::GetUartSignalData()
{
	m_pStUartData;
	return m_pStUartData;
}
bool CConfig::InitCfg()
{
	/*获取激活信号配置信息*/
	m_pStActiveSignalData = new stActDataUnit[u1ACTIVE_SIGNAL_CHANNEL_COUNT];
	m_oActiveCfg = new CActivedSignalCfg(m_pStActiveSignalData);
	m_oActiveCfg->close();
	/*获取非电量信号配置信息*/
	m_pStNoElecData = new stNoElecFullData;
	m_oNonElecCfg = new CNonElectricCfg(m_pStNoElecData);
	m_oNonElecCfg->close();
	/*获取电量信号配置信息*/
	m_pStElecData = new stElecFullData;
	m_oElecCfg = new CElectricCfg(m_pStElecData);
	m_oElecCfg->close();
	/*获取Rs422配置信息*/
	m_pStUartData = new stUartFullData;
	m_oUartCfg = new CUartCfg(m_pStUartData);
	m_oUartCfg->close();
	return true;
}
#include "Cconfig.h"

CConfig::CConfig()
{
	Init();
}
CConfig::~CConfig()
{
	/*�ͷ������ڴ�*/
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
	/*���ö����Ѿ�����Ϊ�ر��䴰���Զ��ͷ�*/ 
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
	/*�������ö���ָ���ʼ��*/
	m_oActiveCfg = NULL;
	m_oNonElecCfg = NULL;
	m_oElecCfg = NULL;
	/*�����������ݴ洢���ڴ�ָ���ʼ��*/
	m_pStActiveSignalData = NULL;
	m_pStNoElecData = NULL;
	m_pStElecData = NULL;
	/*��ʼ��������Ϣ*/
	InitCfg();
}

/*���������ź����ö���*/
void CConfig::CreateActiveSignalCfg()
{
	/*��Ϊ��������洢����������ָ�����������ö���*/
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
/*��ȡ�����źŵ�����������Ϣ*/
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
	/*��ȡ�����ź�������Ϣ*/
	m_pStActiveSignalData = new stActDataUnit[u1ACTIVE_SIGNAL_CHANNEL_COUNT];
	m_oActiveCfg = new CActivedSignalCfg(m_pStActiveSignalData);
	m_oActiveCfg->close();
	/*��ȡ�ǵ����ź�������Ϣ*/
	m_pStNoElecData = new stNoElecFullData;
	m_oNonElecCfg = new CNonElectricCfg(m_pStNoElecData);
	m_oNonElecCfg->close();
	/*��ȡ�����ź�������Ϣ*/
	m_pStElecData = new stElecFullData;
	m_oElecCfg = new CElectricCfg(m_pStElecData);
	m_oElecCfg->close();
	/*��ȡRs422������Ϣ*/
	m_pStUartData = new stUartFullData;
	m_oUartCfg = new CUartCfg(m_pStUartData);
	m_oUartCfg->close();
	return true;
}
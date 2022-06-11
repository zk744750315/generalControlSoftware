#pragma once
#include "ActivedSignalCfg.h"
#include "CNonElectricCfg.h"
#include "CElectricCfg.h"
#include "CUartCfg.h"

using namespace activeSignalCfg;
using namespace noElectricCfg;
using namespace electricCfg;
using namespace uartCfg;
class CConfig
{
public:
	CConfig();
	~CConfig();
	stActDataUnit *GetAvtiveSignalData();
	stElecFullData *GetElecSignalData();
	stNoElecFullData *GetNoElecSignalData();
	stUartFullData *GetUartSignalData();
	/*���������ź����ö���*/
	void CreateActiveSignalCfg();
	/*�����ǵ����ź����ö���*/
	void CreateNoElecSignalCfg();
	/*���������ź����ö���*/
	void CreateElecSignalCfg();
	/*���������ź����ö���*/
	void CreateUartSignalCfg();
private:
	/*�����ź����ö���*/
	CActivedSignalCfg *m_oActiveCfg;
	/*�����ź�������������ָ��*/
	stActDataUnit *m_pStActiveSignalData;

	/*�ǵ����ź����ö���*/
	CNonElectricCfg *m_oNonElecCfg;
	/*�ǵ����ź���������ָ��*/
	stNoElecFullData *m_pStNoElecData;

	/*�����ź����ö���*/
	CElectricCfg *m_oElecCfg;
	/*�����ź���������ָ��*/
	stElecFullData *m_pStElecData;

	/*�����ź����ö���*/
	CUartCfg *m_oUartCfg;
	/*�����ź���������ָ��*/
	stUartFullData *m_pStUartData;
	void Init();
	bool InitCfg();
};


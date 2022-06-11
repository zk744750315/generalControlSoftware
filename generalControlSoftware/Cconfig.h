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
	/*创建激活信号配置对象*/
	void CreateActiveSignalCfg();
	/*创建非电量信号配置对象*/
	void CreateNoElecSignalCfg();
	/*创建电量信号配置对象*/
	void CreateElecSignalCfg();
	/*创建数字信号配置对象*/
	void CreateUartSignalCfg();
private:
	/*激活信号配置对象*/
	CActivedSignalCfg *m_oActiveCfg;
	/*激活信号配置数据数组指针*/
	stActDataUnit *m_pStActiveSignalData;

	/*非电量信号配置对象*/
	CNonElectricCfg *m_oNonElecCfg;
	/*非电量信号配置数据指针*/
	stNoElecFullData *m_pStNoElecData;

	/*电量信号配置对象*/
	CElectricCfg *m_oElecCfg;
	/*电量信号配置数据指针*/
	stElecFullData *m_pStElecData;

	/*数字信号配置对象*/
	CUartCfg *m_oUartCfg;
	/*数字信号配置数据指针*/
	stUartFullData *m_pStUartData;
	void Init();
	bool InitCfg();
};


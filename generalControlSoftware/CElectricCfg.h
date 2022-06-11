#pragma once

#include <QWidget>
#include "ui_CElectricCfg.h"
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace electricCfg
{
#define CfgPathDefault "./config/ElectricModule/config.ini"
#define WaveFormDefaultValue                 WAVE_TYPE::WAVE_DC           
#define DCAmplitudeDefaultValue              0
#define LadderFreshPerDefaultValue           1
#define LadderOutHDefaultValue               0
#define LadderOutLDefaultValue               0
#define LadderOutStartValueDefaultValue      1
#define ACValidDefaultValue                  0
#define ACFrequencyDefaultValue              0.01
#define PauseOutAmplitudeDefaultValue        0
#define PauseOutFrequencyDefaultValue        1
#define PauseOutWidthDefaultValue            0
#define Sin8kValidDefaultValue               0

#pragma execution_character_set("utf-8") 
	/*ini配置文件数据单元节的前半部分名称*/
	const QString CFGFILE_SECTION = "ElectricUnit";
	/*ini配置文件模块内与通道无关的全局变量配置节名称*/
	const QString CFGFILE_GLOBAL_SECTION = "ElectricGlobal";
	/*电量信号通道数量设定*/
	const quint8  u1ELECTRIC_SIGNAL_CHANNEL_COUNT = 4;
	/*配置文件全局变量的键的数量*/
	const quint8  u1DATAGLOBAL_COUNT = 0;
	/*配置文件数据单元中的键的数量*/
	const quint8  u1DATAUNIT_COUNT = 12;
	/*配置文件数据单元中全局变量键的名称，此类中没有，先注释掉
	const QString arrCFG_DATAGLOBAL_NAME[] = {}; */
	/*配置文件数据单元中的键名称,与下面的DATAUNIT_NAME组合使用*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "waveForm","dcAmplitude" ,"ladderFreshPer","ladderOutH", \
		"ladderOutL", "ladderOutStartVal" , "ACValidVal", "ACFrequency" , "pauseOutAmplitude", "pauseOutFrequency" , \
		"pauseOutWidth", "sin8kValid" };
	enum DATAGLOBAL_NAME
	{
		/*此类没有与通道无关的全局变量*/
	};
	enum DATAUNIT_NAME
	{
		WAVE_FORM = 0x0,     /*波形*/
		DC_AMPLITUDE,        /*直流信号幅值*/   
		LADDER_FRESH_PER,    /*阶梯波刷新频率*/
		LADDER_OUT_H,		 /*阶梯波高幅值*/
		LADDER_OUT_L,		 /*阶梯波低幅值*/
		LADDER_OUT_START_VAL,/*阶梯波输出起始序列值*/
		AC_VALID_VAL,		 /*交流信号有效值*/
		AC_FREQUENCY,		 /*交流信号频率*/
		PAUSE_AMPLITUDE,	 /*脉冲信号幅值*/
		PAUSE_FREQUENCY,	 /*脉冲信号频率*/
		PAUSE_WIDTH,		 /*脉冲信号宽度*/
		SIN_8K_VALID_VAL,	 /*8K正弦信号有效值*/

		DATAUNIT_COUT		 /*无效定义，记录DATAUNIT_NAME枚举size()*/
	};
	enum WAVE_TYPE
	{
		WAVE_DC = 0x0,     /*直流*/
		WAVE_LADDER,       /*阶梯波*/
		WAVE_AC,           /*交流*/
		WAVE_PALSE,        /*脉冲*/ 
		WAVE_8K,            /*8K*/ 

		WAVE_COUNT
	};

	/*电量信号单通道数据结构体*/
	typedef struct stElecSignalDataUnit
	{
		WAVE_TYPE m_enumWave;
		/*DC_wave*/
		float m_fDcAmplitude;
		/*Ladder_wave*/
		uint m_u4LadderFreshPer;
		float m_fLadderOutH;
		float m_fLadderOutL;
		uint m_u4LadderOutStartVal;
		/*AC_wave*/
		float m_fACValidVal;
		float m_fACFrequency;
		/*pause_wave*/
		float m_fPauseOutAmplitude;
		float m_fPauseOutFrequency;
		uint m_u4PauseOutWidth;
		/*8K_wave*/
		float m_fSin8kValidVal;

		stElecSignalDataUnit()
		{
			m_enumWave = WAVE_DC;
			m_fDcAmplitude = 0;
			m_u4LadderFreshPer = 1;
			m_fLadderOutH = 0;
			m_fLadderOutL = 0;
			m_u4LadderOutStartVal = 1;
			m_fACValidVal = 0;
			m_fACFrequency = 0.01;
			m_fPauseOutAmplitude = 0;
			m_fPauseOutFrequency = 1;
			m_u4PauseOutWidth = 0;
			m_fSin8kValidVal = 0;
		}

	}stElecDataUnit;

	/*电量信号单通道数据及与通道无关数据的结构体*/
	typedef struct stElecUiShowedData
	{
		WAVE_TYPE m_enumWave;
		float m_fDcAmplitude;
		/*无与通道没有关系的模块全局变量*/
		stElecUiShowedData()
		{
			m_enumWave = WAVE_DC;
			m_fDcAmplitude = 0;
		}

	}stElecUiShowedData;

	typedef struct stElecFullData
	{
		stElecDataUnit m_stArrElecData[u1ELECTRIC_SIGNAL_CHANNEL_COUNT];
		/*无模块全局变量*/
		stElecFullData()
		{
		}
	}stElecFullData;

	class CElectricCfg : public QWidget
	{
		Q_OBJECT

	public:
		CElectricCfg(stElecFullData *pElecCfgData, QWidget *parent = Q_NULLPTR);
		~CElectricCfg();
		//void test();//测试


	private:
		/*重写窗口关闭事件*/
		void closeEvent(QCloseEvent *event);
		/*初始化*/
		void Init();
		/*关联回调函数*/
		void SetCallbackFunc();
		/*从读取单元配置信息*/
		void GetSignalDataUnit(stElecSignalDataUnit& stCfgData, const quint8 &channel = 0);
		void SetSignalDataUnit(const stElecSignalDataUnit& stCfgData, const quint8 &channel = 0);
		/*应用到全部通道槽函数关联*/
		/*解析配置文件*/
		bool ParseCfgFile(const QString &strFileName, stElecFullData *arrData);
		/*更新创建配置文件读写实例，此实例创建以后配置的文件路径无法更改，故而每次用到都重新创建*/
		void CreateFileIOer();
		/*另存为从内存中把配置信息保存到本地的函数*/
		void SaveCfgDataFromMemoty();
		/*由Index返回枚举类型的内联函数*/
		WAVE_TYPE GetWaveType(quint8 index)
		{
			WAVE_TYPE arrTem[WAVE_COUNT] = { WAVE_DC ,WAVE_LADDER ,WAVE_AC,WAVE_PALSE,WAVE_8K };
			return arrTem[index];
		}


		Ui::CElectricCfg ui;
		/*ini文件中读取到的数据信息，此数据有有效数据*/
		stElecFullData * m_pStElecData;
		/*ini配置文件读写*/
		QSettings *m_oCfgOperator;
		//QTimer timer;
		/*配置文件路径*/
		QString m_strCfgFilePath;
		/*是否时在初始化时首次打开配置文件不弹框标识*/
		bool m_bIfInitOpenCfgFile;
		/*为另存为按键设置，是否从ui界面读取配置信息开关，默认关，只有在“另存为”才会打开*/
		bool m_bIfGetInfoFromUi;
	private slots:
		//void test1();//测试
				/*输入框数据发生变化更新内存的回调函数*/
		void InPutChangedCallbackof_spinDCAmplitude();
		void InPutChangedCallbackof_spinLadderFreshPer();
		void InPutChangedCallbackof_spinLadderOutH();
		void InPutChangedCallbackof_spinLadderOutL();
		void InPutChangedCallbackof_spinLadderOutStartValue();
		/*20220531增加，根据不同波形，让界面中的某些控件显示或者隐藏*/
		void InPutChangedCallbackof_combCVaveform();
		void InPutChangedCallbackof_spinACValidValue();
		void InPutChangedCallbackof_spinACFrequency();
		void InPutChangedCallbackof_spinPauseOutAmplitude();
		void InPutChangedCallbackof_spinPauseOutFrequency();
		void InPutChangedCallbackof_spinPauseOutWidth();
		void InPutChangedCallbackof_spin8kValidValue();

		/*保存按键回调函数*/
		bool SaveCfg();
		/*另存为按键回调函数*/
		bool SaveCfgAs();
		/*打开配置文件按键回调函数*/
		bool OpenCfg();
		/*取消按键回调函数*/
		void Cancel();
		/*更改通道的回调函数*/
		void CallfunctoChannelChanged();
		/*应用到所有通道*/
		void ApplyToAllChannel();
	};

}
QT_END_NAMESPACE
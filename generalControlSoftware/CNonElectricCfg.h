#pragma once

#include <QWidget>
#include "ui_CNonElectricCfg.h"
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>

QT_BEGIN_NAMESPACE

namespace noElectricCfg
{
#define CfgPathDefault "./config/NonElectricModule/config.ini"
#define WaveFormDefaultValue            WAVE_TYPE::WAVE_DC           
#define DCAmplitudeDefaultValue         0
#define NoEleSampPeriodDefaultValue     1
#define LadderwaveFreshPerDefaultValue  1
#define LadderwaveOutHDefaultValue      0
#define LadderwaveOutLDefaultValue      0
#define LadderwaveOutStartfaultValue    1

#pragma execution_character_set("utf-8") 
	/*ini配置文件数据单元节的前半部分名称*/
	const QString CFGFILE_SECTION = "NoElectricUnit";
	/*ini配置文件模块内与通道无关的全局变量配置节名称*/
	const QString CFGFILE_GLOBAL_SECTION = "NoElectricGlobal";
	/*非电量信号通道数量设定*/
	const quint8  u1NOELECTRIC_SIGNAL_CHANNEL_COUNT = 48;
	/*配置文件全局变量的键的数量*/
	const quint8  u1DATAGLOBAL_COUNT = 2;
	/*配置文件数据单元中的键的数量*/
	const quint8  u1DATAUNIT_COUNT = 5;
	/*配置文件数据单元中全局变量键的名称*/
	const QString arrCFG_DATAGLOBAL_NAME[u1DATAGLOBAL_COUNT] = { "noEleSampPeriod","ladderwaveFreshPer" };
	/*配置文件数据单元中的键名称,与下面的DATAUNIT_NAME组合使用*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "waveForm","dcAmplitude","ladderH","ladderL","ladderStart" };
	enum DATAGLOBAL_NAME
	{
		NOELEC_SAMPLE_PERIOD = 0x0,
		LADDERWAVE_FRESH_PERIOD
	};
	enum DATAUNIT_NAME
	{
		WAVE_FORM = 0x0,
		DC_AMPLITUDE,
		LADDER_H,           /*阶梯波高幅值*/
		LADDER_L,			/*阶梯波低幅值*/
		LADDER_START_VALUE /*输出初始序列值*/
	};
	enum WAVE_TYPE
	{
		WAVE_DC = 0x0,/*直流*/
		WAVE_LADDER, /*阶梯波*/

		WAVE_COUNT
	};
	/*非电量信号单通道数据结构体*/
	typedef struct stNoElecSignalDataUnit
	{
		WAVE_TYPE m_enumWave;
		float m_fDcAmplitude;
		float m_fLadderHigeAmplitude;
		float m_fLadderLowAmplitude;
		quint8 m_u1LadderStartValue;
		stNoElecSignalDataUnit()
		{
			m_enumWave = WAVE_DC;
			m_fDcAmplitude = 0;
			m_fLadderHigeAmplitude = 0;
			m_fLadderLowAmplitude = 0;
			m_u1LadderStartValue = 1;
		}

	}stNoElecDataUnit;

	/*非电量信号单通道数据及与通道无关数据的结构体*/
	typedef struct stNoElecUiShowedData
	{
		WAVE_TYPE m_enumWave;
		float m_fDcAmplitude;
		float m_fLadderHigeAmplitude;
		float m_fLadderLowAmplitude;
		quint8 m_u1LadderStartValue;
		int m_iNoEleSampPeriod;
		int m_iLadderwaveFreshPer;

		stNoElecUiShowedData()
		{
			m_enumWave = WAVE_DC;
			m_fDcAmplitude = 0;
			m_fLadderHigeAmplitude = 0;
			m_fLadderLowAmplitude = 0;
			m_u1LadderStartValue = 1;
			m_iNoEleSampPeriod = 1;
			m_iLadderwaveFreshPer = 1;
		}

	}stNoElecUiShowedData;

	typedef struct stNoElecFullData
	{
		stNoElecDataUnit m_stArrNoElecData[u1NOELECTRIC_SIGNAL_CHANNEL_COUNT];
		int m_iNoEleSampPeriod;
		int m_iLadderwaveFreshPer;
		stNoElecFullData()
		{
			m_iNoEleSampPeriod = 1;
			m_iLadderwaveFreshPer = 1;
		}
	}stNoElecFullData;
	class CNonElectricCfg;



	class CNonElectricCfg : public QWidget
	{
		Q_OBJECT

	public:
		CNonElectricCfg(stNoElecFullData *pNoElecCfgData, QWidget *parent = Q_NULLPTR);
		~CNonElectricCfg();
		//void test();//测试


	private:
		/*重写窗口关闭事件*/
		void closeEvent(QCloseEvent *event);
		/*初始化*/
		void Init();
		/*关联回调函数*/
		void SetCallbackFunc();
		/*从界面读取配置信息*/
		void GetInfoFromUi(stNoElecUiShowedData& stCfgData);
		/*应用到全部通道槽函数关联*/
		void ApplyToAllSlots();
		/*保存配置单元*/
		void SaveCfgUnit(const quint8 &u1Channel, const stNoElecUiShowedData& stData);
		/*保存与通道无关的配置信息*/
		void SaveModuleGlobalCfg(const quint8 &u1Channel, const stNoElecUiShowedData& stData);
		/*解析配置文件*/
		bool ParseCfgFile(const QString &strFileName, stNoElecFullData *arrData);
		/*更新创建配置文件读写实例，此实例创建以后配置的文件路径无法更改，故而每次用到都重新创建*/
		void CreateFileIOer();
		/*另存为从内存中把配置信息保存到本地的函数*/
		void SaveCfgDataFromMemoty();
		WAVE_TYPE GetWaveType(quint8 index)
		{
			WAVE_TYPE arrTem[WAVE_COUNT] = { WAVE_DC ,WAVE_LADDER};
			return arrTem[index];
		}

		Ui::CNonElectricCfg ui;
		/*ini文件中读取到的数据信息，此数据有有效数据*/
		stNoElecFullData * m_pStNoElecData;
		/*应用到全部通道开关*/
		bool m_bApplyToAll = false;
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
		void InPutChangedCallbackof_spinLadderOutH();
		void InPutChangedCallbackof_spinLadderOutL();
		void InPutChangedCallbackof_spinLadderOutStartValue();
		/*20220531增加，根据不同波形，让界面中的某些控件显示或者隐藏*/
		void InPutChangedCallbackof_combCVaveform();
		void InPutChangedCallbackof_spinNoEleCheckSampPer();
		void InPutChangedCallbackof_spinLadderwaveFreshPer();
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
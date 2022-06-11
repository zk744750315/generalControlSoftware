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
	/*ini�����ļ����ݵ�Ԫ�ڵ�ǰ�벿������*/
	const QString CFGFILE_SECTION = "ElectricUnit";
	/*ini�����ļ�ģ������ͨ���޹ص�ȫ�ֱ������ý�����*/
	const QString CFGFILE_GLOBAL_SECTION = "ElectricGlobal";
	/*�����ź�ͨ�������趨*/
	const quint8  u1ELECTRIC_SIGNAL_CHANNEL_COUNT = 4;
	/*�����ļ�ȫ�ֱ����ļ�������*/
	const quint8  u1DATAGLOBAL_COUNT = 0;
	/*�����ļ����ݵ�Ԫ�еļ�������*/
	const quint8  u1DATAUNIT_COUNT = 12;
	/*�����ļ����ݵ�Ԫ��ȫ�ֱ����������ƣ�������û�У���ע�͵�
	const QString arrCFG_DATAGLOBAL_NAME[] = {}; */
	/*�����ļ����ݵ�Ԫ�еļ�����,�������DATAUNIT_NAME���ʹ��*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "waveForm","dcAmplitude" ,"ladderFreshPer","ladderOutH", \
		"ladderOutL", "ladderOutStartVal" , "ACValidVal", "ACFrequency" , "pauseOutAmplitude", "pauseOutFrequency" , \
		"pauseOutWidth", "sin8kValid" };
	enum DATAGLOBAL_NAME
	{
		/*����û����ͨ���޹ص�ȫ�ֱ���*/
	};
	enum DATAUNIT_NAME
	{
		WAVE_FORM = 0x0,     /*����*/
		DC_AMPLITUDE,        /*ֱ���źŷ�ֵ*/   
		LADDER_FRESH_PER,    /*���ݲ�ˢ��Ƶ��*/
		LADDER_OUT_H,		 /*���ݲ��߷�ֵ*/
		LADDER_OUT_L,		 /*���ݲ��ͷ�ֵ*/
		LADDER_OUT_START_VAL,/*���ݲ������ʼ����ֵ*/
		AC_VALID_VAL,		 /*�����ź���Чֵ*/
		AC_FREQUENCY,		 /*�����ź�Ƶ��*/
		PAUSE_AMPLITUDE,	 /*�����źŷ�ֵ*/
		PAUSE_FREQUENCY,	 /*�����ź�Ƶ��*/
		PAUSE_WIDTH,		 /*�����źſ��*/
		SIN_8K_VALID_VAL,	 /*8K�����ź���Чֵ*/

		DATAUNIT_COUT		 /*��Ч���壬��¼DATAUNIT_NAMEö��size()*/
	};
	enum WAVE_TYPE
	{
		WAVE_DC = 0x0,     /*ֱ��*/
		WAVE_LADDER,       /*���ݲ�*/
		WAVE_AC,           /*����*/
		WAVE_PALSE,        /*����*/ 
		WAVE_8K,            /*8K*/ 

		WAVE_COUNT
	};

	/*�����źŵ�ͨ�����ݽṹ��*/
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

	/*�����źŵ�ͨ�����ݼ���ͨ���޹����ݵĽṹ��*/
	typedef struct stElecUiShowedData
	{
		WAVE_TYPE m_enumWave;
		float m_fDcAmplitude;
		/*����ͨ��û�й�ϵ��ģ��ȫ�ֱ���*/
		stElecUiShowedData()
		{
			m_enumWave = WAVE_DC;
			m_fDcAmplitude = 0;
		}

	}stElecUiShowedData;

	typedef struct stElecFullData
	{
		stElecDataUnit m_stArrElecData[u1ELECTRIC_SIGNAL_CHANNEL_COUNT];
		/*��ģ��ȫ�ֱ���*/
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
		//void test();//����


	private:
		/*��д���ڹر��¼�*/
		void closeEvent(QCloseEvent *event);
		/*��ʼ��*/
		void Init();
		/*�����ص�����*/
		void SetCallbackFunc();
		/*�Ӷ�ȡ��Ԫ������Ϣ*/
		void GetSignalDataUnit(stElecSignalDataUnit& stCfgData, const quint8 &channel = 0);
		void SetSignalDataUnit(const stElecSignalDataUnit& stCfgData, const quint8 &channel = 0);
		/*Ӧ�õ�ȫ��ͨ���ۺ�������*/
		/*���������ļ�*/
		bool ParseCfgFile(const QString &strFileName, stElecFullData *arrData);
		/*���´��������ļ���дʵ������ʵ�������Ժ����õ��ļ�·���޷����ģ��ʶ�ÿ���õ������´���*/
		void CreateFileIOer();
		/*���Ϊ���ڴ��а�������Ϣ���浽���صĺ���*/
		void SaveCfgDataFromMemoty();
		/*��Index����ö�����͵���������*/
		WAVE_TYPE GetWaveType(quint8 index)
		{
			WAVE_TYPE arrTem[WAVE_COUNT] = { WAVE_DC ,WAVE_LADDER ,WAVE_AC,WAVE_PALSE,WAVE_8K };
			return arrTem[index];
		}


		Ui::CElectricCfg ui;
		/*ini�ļ��ж�ȡ����������Ϣ������������Ч����*/
		stElecFullData * m_pStElecData;
		/*ini�����ļ���д*/
		QSettings *m_oCfgOperator;
		//QTimer timer;
		/*�����ļ�·��*/
		QString m_strCfgFilePath;
		/*�Ƿ�ʱ�ڳ�ʼ��ʱ�״δ������ļ��������ʶ*/
		bool m_bIfInitOpenCfgFile;
		/*Ϊ���Ϊ�������ã��Ƿ��ui�����ȡ������Ϣ���أ�Ĭ�Ϲأ�ֻ���ڡ����Ϊ���Ż��*/
		bool m_bIfGetInfoFromUi;
	private slots:
		//void test1();//����
				/*��������ݷ����仯�����ڴ�Ļص�����*/
		void InPutChangedCallbackof_spinDCAmplitude();
		void InPutChangedCallbackof_spinLadderFreshPer();
		void InPutChangedCallbackof_spinLadderOutH();
		void InPutChangedCallbackof_spinLadderOutL();
		void InPutChangedCallbackof_spinLadderOutStartValue();
		/*20220531���ӣ����ݲ�ͬ���Σ��ý����е�ĳЩ�ؼ���ʾ��������*/
		void InPutChangedCallbackof_combCVaveform();
		void InPutChangedCallbackof_spinACValidValue();
		void InPutChangedCallbackof_spinACFrequency();
		void InPutChangedCallbackof_spinPauseOutAmplitude();
		void InPutChangedCallbackof_spinPauseOutFrequency();
		void InPutChangedCallbackof_spinPauseOutWidth();
		void InPutChangedCallbackof_spin8kValidValue();

		/*���水���ص�����*/
		bool SaveCfg();
		/*���Ϊ�����ص�����*/
		bool SaveCfgAs();
		/*�������ļ������ص�����*/
		bool OpenCfg();
		/*ȡ�������ص�����*/
		void Cancel();
		/*����ͨ���Ļص�����*/
		void CallfunctoChannelChanged();
		/*Ӧ�õ�����ͨ��*/
		void ApplyToAllChannel();
	};

}
QT_END_NAMESPACE
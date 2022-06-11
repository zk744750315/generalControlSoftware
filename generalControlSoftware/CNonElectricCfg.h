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
	/*ini�����ļ����ݵ�Ԫ�ڵ�ǰ�벿������*/
	const QString CFGFILE_SECTION = "NoElectricUnit";
	/*ini�����ļ�ģ������ͨ���޹ص�ȫ�ֱ������ý�����*/
	const QString CFGFILE_GLOBAL_SECTION = "NoElectricGlobal";
	/*�ǵ����ź�ͨ�������趨*/
	const quint8  u1NOELECTRIC_SIGNAL_CHANNEL_COUNT = 48;
	/*�����ļ�ȫ�ֱ����ļ�������*/
	const quint8  u1DATAGLOBAL_COUNT = 2;
	/*�����ļ����ݵ�Ԫ�еļ�������*/
	const quint8  u1DATAUNIT_COUNT = 5;
	/*�����ļ����ݵ�Ԫ��ȫ�ֱ�����������*/
	const QString arrCFG_DATAGLOBAL_NAME[u1DATAGLOBAL_COUNT] = { "noEleSampPeriod","ladderwaveFreshPer" };
	/*�����ļ����ݵ�Ԫ�еļ�����,�������DATAUNIT_NAME���ʹ��*/
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
		LADDER_H,           /*���ݲ��߷�ֵ*/
		LADDER_L,			/*���ݲ��ͷ�ֵ*/
		LADDER_START_VALUE /*�����ʼ����ֵ*/
	};
	enum WAVE_TYPE
	{
		WAVE_DC = 0x0,/*ֱ��*/
		WAVE_LADDER, /*���ݲ�*/

		WAVE_COUNT
	};
	/*�ǵ����źŵ�ͨ�����ݽṹ��*/
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

	/*�ǵ����źŵ�ͨ�����ݼ���ͨ���޹����ݵĽṹ��*/
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
		//void test();//����


	private:
		/*��д���ڹر��¼�*/
		void closeEvent(QCloseEvent *event);
		/*��ʼ��*/
		void Init();
		/*�����ص�����*/
		void SetCallbackFunc();
		/*�ӽ����ȡ������Ϣ*/
		void GetInfoFromUi(stNoElecUiShowedData& stCfgData);
		/*Ӧ�õ�ȫ��ͨ���ۺ�������*/
		void ApplyToAllSlots();
		/*�������õ�Ԫ*/
		void SaveCfgUnit(const quint8 &u1Channel, const stNoElecUiShowedData& stData);
		/*������ͨ���޹ص�������Ϣ*/
		void SaveModuleGlobalCfg(const quint8 &u1Channel, const stNoElecUiShowedData& stData);
		/*���������ļ�*/
		bool ParseCfgFile(const QString &strFileName, stNoElecFullData *arrData);
		/*���´��������ļ���дʵ������ʵ�������Ժ����õ��ļ�·���޷����ģ��ʶ�ÿ���õ������´���*/
		void CreateFileIOer();
		/*���Ϊ���ڴ��а�������Ϣ���浽���صĺ���*/
		void SaveCfgDataFromMemoty();
		WAVE_TYPE GetWaveType(quint8 index)
		{
			WAVE_TYPE arrTem[WAVE_COUNT] = { WAVE_DC ,WAVE_LADDER};
			return arrTem[index];
		}

		Ui::CNonElectricCfg ui;
		/*ini�ļ��ж�ȡ����������Ϣ������������Ч����*/
		stNoElecFullData * m_pStNoElecData;
		/*Ӧ�õ�ȫ��ͨ������*/
		bool m_bApplyToAll = false;
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
		void InPutChangedCallbackof_spinLadderOutH();
		void InPutChangedCallbackof_spinLadderOutL();
		void InPutChangedCallbackof_spinLadderOutStartValue();
		/*20220531���ӣ����ݲ�ͬ���Σ��ý����е�ĳЩ�ؼ���ʾ��������*/
		void InPutChangedCallbackof_combCVaveform();
		void InPutChangedCallbackof_spinNoEleCheckSampPer();
		void InPutChangedCallbackof_spinLadderwaveFreshPer();
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
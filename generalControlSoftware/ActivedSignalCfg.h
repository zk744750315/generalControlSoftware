/*
�޸Ľ����ϵ�������е����ݣ���ֱ�ӵ����ص��������������ڴ��е����ݽ��и��ġ��������Ż���ĵ�����
���ȡ�����߹ر�ҳ�棬��ôû�е������ǰ���������ý����ᱻ���棬Ҳ������Ч��
*/
#pragma once

#include <QWidget>
#include "ui_ActivedSignalCfg.h"
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>

QT_BEGIN_NAMESPACE

namespace activeSignalCfg
{
#define CfgPathDefault "./config/ActivedSignalModule/config.ini"
#define currentDefaultValue 0
#define voltageDefaultValue 25
#pragma execution_character_set("utf-8") 
	/*ini�����ļ����ݵ�Ԫ�ڵ�ǰ�벿������*/
	const QString CFGFILE_SECTION = "ActiveUnit";
	/*�����ź�ͨ�������趨*/
	const quint8  u1ACTIVE_SIGNAL_CHANNEL_COUNT = 3;
	/*�����ļ����ݵ�Ԫ�еļ�������*/
	const quint8  u1DATAUNIT_COUNT = 2;
	/*�����ļ����ݵ�Ԫ�еļ�����,�������DATAUNIT_NAME���ʹ��*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "currnet","voltage" };
	enum DATAUNIT_NAME
	{
		CURRENT = 0x0,
		VOLTAGE
	};
	/*�����źŵ�ͨ�����ݽṹ��*/
	typedef struct stActiveSignalDataUnit
	{
		float m_fVoltage;
		float m_fCurrnet;

		stActiveSignalDataUnit()
		{
			m_fVoltage = 25;
			m_fCurrnet = 0;
		}

	}stActDataUnit;
	class CActivedSignalCfg;

	class CActivedSignalCfg : public QWidget
	{
		Q_OBJECT

	public:
		CActivedSignalCfg(stActDataUnit *pActiveCfgData, QWidget *parent = Q_NULLPTR);
		~CActivedSignalCfg();
		//void test();//����


	private:
		/*��д���ڹر��¼�*/
		void closeEvent(QCloseEvent *event);
		/*��ʼ��*/
		void Init();
		/*�����ص�����*/
		void SetCallbackFunc();
		/*���������ļ�*/
		bool ParseCfgFile(const QString &strFileName, stActDataUnit arrData[]);
		/*���´��������ļ���дʵ������ʵ�������Ժ����õ��ļ�·���޷����ģ��ʶ�ÿ���õ������´���*/
		void CreateFileIOer();
		/*���Ϊ���ڴ��а�������Ϣ���浽���صĺ���*/
		void SaveCfgDataFromMemoty();

		Ui::ActivedSignalCfg ui;
		///*��Ч������Ϣ*/
		//stActDataUnit m_arrStActiveSignalData[u1ACTIVE_SIGNAL_CHANNEL_COUNT];
		/*����ָ�룬ini�ļ��ж�ȡ����ȫ��������Ϣ��������Ϊ��Ч����*/
		stActDataUnit * m_pStActiveSignalData;
		/*Ӧ�õ�ȫ��ͨ������*/
		bool m_bApplyToAll = false;
		/*ini�����ļ���д*/
		QSettings *m_oCfgOperator;
		//QTimer timer;
		/*�����ļ�·��*/
		QString m_strCfgFilePath;
		/*�Ƿ�ʱ�ڳ�ʼ��ʱ�״δ������ļ��������ʶ*/
		bool m_bIfInitOpenCfgFile;
	private slots:
		//void test1();//����
		/*��������ݷ����仯�����ڴ�Ļص�����*/
		void InPutChangedCallbackof_spinBoxVoltage();
		void InPutChangedCallbackof_spinBoxCurrent();
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
		/*Ӧ�õ����лص�����*/
		void ApplyToAllChannel();
	};
}
QT_END_NAMESPACE



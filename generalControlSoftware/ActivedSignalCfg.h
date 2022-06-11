/*
修改界面上的输入框中的内容，会直接调动回调函数，将运行内存中的数据进行更改。点击保存才会更改到本地
点击取消或者关闭页面，那么没有点击保存前的所有设置将不会被保存，也不会生效。
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
	/*ini配置文件数据单元节的前半部分名称*/
	const QString CFGFILE_SECTION = "ActiveUnit";
	/*激活信号通道数量设定*/
	const quint8  u1ACTIVE_SIGNAL_CHANNEL_COUNT = 3;
	/*配置文件数据单元中的键的数量*/
	const quint8  u1DATAUNIT_COUNT = 2;
	/*配置文件数据单元中的键名称,与下面的DATAUNIT_NAME组合使用*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "currnet","voltage" };
	enum DATAUNIT_NAME
	{
		CURRENT = 0x0,
		VOLTAGE
	};
	/*激活信号单通道数据结构体*/
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
		//void test();//测试


	private:
		/*重写窗口关闭事件*/
		void closeEvent(QCloseEvent *event);
		/*初始化*/
		void Init();
		/*关联回调函数*/
		void SetCallbackFunc();
		/*解析配置文件*/
		bool ParseCfgFile(const QString &strFileName, stActDataUnit arrData[]);
		/*更新创建配置文件读写实例，此实例创建以后配置的文件路径无法更改，故而每次用到都重新创建*/
		void CreateFileIOer();
		/*另存为从内存中把配置信息保存到本地的函数*/
		void SaveCfgDataFromMemoty();

		Ui::ActivedSignalCfg ui;
		///*有效数据信息*/
		//stActDataUnit m_arrStActiveSignalData[u1ACTIVE_SIGNAL_CHANNEL_COUNT];
		/*数组指针，ini文件中读取到的全部数据信息，此数据为有效数据*/
		stActDataUnit * m_pStActiveSignalData;
		/*应用到全部通道开关*/
		bool m_bApplyToAll = false;
		/*ini配置文件读写*/
		QSettings *m_oCfgOperator;
		//QTimer timer;
		/*配置文件路径*/
		QString m_strCfgFilePath;
		/*是否时在初始化时首次打开配置文件不弹框标识*/
		bool m_bIfInitOpenCfgFile;
	private slots:
		//void test1();//测试
		/*输入框数据发生变化更新内存的回调函数*/
		void InPutChangedCallbackof_spinBoxVoltage();
		void InPutChangedCallbackof_spinBoxCurrent();
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
		/*应用到所有回调函数*/
		void ApplyToAllChannel();
	};
}
QT_END_NAMESPACE



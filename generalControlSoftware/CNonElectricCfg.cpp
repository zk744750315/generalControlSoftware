#include "CNonElectricCfg.h"
#include <QFileDialog>	
using namespace noElectricCfg;

CNonElectricCfg::CNonElectricCfg(stNoElecFullData *pNoElecCfgData, QWidget *parent)
	: QWidget(parent)
	, m_pStNoElecData(pNoElecCfgData)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint);
	setAttribute(Qt::WA_DeleteOnClose);
	Init();
}

CNonElectricCfg::~CNonElectricCfg()
{
	if (NULL != m_oCfgOperator)
	{
		delete m_oCfgOperator;
		m_oCfgOperator = NULL;
	}
	/*只把指针指向空，内存由创建此实例的对象释放*/
	if (NULL != m_pStNoElecData)
	{
		/*	delete [] m_pStNoElecData;*/
		m_pStNoElecData = NULL;
	}
}


/*初始化CNonElectricCfg实例*/
void CNonElectricCfg::Init()
{
	//*默认路径初始化*/
	m_strCfgFilePath = CfgPathDefault;
	/*初始化INI配置文件读写类*/
	m_oCfgOperator = NULL;
	/*初始化，初始化时首次打开配置文件不弹框标识为真*/
	m_bIfInitOpenCfgFile = true;
	m_bIfGetInfoFromUi = false;
	/*读取默认配置文件*/
	OpenCfg();
	SetCallbackFunc();
}
/*关联按键回调函数*/ 
void CNonElectricCfg::SetCallbackFunc()
{
	connect(ui.btnSave, &QPushButton::clicked, this, &CNonElectricCfg::SaveCfg);
	connect(ui.btnSaveAs, &QPushButton::clicked, this, &CNonElectricCfg::SaveCfgAs);
	connect(ui.btnOpen, &QPushButton::clicked, this, &CNonElectricCfg::OpenCfg);
	connect(ui.btnCancel, &QPushButton::clicked, this, &CNonElectricCfg::Cancel);
	connect(ui.combCfgChannel, SIGNAL(activated(int)), this, SLOT(CallfunctoChannelChanged()));
	connect(ui.btnCfgApplyToAll, SIGNAL(clicked()), this, SLOT(ApplyToAllChannel()));
	connect(ui.combCVaveform, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combCVaveform()));
	connect(ui.spinDCAmplitude, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinDCAmplitude()));
	connect(ui.spinLadderOutH, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderOutH()));
	connect(ui.spinLadderOutL, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderOutL()));
	connect(ui.spinLadderOutStartValue, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderOutStartValue()));
	connect(ui.spinNoEleCheckSampPer, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinNoEleCheckSampPer()));
	connect(ui.spinLadderwaveFreshPer, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderwaveFreshPer()));
}

/*对话框输入数据发生变化，回调函数更新对应内存数据*/
void CNonElectricCfg::InPutChangedCallbackof_spinDCAmplitude()
{
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fDcAmplitude = ui.spinDCAmplitude->value();
}
void CNonElectricCfg::InPutChangedCallbackof_spinLadderOutH()
{
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fLadderHigeAmplitude = ui.spinLadderOutH->value();
}
void CNonElectricCfg::InPutChangedCallbackof_spinLadderOutL()
{
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fLadderLowAmplitude = ui.spinLadderOutL->value();
}
void CNonElectricCfg::InPutChangedCallbackof_spinLadderOutStartValue()
{
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	m_pStNoElecData->m_stArrNoElecData[u1Channel].m_u1LadderStartValue = ui.spinLadderOutStartValue->value();
}
void CNonElectricCfg::InPutChangedCallbackof_spinNoEleCheckSampPer()
{
	m_pStNoElecData->m_iNoEleSampPeriod = ui.spinNoEleCheckSampPer->value();
}
void CNonElectricCfg::InPutChangedCallbackof_spinLadderwaveFreshPer()
{
	m_pStNoElecData->m_iLadderwaveFreshPer = ui.spinLadderwaveFreshPer->value();
}

/*保存按键回调函数,QSetting类的单例模式无法修改ini保存路径，其静态函数setPath()对已经创建的实例不起作用
，所以这里选择每次保存时创建一个QSetting实例，保存路径看为m_strCfgFilePath。*/
bool CNonElectricCfg::SaveCfg()
{
	SaveCfgDataFromMemoty();
	return true;
}
/*********************************************************************************
  * @brief  保存配置
  * @param u1Channel
  * @retval
  * @note
**********************************************************************************/
void CNonElectricCfg::SaveCfgDataFromMemoty()
{ 
	QString sectionIndex;
	WAVE_TYPE enumWave;
	float fDcAmplitude;
	float fLadderHigeAmplitude;
	float fLadderLowAmplitude;
	quint8 u1LadderStartValue;

	int iNoEleSampPeriod;
	int iLadderwaveFreshPer;
	for (quint8 u1Channel = 0; u1Channel < u1NOELECTRIC_SIGNAL_CHANNEL_COUNT; u1Channel++)
	{
		sectionIndex = QString::number(u1Channel);
		enumWave = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_enumWave;
		fDcAmplitude = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fDcAmplitude;
		fLadderHigeAmplitude = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fLadderHigeAmplitude;
		fLadderLowAmplitude = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fLadderLowAmplitude;
		u1LadderStartValue = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_u1LadderStartValue;

		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[WAVE_FORM], QString::number(enumWave));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[DC_AMPLITUDE], QString::number(fDcAmplitude, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_H], QString::number(fLadderHigeAmplitude, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_L], QString::number(fLadderLowAmplitude, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_START_VALUE], QString::number(u1LadderStartValue));
		m_oCfgOperator->endGroup();
	}
	/*保存与通道无关的全局配置信息*/
	iNoEleSampPeriod = m_pStNoElecData->m_iNoEleSampPeriod;
	iLadderwaveFreshPer = m_pStNoElecData->m_iLadderwaveFreshPer;
	m_oCfgOperator->beginGroup(CFGFILE_GLOBAL_SECTION);
	m_oCfgOperator->setValue(arrCFG_DATAGLOBAL_NAME[NOELEC_SAMPLE_PERIOD], QString::number(iNoEleSampPeriod));
	m_oCfgOperator->setValue(arrCFG_DATAGLOBAL_NAME[LADDERWAVE_FRESH_PERIOD], QString::number(iLadderwaveFreshPer));
	m_oCfgOperator->endGroup();
	/*同步*/
	m_oCfgOperator->sync();
}

/*另存为按键回调函数，逻辑：先保存，在打开配置文件*/
bool CNonElectricCfg::SaveCfgAs()
{
	QString m_strCfgFilePathCopyy = m_strCfgFilePath;
	/*另存为.dat格式*/
	m_strCfgFilePath = m_strCfgFilePath.replace("ini", "dat");
	m_strCfgFilePath = QFileDialog::getSaveFileName(NULL, tr("另存为"), m_strCfgFilePath, "*.dat");
	/*若没有选择文件，之间关闭了选择文件对话框，恢复配置文件路径，函数直接返回*/
	if (0 == m_strCfgFilePath.length())
	{
		m_strCfgFilePath = m_strCfgFilePathCopyy;
		return false;
	}
	/*创建配置文件*/
	QFile file(m_strCfgFilePath);
	/*创建QSetting实例*/
	CreateFileIOer();
	/*将内存中的数据写入配置文件*/
	SaveCfgDataFromMemoty();
	return true;
}
/*打开配置文件按键回调函数*/
bool CNonElectricCfg::OpenCfg()
{
	if (m_bIfInitOpenCfgFile)
	{
		/*m_bIfInitOpenCfgFile为弹框不弹框的开关，下次就不是初始化打开默认配置文件,选择文件不弹框标识为false*/
		m_bIfInitOpenCfgFile = false;
	}
	else
	{
		/*拷贝配置文件路径m_strCfgFilePath，防止在选择配置文件对话框QFileDialog::getOpenFileName()中因为没有选择
		文件返回空字符串而丢失上一次配置文件的路径*/
		QString m_strCfgFilePathCopy = m_strCfgFilePath;
		m_strCfgFilePath = QFileDialog::getOpenFileName(NULL, "选择文件", m_strCfgFilePath, "*.ini *.dat");
		/*若没有选择文件，之间关闭了选择文件对话框，恢复配置文件路径，函数直接返回*/
		if (0 == m_strCfgFilePath.length())
		{
			m_strCfgFilePath = m_strCfgFilePathCopy;
			return false;
		}
	}
	if (ParseCfgFile(m_strCfgFilePath, m_pStNoElecData))
	{
		/*解析成功，将m_pStNoElecData中的信息更新界面*/
		CallfunctoChannelChanged();
	}
	return true;
}
void CNonElectricCfg::CreateFileIOer()
{
	/*创建QSetting实例*/
	if (NULL != m_oCfgOperator)
	{
		delete m_oCfgOperator;
		m_oCfgOperator = NULL;
	}
	m_oCfgOperator = new QSettings(m_strCfgFilePath, QSettings::IniFormat);
	/*设置配置文件operator为utf-8编码*/
	m_oCfgOperator->setIniCodec("UTF-8");
}
/*解析配置文件。应该在这里创建QSettings对象*/
bool CNonElectricCfg::ParseCfgFile(const QString &strFileName, stNoElecFullData *pData)
{
	/*创建QSetting实例*/
	CreateFileIOer();
	QString sectionIndex;
	quint8 u1WaveType;
	for (quint8 iChannel = 0; iChannel < u1NOELECTRIC_SIGNAL_CHANNEL_COUNT; iChannel++)
	{
		sectionIndex = QString::number(iChannel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		/*波形，读取不到则默认为直流*/
		u1WaveType = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[WAVE_FORM], WaveFormDefaultValue).toInt();
		pData->m_stArrNoElecData[iChannel].m_enumWave = GetWaveType(u1WaveType);
		/*直流波形幅值，读取不到则默认为0*/
 		pData->m_stArrNoElecData[iChannel].m_fDcAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DC_AMPLITUDE], DCAmplitudeDefaultValue).toFloat();
		pData->m_stArrNoElecData[iChannel].m_fLadderHigeAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_H], LadderwaveOutHDefaultValue).toFloat();
		pData->m_stArrNoElecData[iChannel].m_fLadderLowAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_L], LadderwaveOutLDefaultValue).toFloat();
		pData->m_stArrNoElecData[iChannel].m_u1LadderStartValue = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_START_VALUE], LadderwaveOutStartfaultValue).toInt();
		m_oCfgOperator->endGroup();
	}
	/*解析与通道无关的全局配置信息*/
	m_oCfgOperator->beginGroup(CFGFILE_GLOBAL_SECTION);
	/*非电量采样周期，读不到的话默认为1*/
	pData->m_iNoEleSampPeriod = m_oCfgOperator->value(arrCFG_DATAGLOBAL_NAME[NOELEC_SAMPLE_PERIOD], NoEleSampPeriodDefaultValue).toInt();
	/*阶梯波刷新周期，读取不到则默认为1*/
	pData->m_iLadderwaveFreshPer = m_oCfgOperator ->value(arrCFG_DATAGLOBAL_NAME[LADDERWAVE_FRESH_PERIOD], LadderwaveFreshPerDefaultValue).toInt();
	m_oCfgOperator->endGroup();
	/*同步*/
	m_oCfgOperator->sync();
	return true;
}
/*更改通道的回调函数,关闭应用到全局开关，更新ui界面*/
void CNonElectricCfg::CallfunctoChannelChanged()
{
	quint8 u1ShowedChannel = ui.combCfgChannel->currentIndex();
	if (NULL != m_pStNoElecData)
	{
		WAVE_TYPE wave = m_pStNoElecData->m_stArrNoElecData[u1ShowedChannel].m_enumWave;
		ui.combCVaveform->setCurrentIndex(wave);
		ui.spinDCAmplitude->setValue(m_pStNoElecData->m_stArrNoElecData[u1ShowedChannel].m_fDcAmplitude);
		ui.spinLadderOutH->setValue(m_pStNoElecData->m_stArrNoElecData[u1ShowedChannel].m_fLadderHigeAmplitude);
		ui.spinLadderOutL->setValue(m_pStNoElecData->m_stArrNoElecData[u1ShowedChannel].m_fLadderLowAmplitude);
		ui.spinLadderOutStartValue->setValue(m_pStNoElecData->m_stArrNoElecData[u1ShowedChannel].m_u1LadderStartValue);
		/*全局变量也放在这里更新*/
		ui.spinNoEleCheckSampPer->setValue(m_pStNoElecData->m_iNoEleSampPeriod);
		ui.spinLadderwaveFreshPer->setValue(m_pStNoElecData->m_iLadderwaveFreshPer);
		/*显示对应波形的界面*/
		InPutChangedCallbackof_combCVaveform();
	}
	else
	{
		QMessageBox::critical(NULL,
			"错误",
			"当前没有配置信息，CNonElectricCfg::m_pStNoElecData指针为空！");
	}
}
/*取消按键回调函数*/
void CNonElectricCfg::Cancel()
{
	QCloseEvent *event;
	closeEvent(event);
}


/*单击关闭按钮 */
void CNonElectricCfg::closeEvent(QCloseEvent *event)
{
	/*20220530修改。重新加载配置文档，用永久存储来更新内存中不用保存的信息，不弹框标识为true*/
	m_bIfInitOpenCfgFile = true;
	/*重新加载配置文件，从而更新内存与界面信息*/
	OpenCfg();
	close();
}

void CNonElectricCfg::InPutChangedCallbackof_combCVaveform()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	WAVE_TYPE wave = GetWaveType(ui.combCVaveform->currentIndex());
	m_pStNoElecData->m_stArrNoElecData[channel].m_enumWave = wave;
	/*先隐藏所有波形控件*/
	ui.widget1DCOutput->hide();
	ui.widget2DCOutput->hide();
	ui.widget1LadderOutput->hide();
	ui.widget2LadderOutput->hide();
	/*显示对应波形配置控件*/
	switch (wave)
	{
	case noElectricCfg::WAVE_DC:
		ui.widget1DCOutput->show();
		ui.widget2DCOutput->show();
		break;
	case noElectricCfg::WAVE_LADDER:
		ui.widget1LadderOutput->show();
		ui.widget2LadderOutput->show();
		break;
	default:
		break;
	}
}
void CNonElectricCfg::ApplyToAllChannel()
{
	stNoElecUiShowedData stDataTem;
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	stDataTem.m_enumWave = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_enumWave;
	stDataTem.m_fDcAmplitude = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fDcAmplitude;
	stDataTem.m_fLadderHigeAmplitude = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fLadderHigeAmplitude;
	stDataTem.m_fLadderLowAmplitude = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_fLadderLowAmplitude;
	stDataTem.m_u1LadderStartValue = m_pStNoElecData->m_stArrNoElecData[u1Channel].m_u1LadderStartValue;

	/*将临时结构体中的数据拷贝到所有通道*/
	for (quint8 channel = 0; channel < u1NOELECTRIC_SIGNAL_CHANNEL_COUNT; channel++)
	{
		m_pStNoElecData->m_stArrNoElecData[channel].m_enumWave = stDataTem.m_enumWave;
		m_pStNoElecData->m_stArrNoElecData[channel].m_fDcAmplitude = stDataTem.m_fDcAmplitude;
		m_pStNoElecData->m_stArrNoElecData[channel].m_fLadderHigeAmplitude = stDataTem.m_fLadderHigeAmplitude;
		m_pStNoElecData->m_stArrNoElecData[channel].m_fLadderLowAmplitude = stDataTem.m_fLadderLowAmplitude;
		m_pStNoElecData->m_stArrNoElecData[channel].m_u1LadderStartValue = stDataTem.m_u1LadderStartValue;
	}
}
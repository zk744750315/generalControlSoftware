#include "CElectricCfg.h"
#include <QFileDialog>	

using namespace electricCfg;

CElectricCfg::CElectricCfg(stElecFullData *pElecCfgData, QWidget *parent)
	: QWidget(parent)
	, m_pStElecData(pElecCfgData)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint);
	setAttribute(Qt::WA_DeleteOnClose);
	Init();
}

CElectricCfg::~CElectricCfg()
{
	if (NULL != m_oCfgOperator)
	{
		delete m_oCfgOperator;
		m_oCfgOperator = NULL;
	}
	/*ֻ��ָ��ָ��գ��ڴ��ɴ�����ʵ���Ķ����ͷ�*/
	if (NULL != m_pStElecData)
	{
		/*	delete [] m_pStNoElecData;*/
		m_pStElecData = NULL;
	}
}

/*��ʼ��CElectricCfgʵ��*/
void CElectricCfg::Init()
{
	///*��Ч������Ϣָ���ʼ��*/
	//m_pStElecData = NULL;
	m_strCfgFilePath = CfgPathDefault;
	/*��ʼ��INI�����ļ���д��*/
	m_oCfgOperator = NULL;
	/*��ʼ������ʼ��ʱ�״δ������ļ��������ʶΪ��*/
	m_bIfInitOpenCfgFile = true;
	m_bIfGetInfoFromUi = false;
	/*��ȡĬ�������ļ�*/
	OpenCfg();
	SetCallbackFunc();
}
/*���������ص�����*/
void CElectricCfg::SetCallbackFunc()
{
	connect(ui.btnSave, &QPushButton::clicked, this, &CElectricCfg::SaveCfg);
	connect(ui.btnSaveAs, &QPushButton::clicked, this, &CElectricCfg::SaveCfgAs);
	connect(ui.btnOpen, &QPushButton::clicked, this, &CElectricCfg::OpenCfg);
	connect(ui.btnCancel, &QPushButton::clicked, this, &CElectricCfg::Cancel);
	connect(ui.btnCfgApplyToAll, &QPushButton::clicked, this, &CElectricCfg::ApplyToAllChannel);
	connect(ui.combCfgChannel, SIGNAL(activated(int)), this, SLOT(CallfunctoChannelChanged()));
	connect(ui.combCVaveform, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combCVaveform()));
	connect(ui.spinDCAmplitude, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinDCAmplitude()));
	connect(ui.spinLadderFreshPer, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderFreshPer()));
	connect(ui.spinLadderOutH, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderOutH()));
	connect(ui.spinLadderOutL, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderOutL()));
	connect(ui.spinLadderOutStartValue, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinLadderOutStartValue()));
	connect(ui.spinACValidValue, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinACValidValue()));
	connect(ui.spinACFrequency, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinACFrequency()));
	connect(ui.spinPauseOutAmplitude, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinPauseOutAmplitude()));
	connect(ui.spinPauseOutFrequency, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinPauseOutFrequency()));
	connect(ui.spinPauseOutWidth, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinPauseOutWidth()));
	connect(ui.spin8kValidValue, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spin8kValidValue()));
}

void CElectricCfg::InPutChangedCallbackof_spinDCAmplitude()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fDcAmplitude = ui.spinDCAmplitude->value();
}
void CElectricCfg::InPutChangedCallbackof_spinLadderFreshPer()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_u4LadderFreshPer = ui.spinLadderFreshPer->value();
}
void CElectricCfg::InPutChangedCallbackof_spinLadderOutH()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fLadderOutH = ui.spinLadderOutH->value();
}
void CElectricCfg::InPutChangedCallbackof_spinLadderOutL()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fLadderOutL = ui.spinLadderOutL->value();
}
void CElectricCfg::InPutChangedCallbackof_spinLadderOutStartValue()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_u4LadderOutStartVal = ui.spinLadderOutStartValue->value();
}
/*20220531���ӣ����ݲ�ͬ���Σ��ý����е�ĳЩ�ؼ���ʾ��������*/
void CElectricCfg::InPutChangedCallbackof_combCVaveform()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	WAVE_TYPE wave = GetWaveType(ui.combCVaveform->currentIndex());
	m_pStElecData->m_stArrElecData[channel].m_enumWave = wave;
	/*���������в��οؼ�*/
	ui.widget1DCOutput->hide();
	ui.widget2DCOutput->hide();
	ui.widget1LadderOutput->hide();
	ui.widget2LadderOutput->hide();
	ui.widget1ACOutput->hide();
	ui.widget2ACOutput->hide();
	ui.widget1PauseOutput->hide();
	ui.widget2PauseOutput->hide();
	ui.widget18kOutput->hide();
	ui.widget28kOutput->hide();

	/*��ʾ��Ӧ�������ÿؼ�*/
	switch (wave)
	{
	case electricCfg::WAVE_DC:
		ui.widget1DCOutput->show();
		ui.widget2DCOutput->show();
		break;
	case electricCfg::WAVE_LADDER:
		ui.widget1LadderOutput->show();
		ui.widget2LadderOutput->show();
		break;
	case electricCfg::WAVE_AC:
		ui.widget1ACOutput->show();
		ui.widget2ACOutput->show();
		break;
	case electricCfg::WAVE_PALSE:
		ui.widget1PauseOutput->show();
		ui.widget2PauseOutput->show();
		break;
	case electricCfg::WAVE_8K:
		ui.widget18kOutput->show();
		ui.widget28kOutput->show();
		break;
	case electricCfg::WAVE_COUNT:
		break;
	default:
		break;
	}
}
void CElectricCfg::InPutChangedCallbackof_spinACValidValue()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fACValidVal = ui.spinACValidValue->value();
}
void CElectricCfg::InPutChangedCallbackof_spinACFrequency()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fACFrequency = ui.spinACFrequency->value();
}
void CElectricCfg::InPutChangedCallbackof_spinPauseOutAmplitude()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fPauseOutAmplitude = ui.spinPauseOutAmplitude->value();
}
void CElectricCfg::InPutChangedCallbackof_spinPauseOutFrequency()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fPauseOutFrequency = ui.spinPauseOutFrequency->value();
}
void CElectricCfg::InPutChangedCallbackof_spinPauseOutWidth()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_u4PauseOutWidth = ui.spinPauseOutWidth->value();
}
void CElectricCfg::InPutChangedCallbackof_spin8kValidValue()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStElecData->m_stArrElecData[channel].m_fSin8kValidVal = ui.spin8kValidValue->value();
}
void CElectricCfg::ApplyToAllChannel()
{
	stElecSignalDataUnit stData;
	quint8 u1ShowedChannel = ui.combCfgChannel->currentIndex();
	GetSignalDataUnit(stData, u1ShowedChannel);
	for (quint8 channel = 0; channel < u1ELECTRIC_SIGNAL_CHANNEL_COUNT; channel++)
	{
		SetSignalDataUnit(stData,channel);
	}
}
void CElectricCfg::GetSignalDataUnit(stElecSignalDataUnit& stCfgData, const quint8 &channel)
{
	stCfgData.m_enumWave = m_pStElecData->m_stArrElecData[channel].m_enumWave;
	stCfgData.m_fDcAmplitude = m_pStElecData->m_stArrElecData[channel].m_fDcAmplitude;
	stCfgData.m_u4LadderFreshPer = m_pStElecData->m_stArrElecData[channel].m_u4LadderFreshPer;
	stCfgData.m_fLadderOutH = m_pStElecData->m_stArrElecData[channel].m_fLadderOutH;
	stCfgData.m_fLadderOutL = m_pStElecData->m_stArrElecData[channel].m_fLadderOutL;
	stCfgData.m_u4LadderOutStartVal = m_pStElecData->m_stArrElecData[channel].m_u4LadderOutStartVal;
	stCfgData.m_fACValidVal = m_pStElecData->m_stArrElecData[channel].m_fACValidVal;
	stCfgData.m_fACFrequency = m_pStElecData->m_stArrElecData[channel].m_fACFrequency;
	stCfgData.m_fPauseOutAmplitude = m_pStElecData->m_stArrElecData[channel].m_fPauseOutAmplitude;
	stCfgData.m_fPauseOutFrequency = m_pStElecData->m_stArrElecData[channel].m_fPauseOutFrequency;
	stCfgData.m_u4PauseOutWidth = m_pStElecData->m_stArrElecData[channel].m_u4PauseOutWidth;
	stCfgData.m_fSin8kValidVal = m_pStElecData->m_stArrElecData[channel].m_fSin8kValidVal;
}

void CElectricCfg::SetSignalDataUnit(const stElecSignalDataUnit& stCfgData, const quint8 &channel)
{
	m_pStElecData->m_stArrElecData[channel].m_enumWave = stCfgData.m_enumWave;
	m_pStElecData->m_stArrElecData[channel].m_fDcAmplitude= stCfgData.m_fDcAmplitude;
	m_pStElecData->m_stArrElecData[channel].m_u4LadderFreshPer= stCfgData.m_u4LadderFreshPer;
	m_pStElecData->m_stArrElecData[channel].m_fLadderOutH= stCfgData.m_fLadderOutH;
	m_pStElecData->m_stArrElecData[channel].m_fLadderOutL= stCfgData.m_fLadderOutL;
	m_pStElecData->m_stArrElecData[channel].m_u4LadderOutStartVal= stCfgData.m_u4LadderOutStartVal;
	m_pStElecData->m_stArrElecData[channel].m_fACValidVal= stCfgData.m_fACValidVal;
	m_pStElecData->m_stArrElecData[channel].m_fACFrequency= stCfgData.m_fACFrequency;
	m_pStElecData->m_stArrElecData[channel].m_fPauseOutAmplitude= stCfgData.m_fPauseOutAmplitude;
	m_pStElecData->m_stArrElecData[channel].m_fPauseOutFrequency= stCfgData.m_fPauseOutFrequency;
	m_pStElecData->m_stArrElecData[channel].m_u4PauseOutWidth= stCfgData.m_u4PauseOutWidth;
	m_pStElecData->m_stArrElecData[channel].m_fSin8kValidVal= stCfgData.m_fSin8kValidVal;
}
/*���水���ص�����,QSetting��ĵ���ģʽ�޷��޸�ini����·�����侲̬����setPath()���Ѿ�������ʵ����������
����������ѡ��ÿ�α���ʱ����һ��QSettingʵ��������·����Ϊm_strCfgFilePath��*/
bool CElectricCfg::SaveCfg()
{
	SaveCfgDataFromMemoty();
	return true;
}
/*********************************************************************************
  * @brief  ��������
  * @param u1Channel:
  * @retval
  * @note
**********************************************************************************/
void CElectricCfg::SaveCfgDataFromMemoty()
{
	QString sectionIndex;
	stElecSignalDataUnit stData;
	for (quint8 u1Channel = 0; u1Channel < u1ELECTRIC_SIGNAL_CHANNEL_COUNT; u1Channel++)
	{
		GetSignalDataUnit(stData, u1Channel);
		sectionIndex = QString::number(u1Channel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[WAVE_FORM], QString::number(stData.m_enumWave));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[DC_AMPLITUDE], QString::number(stData.m_fDcAmplitude, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_FRESH_PER], QString::number(stData.m_u4LadderFreshPer));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_OUT_H], QString::number(stData.m_fLadderOutH, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_OUT_L], QString::number(stData.m_fLadderOutL, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[LADDER_OUT_START_VAL], QString::number(stData.m_u4LadderOutStartVal));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[AC_VALID_VAL], QString::number(stData.m_fACValidVal, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[AC_FREQUENCY], QString::number(stData.m_fACFrequency, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_AMPLITUDE], QString::number(stData.m_fPauseOutAmplitude, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_FREQUENCY], QString::number(stData.m_fPauseOutFrequency, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_WIDTH], QString::number(stData.m_u4PauseOutWidth));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[SIN_8K_VALID_VAL], QString::number(stData.m_fSin8kValidVal, 'f', 2));
		m_oCfgOperator->endGroup();
	}
	/*������ͨ���޹ص�ȫ��������Ϣ    �޴�����*/
	/*ͬ��*/
	m_oCfgOperator->sync();
}

/*���Ϊ�����ص��������߼����ȱ��棬�ڴ������ļ�*/
bool CElectricCfg::SaveCfgAs()
{
	QString m_strCfgFilePathCopyy = m_strCfgFilePath;
	/*���Ϊ.dat��ʽ*/
	m_strCfgFilePath = m_strCfgFilePath.replace("ini", "dat");
	m_strCfgFilePath = QFileDialog::getSaveFileName(NULL, tr("���Ϊ"), m_strCfgFilePath, "*.dat");
	/*��û��ѡ���ļ���֮��ر���ѡ���ļ��Ի��򣬻ָ������ļ�·��������ֱ�ӷ���*/
	if (0 == m_strCfgFilePath.length())
	{
		m_strCfgFilePath = m_strCfgFilePathCopyy;
		return false;
	}
	/*���������ļ�*/
	QFile file(m_strCfgFilePath);
	//QString filename1 = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.bmp *.jpg)")); //ѡ��·��
	/*����QSettingʵ��*/
	CreateFileIOer();
	/*���ڴ��е�����д�������ļ����û����ܻ��޸ĵ�ǰͨ����������Ϣû�е�����棬������Ҫ��ui���´�ͨ��������*/
	SaveCfgDataFromMemoty();
}
/*�������ļ������ص�����*/
bool CElectricCfg::OpenCfg()
{
	if (m_bIfInitOpenCfgFile)
	{
		/*m_bIfInitOpenCfgFileΪ���򲻵���Ŀ��أ��´ξͲ��ǳ�ʼ����Ĭ�������ļ�,ѡ���ļ��������ʶΪfalse*/
		m_bIfInitOpenCfgFile = false;
	}
	else
	{
		/*���������ļ�·��m_strCfgFilePath����ֹ��ѡ�������ļ��Ի���QFileDialog::getOpenFileName()����Ϊû��ѡ��
		�ļ����ؿ��ַ�������ʧ��һ�������ļ���·��*/
		QString m_strCfgFilePathCopy = m_strCfgFilePath;
		m_strCfgFilePath = QFileDialog::getOpenFileName(NULL, "ѡ���ļ�", m_strCfgFilePath, "*.ini *.dat");
		/*��û��ѡ���ļ���֮��ر���ѡ���ļ��Ի��򣬻ָ������ļ�·��������ֱ�ӷ���*/
		if (0 == m_strCfgFilePath.length())
		{
			m_strCfgFilePath = m_strCfgFilePathCopy;
			return false;
		}
	}
	if (ParseCfgFile(m_strCfgFilePath, m_pStElecData))
	{
		/*�����ɹ�����m_pStNoElecData�е���Ϣ���½���*/
		CallfunctoChannelChanged();
	}
	return true;
}
void CElectricCfg::CreateFileIOer()
{
	/*����QSettingʵ��*/
	if (NULL != m_oCfgOperator)
	{
		delete m_oCfgOperator;
		m_oCfgOperator = NULL;
	}
	m_oCfgOperator = new QSettings(m_strCfgFilePath, QSettings::IniFormat);
	/*���������ļ�operatorΪutf-8����*/
	m_oCfgOperator->setIniCodec("UTF-8");
}
/*���������ļ���Ӧ�������ﴴ��QSettings����*/
bool CElectricCfg::ParseCfgFile(const QString &strFileName, stElecFullData *pData)
{
	/*����QSettingʵ��*/
	CreateFileIOer();
	QString sectionIndex;
	stElecSignalDataUnit stData;
	for (quint8 iChannel = 0; iChannel < u1ELECTRIC_SIGNAL_CHANNEL_COUNT; iChannel++)
	{
		sectionIndex = QString::number(iChannel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		/*���Σ���ȡ������Ĭ��Ϊֱ��*/
		stData.m_enumWave = GetWaveType(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[WAVE_FORM], WaveFormDefaultValue).toInt());
		stData.m_fDcAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DC_AMPLITUDE], DCAmplitudeDefaultValue).toFloat();
		stData.m_u4LadderFreshPer = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_FRESH_PER], LadderFreshPerDefaultValue).toInt();
		stData.m_fLadderOutH = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_OUT_H], LadderOutHDefaultValue).toFloat();
		stData.m_fLadderOutL = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_OUT_L], LadderOutLDefaultValue).toFloat();
		stData.m_u4LadderOutStartVal = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_OUT_START_VAL], LadderOutStartValueDefaultValue).toInt();
		stData.m_fACValidVal = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[AC_VALID_VAL], ACValidDefaultValue).toFloat();
		stData.m_fACFrequency = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[AC_FREQUENCY], ACFrequencyDefaultValue).toFloat();
		stData.m_fPauseOutAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_AMPLITUDE], PauseOutAmplitudeDefaultValue).toFloat();
		stData.m_fPauseOutFrequency = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_FREQUENCY], PauseOutFrequencyDefaultValue).toFloat();
		stData.m_u4PauseOutWidth = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_WIDTH], PauseOutWidthDefaultValue).toInt();
		stData.m_fSin8kValidVal = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[SIN_8K_VALID_VAL], Sin8kValidDefaultValue).toFloat();
		m_oCfgOperator->endGroup();
		/*���ص��ڴ�*/
		SetSignalDataUnit(stData, iChannel);
	}
	/*������ͨ���޹ص�ȫ��������Ϣ*/
	/*ͬ��*/
	m_oCfgOperator->sync();
	return true;
}
/*����ͨ���Ļص�����,�ر�Ӧ�õ�ȫ�ֿ��أ�����ui����*/
void CElectricCfg::CallfunctoChannelChanged()
{
	quint8 u1ShowedChannel = ui.combCfgChannel->currentIndex();
	if (NULL != m_pStElecData)
	{
		ui.combCVaveform->setCurrentIndex(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_enumWave);
		ui.spinDCAmplitude->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fDcAmplitude);
		ui.spinLadderFreshPer->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_u4LadderFreshPer);
		ui.spinLadderOutH->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fLadderOutH);
		ui.spinLadderOutL->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fLadderOutL);
		ui.spinLadderOutStartValue->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_u4LadderOutStartVal);
		ui.spinACValidValue->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fACValidVal);
		ui.spinACFrequency->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fACFrequency);
		ui.spinPauseOutAmplitude->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fPauseOutAmplitude);
		ui.spinPauseOutFrequency->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fPauseOutFrequency);
		ui.spinPauseOutWidth->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_u4PauseOutWidth);
		ui.spin8kValidValue->setValue(m_pStElecData->m_stArrElecData[u1ShowedChannel].m_fSin8kValidVal);

		InPutChangedCallbackof_combCVaveform();
	}
	else
	{
		QMessageBox::critical(NULL,
			"����",
			"��ǰû��������Ϣ��CElectricCfg::m_pStNoElecDataָ��Ϊ�գ�");
	}
}
/*ȡ�������ص�����*/
void CElectricCfg::Cancel()
{
	QCloseEvent *event;
	closeEvent(event);
}


/*�����رհ�ť �޸�m_bApplyToAll��ֵ*/
void CElectricCfg::closeEvent(QCloseEvent *event)
{
	m_bIfInitOpenCfgFile = true;
	/*���¼��������ļ����Ӷ������ڴ��������Ϣ*/
	OpenCfg();
	close();
}
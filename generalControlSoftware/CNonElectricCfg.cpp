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
	/*ֻ��ָ��ָ��գ��ڴ��ɴ�����ʵ���Ķ����ͷ�*/
	if (NULL != m_pStNoElecData)
	{
		/*	delete [] m_pStNoElecData;*/
		m_pStNoElecData = NULL;
	}
}


/*��ʼ��CNonElectricCfgʵ��*/
void CNonElectricCfg::Init()
{
	//*Ĭ��·����ʼ��*/
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

/*�Ի����������ݷ����仯���ص��������¶�Ӧ�ڴ�����*/
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

/*���水���ص�����,QSetting��ĵ���ģʽ�޷��޸�ini����·�����侲̬����setPath()���Ѿ�������ʵ����������
����������ѡ��ÿ�α���ʱ����һ��QSettingʵ��������·����Ϊm_strCfgFilePath��*/
bool CNonElectricCfg::SaveCfg()
{
	SaveCfgDataFromMemoty();
	return true;
}
/*********************************************************************************
  * @brief  ��������
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
	/*������ͨ���޹ص�ȫ��������Ϣ*/
	iNoEleSampPeriod = m_pStNoElecData->m_iNoEleSampPeriod;
	iLadderwaveFreshPer = m_pStNoElecData->m_iLadderwaveFreshPer;
	m_oCfgOperator->beginGroup(CFGFILE_GLOBAL_SECTION);
	m_oCfgOperator->setValue(arrCFG_DATAGLOBAL_NAME[NOELEC_SAMPLE_PERIOD], QString::number(iNoEleSampPeriod));
	m_oCfgOperator->setValue(arrCFG_DATAGLOBAL_NAME[LADDERWAVE_FRESH_PERIOD], QString::number(iLadderwaveFreshPer));
	m_oCfgOperator->endGroup();
	/*ͬ��*/
	m_oCfgOperator->sync();
}

/*���Ϊ�����ص��������߼����ȱ��棬�ڴ������ļ�*/
bool CNonElectricCfg::SaveCfgAs()
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
	/*����QSettingʵ��*/
	CreateFileIOer();
	/*���ڴ��е�����д�������ļ�*/
	SaveCfgDataFromMemoty();
	return true;
}
/*�������ļ������ص�����*/
bool CNonElectricCfg::OpenCfg()
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
	if (ParseCfgFile(m_strCfgFilePath, m_pStNoElecData))
	{
		/*�����ɹ�����m_pStNoElecData�е���Ϣ���½���*/
		CallfunctoChannelChanged();
	}
	return true;
}
void CNonElectricCfg::CreateFileIOer()
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
bool CNonElectricCfg::ParseCfgFile(const QString &strFileName, stNoElecFullData *pData)
{
	/*����QSettingʵ��*/
	CreateFileIOer();
	QString sectionIndex;
	quint8 u1WaveType;
	for (quint8 iChannel = 0; iChannel < u1NOELECTRIC_SIGNAL_CHANNEL_COUNT; iChannel++)
	{
		sectionIndex = QString::number(iChannel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		/*���Σ���ȡ������Ĭ��Ϊֱ��*/
		u1WaveType = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[WAVE_FORM], WaveFormDefaultValue).toInt();
		pData->m_stArrNoElecData[iChannel].m_enumWave = GetWaveType(u1WaveType);
		/*ֱ�����η�ֵ����ȡ������Ĭ��Ϊ0*/
 		pData->m_stArrNoElecData[iChannel].m_fDcAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DC_AMPLITUDE], DCAmplitudeDefaultValue).toFloat();
		pData->m_stArrNoElecData[iChannel].m_fLadderHigeAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_H], LadderwaveOutHDefaultValue).toFloat();
		pData->m_stArrNoElecData[iChannel].m_fLadderLowAmplitude = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_L], LadderwaveOutLDefaultValue).toFloat();
		pData->m_stArrNoElecData[iChannel].m_u1LadderStartValue = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[LADDER_START_VALUE], LadderwaveOutStartfaultValue).toInt();
		m_oCfgOperator->endGroup();
	}
	/*������ͨ���޹ص�ȫ��������Ϣ*/
	m_oCfgOperator->beginGroup(CFGFILE_GLOBAL_SECTION);
	/*�ǵ����������ڣ��������Ļ�Ĭ��Ϊ1*/
	pData->m_iNoEleSampPeriod = m_oCfgOperator->value(arrCFG_DATAGLOBAL_NAME[NOELEC_SAMPLE_PERIOD], NoEleSampPeriodDefaultValue).toInt();
	/*���ݲ�ˢ�����ڣ���ȡ������Ĭ��Ϊ1*/
	pData->m_iLadderwaveFreshPer = m_oCfgOperator ->value(arrCFG_DATAGLOBAL_NAME[LADDERWAVE_FRESH_PERIOD], LadderwaveFreshPerDefaultValue).toInt();
	m_oCfgOperator->endGroup();
	/*ͬ��*/
	m_oCfgOperator->sync();
	return true;
}
/*����ͨ���Ļص�����,�ر�Ӧ�õ�ȫ�ֿ��أ�����ui����*/
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
		/*ȫ�ֱ���Ҳ�����������*/
		ui.spinNoEleCheckSampPer->setValue(m_pStNoElecData->m_iNoEleSampPeriod);
		ui.spinLadderwaveFreshPer->setValue(m_pStNoElecData->m_iLadderwaveFreshPer);
		/*��ʾ��Ӧ���εĽ���*/
		InPutChangedCallbackof_combCVaveform();
	}
	else
	{
		QMessageBox::critical(NULL,
			"����",
			"��ǰû��������Ϣ��CNonElectricCfg::m_pStNoElecDataָ��Ϊ�գ�");
	}
}
/*ȡ�������ص�����*/
void CNonElectricCfg::Cancel()
{
	QCloseEvent *event;
	closeEvent(event);
}


/*�����رհ�ť */
void CNonElectricCfg::closeEvent(QCloseEvent *event)
{
	/*20220530�޸ġ����¼��������ĵ��������ô洢�������ڴ��в��ñ������Ϣ���������ʶΪtrue*/
	m_bIfInitOpenCfgFile = true;
	/*���¼��������ļ����Ӷ������ڴ��������Ϣ*/
	OpenCfg();
	close();
}

void CNonElectricCfg::InPutChangedCallbackof_combCVaveform()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	WAVE_TYPE wave = GetWaveType(ui.combCVaveform->currentIndex());
	m_pStNoElecData->m_stArrNoElecData[channel].m_enumWave = wave;
	/*���������в��οؼ�*/
	ui.widget1DCOutput->hide();
	ui.widget2DCOutput->hide();
	ui.widget1LadderOutput->hide();
	ui.widget2LadderOutput->hide();
	/*��ʾ��Ӧ�������ÿؼ�*/
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

	/*����ʱ�ṹ���е����ݿ���������ͨ��*/
	for (quint8 channel = 0; channel < u1NOELECTRIC_SIGNAL_CHANNEL_COUNT; channel++)
	{
		m_pStNoElecData->m_stArrNoElecData[channel].m_enumWave = stDataTem.m_enumWave;
		m_pStNoElecData->m_stArrNoElecData[channel].m_fDcAmplitude = stDataTem.m_fDcAmplitude;
		m_pStNoElecData->m_stArrNoElecData[channel].m_fLadderHigeAmplitude = stDataTem.m_fLadderHigeAmplitude;
		m_pStNoElecData->m_stArrNoElecData[channel].m_fLadderLowAmplitude = stDataTem.m_fLadderLowAmplitude;
		m_pStNoElecData->m_stArrNoElecData[channel].m_u1LadderStartValue = stDataTem.m_u1LadderStartValue;
	}
}
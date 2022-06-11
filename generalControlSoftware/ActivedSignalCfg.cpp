#include "ActivedSignalCfg.h"
#include <QFileDialog>	

using namespace activeSignalCfg;
CActivedSignalCfg::CActivedSignalCfg(stActDataUnit *pActiveCfgData, QWidget *parent)
	: QWidget(parent)
	, m_pStActiveSignalData(pActiveCfgData)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint);
	setAttribute(Qt::WA_DeleteOnClose);
	Init();
}

CActivedSignalCfg::~CActivedSignalCfg()
{
	if (NULL != m_oCfgOperator)
	{
		delete m_oCfgOperator;
		m_oCfgOperator = NULL;
	}
	/*ֻ��ָ��ָ��գ��ڴ��ɴ�����ʵ���Ķ����ͷ�*/
	if (NULL != m_pStActiveSignalData)
	{
	/*	delete [] m_pStActiveSignalData;*/
		m_pStActiveSignalData = NULL;
	}
}

/*��ʼ��CActivedSignalCfgʵ��*/ 
void CActivedSignalCfg::Init()
{	
	///*��Ч������Ϣָ���ʼ��*/
	//m_pStActiveSignalData = NULL;
	m_strCfgFilePath = CfgPathDefault;
	/*��ʼ��INI�����ļ���д��*/
	m_oCfgOperator = NULL;
	/*��ʼ������ʼ��ʱ�״δ������ļ��������ʶΪ��*/
	m_bIfInitOpenCfgFile = true;
	/*��ȡĬ�������ļ�*/
	OpenCfg();
	SetCallbackFunc();
}
/*���������ص�����*/
void CActivedSignalCfg::SetCallbackFunc()
{
	connect(ui.btnSave, &QPushButton::clicked, this, &CActivedSignalCfg::SaveCfg);
	connect(ui.btnSaveAs, &QPushButton::clicked, this, &CActivedSignalCfg::SaveCfgAs);
	connect(ui.btnOpen, &QPushButton::clicked, this, &CActivedSignalCfg::OpenCfg);
	connect(ui.btnCancel, &QPushButton::clicked, this, &CActivedSignalCfg::Cancel);
	connect(ui.combCfgChannel, SIGNAL(activated(int)), this, SLOT(CallfunctoChannelChanged()));
	connect(ui.btnCfgApplyToAll, &QPushButton::clicked, this, &CActivedSignalCfg::ApplyToAllChannel);
	/*�����е��������ֵ�����仯���򽫶�Ӧ�ı仯�������ڴ���,20200530�޸�*/
	connect(ui.spinBoxCurrent, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinBoxCurrent()));
	connect(ui.spinBoxVoltage, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinBoxVoltage()));
}

/*�Ի����������ݷ����仯���ص��������¶�Ӧ�ڴ�����*/
void CActivedSignalCfg::InPutChangedCallbackof_spinBoxCurrent()
{
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	m_pStActiveSignalData[u1Channel].m_fCurrnet = ui.spinBoxCurrent->value();
}

void CActivedSignalCfg::InPutChangedCallbackof_spinBoxVoltage()
{
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	m_pStActiveSignalData[u1Channel].m_fVoltage = ui.spinBoxVoltage->value();
}
/*���水���ص�����,QSetting��ĵ���ģʽ�޷��޸�ini����·�����侲̬����setPath()���Ѿ�������ʵ����������
����������ѡ��ÿ�α���ʱ����һ��QSettingʵ��������·����Ϊm_strCfgFilePath��*/
bool CActivedSignalCfg::SaveCfg()
{
	/*20220530�޸�*/
	SaveCfgDataFromMemoty();
	return true;
}
/*********************************************************************************
  * @brief  ��������
  * @param u1Channel:
  * @retval
  * @note
**********************************************************************************/
void CActivedSignalCfg::SaveCfgDataFromMemoty()
{
	QString sectionIndex;
	float strCcurrnet;
	float strVoltage;
	for (quint8 u1Channel = 0; u1Channel < u1ACTIVE_SIGNAL_CHANNEL_COUNT; u1Channel++)
	{
		sectionIndex = QString::number(u1Channel);
		strCcurrnet = m_pStActiveSignalData[u1Channel].m_fCurrnet;
		strVoltage = m_pStActiveSignalData[u1Channel].m_fVoltage;
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[CURRENT], QString::number(strCcurrnet, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[VOLTAGE], QString::number(strVoltage, 'f', 2));
		m_oCfgOperator->endGroup();
	}
	/*ͬ��*/
	m_oCfgOperator->sync();
}

/*���Ϊ�����ص��������߼����������ڴ��е����ݱ��浽�����ļ�*/
bool CActivedSignalCfg::SaveCfgAs()
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
bool CActivedSignalCfg::OpenCfg()
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

	if (ParseCfgFile(m_strCfgFilePath, m_pStActiveSignalData))
	{
		/*�����ɹ�����m_pStActiveSignalData�����е���Ϣ���½���*/
		CallfunctoChannelChanged();
		/*������*/
	}
	return true;
}
void CActivedSignalCfg::CreateFileIOer()
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
bool CActivedSignalCfg::ParseCfgFile(const QString &strFileName, stActDataUnit arrData[])
{
	/*����QSettingʵ��*/
	CreateFileIOer();
	QString sectionIndex;
	for (quint8 iChannel = 0; iChannel < u1ACTIVE_SIGNAL_CHANNEL_COUNT; iChannel++)
	{
		sectionIndex = QString::number(iChannel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		/*��������ȡ������Ĭ��Ϊ0*/
		arrData[iChannel].m_fCurrnet = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CURRENT], currentDefaultValue).toFloat();
		/*��ѹ����ȡ������Ĭ��Ϊ25*/
		arrData[iChannel].m_fVoltage = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[VOLTAGE], voltageDefaultValue).toFloat();
		m_oCfgOperator->endGroup();
	}
	/*ͬ��*/
	m_oCfgOperator->sync();
	return true;
}
/*����ͨ���Ļص�����,�ر�Ӧ�õ�ȫ�ֿ��أ�����ui����*/
void CActivedSignalCfg::CallfunctoChannelChanged()
{
	quint8 u1ShowedChannel = ui.combCfgChannel->currentIndex();
	if (NULL!=m_pStActiveSignalData)
	{
		ui.spinBoxCurrent->setValue(m_pStActiveSignalData[u1ShowedChannel].m_fCurrnet);
		ui.spinBoxVoltage->setValue(m_pStActiveSignalData[u1ShowedChannel].m_fVoltage);
	}
	else 
	{
		QMessageBox::critical(NULL,
			"����",
			"��ǰû��������Ϣ��CActivedSignalCfg::m_pStActiveSignalDataָ��Ϊ�գ�");
	}
}
/*ȡ�������ص�����*/
void CActivedSignalCfg::Cancel()
{
	QCloseEvent *event;
	closeEvent(event);
}


/*�����رհ�ť*/
void CActivedSignalCfg::closeEvent(QCloseEvent *event)
{
	/*20220530�޸ġ����¼��������ĵ��������ô洢�������ڴ��в��ñ������Ϣ���������ʶΪtrue*/
	m_bIfInitOpenCfgFile = true;
	/*���¼��������ļ����Ӷ������ڴ��������Ϣ*/
	OpenCfg();
	close();
}
/*����ǰ��ʾ��ͨ����Ϣ����������ͨ��*/
void CActivedSignalCfg::ApplyToAllChannel()
{
	stActDataUnit stDataTem;
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	stDataTem.m_fCurrnet = m_pStActiveSignalData[u1Channel].m_fCurrnet;
	stDataTem.m_fVoltage = m_pStActiveSignalData[u1Channel].m_fVoltage;
	/*����ʱ�ṹ���е����ݿ���������ͨ��*/
	for (quint8 channel = 0; channel < u1ACTIVE_SIGNAL_CHANNEL_COUNT; channel++)
	{
		m_pStActiveSignalData[channel].m_fCurrnet = stDataTem.m_fCurrnet;
		m_pStActiveSignalData[channel].m_fVoltage = stDataTem.m_fVoltage;
	}
}
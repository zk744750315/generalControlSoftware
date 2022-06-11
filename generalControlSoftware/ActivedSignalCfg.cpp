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
	/*只把指针指向空，内存由创建此实例的对象释放*/
	if (NULL != m_pStActiveSignalData)
	{
	/*	delete [] m_pStActiveSignalData;*/
		m_pStActiveSignalData = NULL;
	}
}

/*初始化CActivedSignalCfg实例*/ 
void CActivedSignalCfg::Init()
{	
	///*有效数据信息指针初始化*/
	//m_pStActiveSignalData = NULL;
	m_strCfgFilePath = CfgPathDefault;
	/*初始化INI配置文件读写类*/
	m_oCfgOperator = NULL;
	/*初始化，初始化时首次打开配置文件不弹框标识为真*/
	m_bIfInitOpenCfgFile = true;
	/*读取默认配置文件*/
	OpenCfg();
	SetCallbackFunc();
}
/*关联按键回调函数*/
void CActivedSignalCfg::SetCallbackFunc()
{
	connect(ui.btnSave, &QPushButton::clicked, this, &CActivedSignalCfg::SaveCfg);
	connect(ui.btnSaveAs, &QPushButton::clicked, this, &CActivedSignalCfg::SaveCfgAs);
	connect(ui.btnOpen, &QPushButton::clicked, this, &CActivedSignalCfg::OpenCfg);
	connect(ui.btnCancel, &QPushButton::clicked, this, &CActivedSignalCfg::Cancel);
	connect(ui.combCfgChannel, SIGNAL(activated(int)), this, SLOT(CallfunctoChannelChanged()));
	connect(ui.btnCfgApplyToAll, &QPushButton::clicked, this, &CActivedSignalCfg::ApplyToAllChannel);
	/*界面中的输入框数值发生变化，则将对应的变化更新再内存中,20200530修改*/
	connect(ui.spinBoxCurrent, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinBoxCurrent()));
	connect(ui.spinBoxVoltage, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinBoxVoltage()));
}

/*对话框输入数据发生变化，回调函数更新对应内存数据*/
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
/*保存按键回调函数,QSetting类的单例模式无法修改ini保存路径，其静态函数setPath()对已经创建的实例不起作用
，所以这里选择每次保存时创建一个QSetting实例，保存路径看为m_strCfgFilePath。*/
bool CActivedSignalCfg::SaveCfg()
{
	/*20220530修改*/
	SaveCfgDataFromMemoty();
	return true;
}
/*********************************************************************************
  * @brief  保存配置
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
	/*同步*/
	m_oCfgOperator->sync();
}

/*另存为按键回调函数，逻辑：将运行内存中的数据保存到本地文件*/
bool CActivedSignalCfg::SaveCfgAs()
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
bool CActivedSignalCfg::OpenCfg()
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

	if (ParseCfgFile(m_strCfgFilePath, m_pStActiveSignalData))
	{
		/*解析成功，将m_pStActiveSignalData数组中的信息更新界面*/
		CallfunctoChannelChanged();
		/*将配置*/
	}
	return true;
}
void CActivedSignalCfg::CreateFileIOer()
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
bool CActivedSignalCfg::ParseCfgFile(const QString &strFileName, stActDataUnit arrData[])
{
	/*创建QSetting实例*/
	CreateFileIOer();
	QString sectionIndex;
	for (quint8 iChannel = 0; iChannel < u1ACTIVE_SIGNAL_CHANNEL_COUNT; iChannel++)
	{
		sectionIndex = QString::number(iChannel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		/*电流，读取不到则默认为0*/
		arrData[iChannel].m_fCurrnet = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CURRENT], currentDefaultValue).toFloat();
		/*电压，读取不到则默认为25*/
		arrData[iChannel].m_fVoltage = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[VOLTAGE], voltageDefaultValue).toFloat();
		m_oCfgOperator->endGroup();
	}
	/*同步*/
	m_oCfgOperator->sync();
	return true;
}
/*更改通道的回调函数,关闭应用到全局开关，更新ui界面*/
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
			"错误",
			"当前没有配置信息，CActivedSignalCfg::m_pStActiveSignalData指针为空！");
	}
}
/*取消按键回调函数*/
void CActivedSignalCfg::Cancel()
{
	QCloseEvent *event;
	closeEvent(event);
}


/*单击关闭按钮*/
void CActivedSignalCfg::closeEvent(QCloseEvent *event)
{
	/*20220530修改。重新加载配置文档，用永久存储来更新内存中不用保存的信息，不弹框标识为true*/
	m_bIfInitOpenCfgFile = true;
	/*重新加载配置文件，从而更新内存与界面信息*/
	OpenCfg();
	close();
}
/*将当前显示的通道信息拷贝给所有通道*/
void CActivedSignalCfg::ApplyToAllChannel()
{
	stActDataUnit stDataTem;
	quint8 u1Channel = ui.combCfgChannel->currentIndex();
	stDataTem.m_fCurrnet = m_pStActiveSignalData[u1Channel].m_fCurrnet;
	stDataTem.m_fVoltage = m_pStActiveSignalData[u1Channel].m_fVoltage;
	/*将临时结构体中的数据拷贝到所有通道*/
	for (quint8 channel = 0; channel < u1ACTIVE_SIGNAL_CHANNEL_COUNT; channel++)
	{
		m_pStActiveSignalData[channel].m_fCurrnet = stDataTem.m_fCurrnet;
		m_pStActiveSignalData[channel].m_fVoltage = stDataTem.m_fVoltage;
	}
}
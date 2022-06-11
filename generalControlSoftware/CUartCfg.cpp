#include "CUartCfg.h"
#include <QFileDialog>	

using namespace uartCfg;

CUartCfg::CUartCfg(stUartFullData *pElecCfgData, QWidget *parent)
	: QWidget(parent)
	, m_pStUartData(pElecCfgData)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint);
	setAttribute(Qt::WA_DeleteOnClose);
	Init();
}

CUartCfg::~CUartCfg()
{
	if (NULL != m_oCfgOperator)
	{
		delete m_oCfgOperator;
		m_oCfgOperator = NULL;
	}
	/*ֻ��ָ��ָ��գ��ڴ��ɴ�����ʵ���Ķ����ͷ�*/
	if (NULL != m_pStUartData)
	{
		/*	delete [] m_pStNoElecData;*/
		m_pStUartData = NULL;
	}
}

/*��ʼ��CUartCfgʵ��*/
void CUartCfg::Init()
{
	///*��Ч������Ϣָ���ʼ��*/
	//m_pStUartData = NULL;
	m_strCfgFilePath = CfgPathDefault;
	/*��ʼ��INI�����ļ���д��*/
	m_oCfgOperator = NULL;
	/*��ʼ������ʼ��ʱ�״δ������ļ��������ʶΪ��*/
	m_bIfInitOpenCfgFile = true;
	m_bIfGetInfoFromUi = false;
	InsertBuadrate();
	InsertStopbitLen();
	/*��ȡĬ�������ļ�*/
	OpenCfg();
	SetCallbackFunc();
}
void CUartCfg::InsertBuadrate()
{
	m_mapBaudIndex.insert(922, 0);
	m_mapBaudIndex.insert(461, 1);
	m_mapBaudIndex.insert(230, 2);
	m_mapBaudIndex.insert(115, 3);
}
void CUartCfg::InsertStopbitLen()
{
	m_mapStopbitLen.insert(1* StopbitLenGain, 0);
	m_mapStopbitLen.insert(1.5 * StopbitLenGain, 1);
	m_mapStopbitLen.insert(2 * StopbitLenGain, 2);
}
/*���������ص�����*/
void CUartCfg::SetCallbackFunc()
{
	connect(ui.btnSave, &QPushButton::clicked, this, &CUartCfg::SaveCfg);
	connect(ui.btnSaveAs, &QPushButton::clicked, this, &CUartCfg::SaveCfgAs);
	connect(ui.btnOpen, &QPushButton::clicked, this, &CUartCfg::OpenCfg);
	connect(ui.btnCancel, &QPushButton::clicked, this, &CUartCfg::Cancel);
	connect(ui.btnCfgApplyToAll, &QPushButton::clicked, this, &CUartCfg::ApplyToAllChannel);
	connect(ui.combCfgChannel, SIGNAL(activated(int)), this, SLOT(CallfunctoChannelChanged()));
	connect(ui.combInterfaceType, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combInterfaceType()));
	connect(ui.combWorkMode, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combWorkMode()));
	connect(ui.combBaudRate, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combBaudRate()));
	connect(ui.combCheckType, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combCheckType()));
	connect(ui.combStopBitLen, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_combStopBitLen()));
	connect(ui.radioDoubleRedundancy, SIGNAL(clicked()), this, SLOT(InPutChangedCallbackof_radioDoubleRedundancy()));
	connect(ui.comboPauseType, SIGNAL(activated(int)), this, SLOT(InPutChangedCallbackof_comboPauseType()));
	connect(ui.lineCMDHeaderFormat, SIGNAL(editingFinished()), this, SLOT(InPutChangedCallbackof_lineCMDHeaderFormat()));
	connect(ui.spinSendDataLen, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinSendDataLen()));
	connect(ui.spinFrameNumPos, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinFrameNumPos()));
	connect(ui.spinPauseWidth, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinPauseWidth()));
	connect(ui.spinDigitOutPer, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinDigitOutPer()));
	connect(ui.spinPauseOutPer, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinPauseOutPer()));
	connect(ui.spinCmdOutPer, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinCmdOutPer()));
	connect(ui.spinCmdOutCount, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinCmdOutCount()));
	connect(ui.spinReceiveDataLen, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinReceiveDataLen()));
	connect(ui.spinPauseOutCount, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinPauseOutCount()));
	connect(ui.pushDigitalEditor, &QPushButton::clicked, this, &CUartCfg::InPutChangedCallbackof_pushDigitalEditor);
	connect(ui.pushCmdEditor1, &QPushButton::clicked, this, &CUartCfg::InPutChangedCallbackof_pushCmdEditor1);
	connect(ui.pushCmdEditor2, &QPushButton::clicked, this, &CUartCfg::InPutChangedCallbackof_pushCmdEditor2);
}

void CUartCfg::InPutChangedCallbackof_combInterfaceType()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	UART_RECEIVE_SEND_TYPE enumInterfaceType  = GetInterfaceType(ui.combInterfaceType->currentIndex());
	m_pStUartData->m_stArrUartData[channel].m_enumInterfaceType = enumInterfaceType;
}
void CUartCfg::InPutChangedCallbackof_combWorkMode()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	UART_WORKMODE enumWorkmodeType = GetWorkmodeType(ui.combWorkMode->currentIndex());
	m_pStUartData->m_stArrUartData[channel].m_enumInterfaceWorkmode = enumWorkmodeType;
	/*������ģ�����еĿؼ����ٸ��ݹ���ģʽenumWorkmodeType��ʾһЩ��Ҫ��ʾ�Ŀؼ�*/
	ui.widget1SendPause_SendCmd_Send_ReceiveCmd->hide();
	ui.widget2SendPause_SendCmd_Send->hide();
	ui.widget3SendPause_SendCmd_Send->hide();
	ui.widget4SendPause_Receive->hide();
	ui.widget5SendPause_ReceivePause->hide();
	ui.widget6SendCmd->hide();
	ui.widget7Send->hide();
	ui.widget8ReceivePause->hide();
	ui.widget9ReceiveCmd->hide();
	ui.widget10ReceiveCmd->hide();
	ui.widget11ReceiveCmd->hide();
	ui.widget12ReceiveCmd->hide();
	ui.widget13ReceivePause_ReceiveCmd_Receive->hide();
	ui.widget14ReceivePause->hide();
	/*ѡ������ʾ*/
	switch (enumWorkmodeType)
	{
	case uartCfg::SEND_RESPONSED_TO_PAUSE:
		ui.widget1SendPause_SendCmd_Send_ReceiveCmd->show();
		ui.widget2SendPause_SendCmd_Send->show();
		ui.widget3SendPause_SendCmd_Send->show();
		ui.widget4SendPause_Receive->show();
		ui.widget5SendPause_ReceivePause->show();
		break;
	case uartCfg::SEND_RESPONSED_TO_CMD:
		ui.widget1SendPause_SendCmd_Send_ReceiveCmd->show();
		ui.widget2SendPause_SendCmd_Send->show();
		ui.widget3SendPause_SendCmd_Send->show();
		ui.widget6SendCmd->show();
		break;
	case uartCfg::SEND_CYCLIC:
		ui.widget1SendPause_SendCmd_Send_ReceiveCmd->show();
		ui.widget2SendPause_SendCmd_Send->show();
		ui.widget3SendPause_SendCmd_Send->show();
		ui.widget7Send->show();
		break;

	case uartCfg::RECEIVE_WITH_PAUSE:
		ui.widget13ReceivePause_ReceiveCmd_Receive->show();
		ui.widget14ReceivePause->show();
		ui.widget5SendPause_ReceivePause->show();
		break;
	case uartCfg::RECEIVE_WITH_CMD:
		ui.widget10ReceiveCmd->show();
		ui.widget11ReceiveCmd->show();
		ui.widget12ReceiveCmd->show();
		ui.widget13ReceivePause_ReceiveCmd_Receive->show();
		ui.widget1SendPause_SendCmd_Send_ReceiveCmd->show();
		break;
	case uartCfg::RECEIVE_PASSIVELY:
		ui.widget13ReceivePause_ReceiveCmd_Receive->show();
		break;
	case uartCfg::STOP_WORK:
		break;
	case uartCfg::WORKMODE_COUNT:
		break;
	default:					/*����Ϊ������Ӧ*/
		ui.widget1SendPause_SendCmd_Send_ReceiveCmd->show();
		ui.widget2SendPause_SendCmd_Send->show();
		ui.widget3SendPause_SendCmd_Send->show();
		ui.widget4SendPause_Receive->show();
		ui.widget5SendPause_ReceivePause->show();
		break;
	}
}
void CUartCfg::InPutChangedCallbackof_combBaudRate()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	float fBaudRate = ui.combBaudRate->currentText().replace(" kbs", "").toFloat();
	m_pStUartData->m_stArrUartData[channel].m_fInterfaceBaudRate = fBaudRate;
	//m_pStUartData;
}
void CUartCfg::InPutChangedCallbackof_combCheckType()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	UART_CHENK_TYPE enumCheckType = GetCheckType(ui.combCheckType->currentIndex());
	m_pStUartData->m_stArrUartData[channel].m_enumInterfaceCheckType = enumCheckType;
}
void CUartCfg::InPutChangedCallbackof_combStopBitLen()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	float StopbitLen = ui.combStopBitLen->currentText().replace(" λ", "").toFloat();
	m_pStUartData->m_stArrUartData[channel].m_fInterfaceStopbitLen = StopbitLen;
}
void CUartCfg::InPutChangedCallbackof_radioDoubleRedundancy()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_bInterfaceDoubleDundancy = ui.radioDoubleRedundancy->isChecked();
}
void CUartCfg::InPutChangedCallbackof_spinSendDataLen()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4SendDataLen = ui.spinSendDataLen->value();
}
void CUartCfg::InPutChangedCallbackof_spinFrameNumPos()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4FrameNumPos = ui.spinFrameNumPos->value();
}
void CUartCfg::InPutChangedCallbackof_comboPauseType()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	PAUSE_TYPE enumPauseType = GetPauseType(ui.comboPauseType->currentIndex());
	m_pStUartData->m_stArrUartData[channel].m_enumPauseType = enumPauseType;
}
void CUartCfg::InPutChangedCallbackof_spinPauseWidth()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4PauseWidth = ui.spinPauseWidth->value();
}
void CUartCfg::InPutChangedCallbackof_lineCMDHeaderFormat()
{
	quint8 channel = ui.combCfgChannel->currentIndex(); 
	QString strHeader = ui.lineCMDHeaderFormat->text();
	uchar *pTem = m_pStUartData->m_stArrUartData[channel].m_pCmdHeaderFormat;
	for (int i = 0; i < CmdHeaderLen*2;)
	{

		*m_pStUartData->m_stArrUartData[channel].m_pCmdHeaderFormat++ = strHeader.mid(i, 2).toUInt(NULL, 16);
		i = i + 2;
	}
	m_pStUartData->m_stArrUartData[channel].m_pCmdHeaderFormat = pTem;
}
void CUartCfg::InPutChangedCallbackof_spinDigitOutPer()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4DigitOutPer = ui.spinDigitOutPer->value();
}
void CUartCfg::InPutChangedCallbackof_spinPauseOutPer()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4PauseOutPer = ui.spinPauseOutPer->value();
}
void CUartCfg::InPutChangedCallbackof_spinCmdOutPer()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4CmdOutPer = ui.spinCmdOutPer->value();
}
void CUartCfg::InPutChangedCallbackof_spinCmdOutCount()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4CmdOutCount = ui.spinCmdOutCount->value();
}
void CUartCfg::InPutChangedCallbackof_spinReceiveDataLen()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4ReceiveDataLen = ui.spinReceiveDataLen->value();
}
void CUartCfg::InPutChangedCallbackof_spinPauseOutCount()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pStUartData->m_stArrUartData[channel].m_u4PauseOutCount = ui.spinPauseOutCount->value();
}
void CUartCfg::InPutChangedCallbackof_pushDigitalEditor()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pEditData = new CEditData(m_pStUartData->m_stArrUartData[channel].m_u4SendDataLen,
		m_pStUartData->m_stArrUartData[channel].m_pDigitInfo, m_pStUartData->m_stArrUartData[channel].m_u4FrameNumPos, NULL);
	m_pEditData->show();
}
void CUartCfg::InPutChangedCallbackof_pushCmdEditor1()
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pEditData = new CEditData(m_pStUartData->m_stArrUartData[channel].m_u4ReceiveDataLen,
		m_pStUartData->m_stArrUartData[channel].m_pCmdInfo1, m_pStUartData->m_stArrUartData[channel].m_u4FrameNumPos, NULL);
	m_pEditData->show();
}
void CUartCfg::InPutChangedCallbackof_pushCmdEditor2() 
{
	quint8 channel = ui.combCfgChannel->currentIndex();
	m_pEditData = new CEditData(m_pStUartData->m_stArrUartData[channel].m_u4ReceiveDataLen,
		m_pStUartData->m_stArrUartData[channel].m_pCmdInfo2, m_pStUartData->m_stArrUartData[channel].m_u4FrameNumPos, NULL);
	m_pEditData->show();
}

void CUartCfg::ApplyToAllChannel()
{
	stUartDataUnit stData;
	quint8 u1ShowedChannel = ui.combCfgChannel->currentIndex();
	GetSignalDataUnit(stData, u1ShowedChannel);
	for (quint8 channel = 0; channel < u1UART_SIGNAL_CHANNEL_COUNT; channel++)
	{
		SetSignalDataUnit(stData, channel); 
	}
}
void CUartCfg::GetSignalDataUnit(stUartDataUnit& stCfgData, const quint8 &channel)
{
	/*�ṹ�����ֱ�Ӹ�ֵ������һ��һ������*/
	stCfgData.m_enumInterfaceType = m_pStUartData->m_stArrUartData[channel].m_enumInterfaceType;
	stCfgData.m_enumInterfaceWorkmode = m_pStUartData->m_stArrUartData[channel].m_enumInterfaceWorkmode;
	stCfgData.m_fInterfaceBaudRate = m_pStUartData->m_stArrUartData[channel].m_fInterfaceBaudRate;
	stCfgData.m_enumInterfaceCheckType = m_pStUartData->m_stArrUartData[channel].m_enumInterfaceCheckType;
	stCfgData.m_fInterfaceStopbitLen = m_pStUartData->m_stArrUartData[channel].m_fInterfaceStopbitLen;
	stCfgData.m_bInterfaceDoubleDundancy = m_pStUartData->m_stArrUartData[channel].m_bInterfaceDoubleDundancy;
	stCfgData.m_u4SendDataLen = m_pStUartData->m_stArrUartData[channel].m_u4SendDataLen;
	stCfgData.m_u4ReceiveDataLen = m_pStUartData->m_stArrUartData[channel].m_u4ReceiveDataLen;
	stCfgData.m_u4FrameNumPos = m_pStUartData->m_stArrUartData[channel].m_u4FrameNumPos;
	stCfgData.m_pDigitInfo = m_pStUartData->m_stArrUartData[channel].m_pDigitInfo;
	stCfgData.m_u4DigitOutPer = m_pStUartData->m_stArrUartData[channel].m_u4DigitOutPer;
	stCfgData.m_enumPauseType = m_pStUartData->m_stArrUartData[channel].m_enumPauseType;
	stCfgData.m_u4PauseWidth = m_pStUartData->m_stArrUartData[channel].m_u4PauseWidth;
	stCfgData.m_u4PauseOutCount = m_pStUartData->m_stArrUartData[channel].m_u4PauseOutCount;
	stCfgData.m_u4PauseOutPer = m_pStUartData->m_stArrUartData[channel].m_u4PauseOutPer;
	stCfgData.m_u4CmdOutPer = m_pStUartData->m_stArrUartData[channel].m_u4CmdOutPer;
	stCfgData.m_u4CmdOutCount = m_pStUartData->m_stArrUartData[channel].m_u4CmdOutCount;
	stCfgData.m_pCmdHeaderFormat = m_pStUartData->m_stArrUartData[channel].m_pCmdHeaderFormat;
	stCfgData.m_pCmdInfo1 = m_pStUartData->m_stArrUartData[channel].m_pCmdInfo1;
	stCfgData.m_pCmdInfo2 = m_pStUartData->m_stArrUartData[channel].m_pCmdInfo2;
}

void CUartCfg::SetSignalDataUnit(const stUartDataUnit& stCfgData, const quint8 &channel)
{
	m_pStUartData->m_stArrUartData[channel].m_enumInterfaceType = stCfgData.m_enumInterfaceType;
	m_pStUartData->m_stArrUartData[channel].m_enumInterfaceWorkmode = stCfgData.m_enumInterfaceWorkmode;
	m_pStUartData->m_stArrUartData[channel].m_fInterfaceBaudRate = stCfgData.m_fInterfaceBaudRate;
	m_pStUartData->m_stArrUartData[channel].m_enumInterfaceCheckType = stCfgData.m_enumInterfaceCheckType;
	m_pStUartData->m_stArrUartData[channel].m_fInterfaceStopbitLen = stCfgData.m_fInterfaceStopbitLen;
	m_pStUartData->m_stArrUartData[channel].m_bInterfaceDoubleDundancy = stCfgData.m_bInterfaceDoubleDundancy;
	m_pStUartData->m_stArrUartData[channel].m_u4SendDataLen = stCfgData.m_u4SendDataLen;
	m_pStUartData->m_stArrUartData[channel].m_u4ReceiveDataLen = stCfgData.m_u4ReceiveDataLen;
	m_pStUartData->m_stArrUartData[channel].m_u4FrameNumPos = stCfgData.m_u4FrameNumPos;
	//m_pStUartData->m_stArrUartData[channel].m_pDigitInfo = stCfgData.m_pDigitInfo;
	memcpy(m_pStUartData->m_stArrUartData[channel].m_pDigitInfo, stCfgData.m_pDigitInfo, SendReceiveInfoLen);
	m_pStUartData->m_stArrUartData[channel].m_u4DigitOutPer = stCfgData.m_u4DigitOutPer;
	m_pStUartData->m_stArrUartData[channel].m_enumPauseType = stCfgData.m_enumPauseType;
	m_pStUartData->m_stArrUartData[channel].m_u4PauseWidth = stCfgData.m_u4PauseWidth;
	m_pStUartData->m_stArrUartData[channel].m_u4PauseOutCount = stCfgData.m_u4PauseOutCount;
	m_pStUartData->m_stArrUartData[channel].m_u4PauseOutPer = stCfgData.m_u4PauseOutPer;
	m_pStUartData->m_stArrUartData[channel].m_u4CmdOutPer = stCfgData.m_u4CmdOutPer;
	m_pStUartData->m_stArrUartData[channel].m_u4CmdOutCount = stCfgData.m_u4CmdOutCount;
	//m_pStUartData->m_stArrUartData[channel].m_pCmdHeaderFormat = stCfgData.m_pCmdHeaderFormat;
	memcpy(m_pStUartData->m_stArrUartData[channel].m_pCmdHeaderFormat, stCfgData.m_pCmdHeaderFormat, CmdHeaderLen);
	//m_pStUartData->m_stArrUartData[channel].m_pCmdInfo1 = stCfgData.m_pCmdInfo1;
	//m_pStUartData->m_stArrUartData[channel].m_pCmdInfo2 = stCfgData.m_pCmdInfo2;
	memcpy(m_pStUartData->m_stArrUartData[channel].m_pCmdInfo1, stCfgData.m_pCmdInfo1, SendReceiveInfoLen);
	memcpy(m_pStUartData->m_stArrUartData[channel].m_pCmdInfo2, stCfgData.m_pCmdInfo2, SendReceiveInfoLen);
}
/*���水���ص�����,QSetting��ĵ���ģʽ�޷��޸�ini����·�����侲̬����setPath()���Ѿ�������ʵ����������
����������ѡ��ÿ�α���ʱ����һ��QSettingʵ��������·����Ϊm_strCfgFilePath��*/
bool CUartCfg::SaveCfg()
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
void CUartCfg::SaveCfgDataFromMemoty()
{
	QString sectionIndex;
	stUartDataUnit stData;
	QVariantList charTemList;
	for (quint8 u1Channel = 0; u1Channel < u1UART_SIGNAL_CHANNEL_COUNT; u1Channel++)
	{
		GetSignalDataUnit(stData, u1Channel);
		sectionIndex = QString::number(u1Channel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[INTERFACE_TYPE], QString::number(stData.m_enumInterfaceType));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[INTERFACE_WORKMODE], QString::number(stData.m_enumInterfaceWorkmode));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[INTERFACE_BAUDRATE], QString::number(stData.m_fInterfaceBaudRate, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[INTERFACE_CHECK_TYPE], QString::number(stData.m_enumInterfaceCheckType));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[INTERFACE_STOPBIT_LENGTH], QString::number(stData.m_fInterfaceStopbitLen, 'f', 2));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[INTERFACE_DOUBLE_DUNDANCY], QString::number(stData.m_bInterfaceDoubleDundancy));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[SEND_DATA_LENGTH], QString::number(stData.m_u4SendDataLen));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[RECEIVE_DATA_LENGTH], QString::number(stData.m_u4ReceiveDataLen));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[FRAME_NUM_POSITION], QString::number(stData.m_u4FrameNumPos));
		/*װ�����Ϣ*/
		charTemList.clear();
		CopyInfoToVariant(charTemList, stData.m_pDigitInfo, SendReceiveInfoLen);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[DIGIT_INFO], charTemList);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[DIGIT_OUT_PER], QString::number(stData.m_u4DigitOutPer));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_OUT_TYPE], QString::number(stData.m_enumPauseType));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_OUT_WIDTH], QString::number(stData.m_u4PauseWidth));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_OUT_COUNT], QString::number(stData.m_u4PauseOutCount));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[PAUSE_OUT_PER], QString::number(stData.m_u4PauseOutPer));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[CMD_OUT_PER], QString::number(stData.m_u4CmdOutPer));
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[CMD_OUT_COUNT], QString::number(stData.m_u4CmdOutCount));
		charTemList.clear();
		CopyInfoToVariant(charTemList, stData.m_pCmdHeaderFormat, CmdHeaderLen);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[CMD_HEADER_FOAMAT], charTemList);
		charTemList.clear(); 
		CopyInfoToVariant(charTemList, stData.m_pCmdInfo1, SendReceiveInfoLen);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[CMD_INFO_1], charTemList);
		charTemList.clear();
		CopyInfoToVariant(charTemList, stData.m_pCmdInfo2, SendReceiveInfoLen);
		m_oCfgOperator->setValue(arrCFG_DATAUNIT_NAME[CMD_INFO_2], charTemList);
		m_oCfgOperator->endGroup();
	}
	/*������ͨ���޹ص�ȫ��������Ϣ    �޴�����*/
	/*ͬ��*/
	m_oCfgOperator->sync();
}
void CUartCfg::CopyInfoToVariant(QVariantList &list, uchar* data, uint dataLen)
{
	for (uint i = 0; i < dataLen; i++)
	{
		list.append(*data++);
	}
}
/*���Ϊ�����ص��������߼����ȱ��棬�ڴ������ļ�*/
bool CUartCfg::SaveCfgAs()
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
bool CUartCfg::OpenCfg()
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
	if (ParseCfgFile(m_strCfgFilePath, m_pStUartData))
	{
		/*�����ɹ�����m_pStNoElecData�е���Ϣ���½���*/
		CallfunctoChannelChanged();
	}
	return true;
}
void CUartCfg::CreateFileIOer()
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
bool CUartCfg::ParseCfgFile(const QString &strFileName, stUartFullData *pData)
{
	/*����QSettingʵ��*/
	CreateFileIOer();
	QString sectionIndex;
	stUartDataUnit stData;
	for (quint8 iChannel = 0; iChannel < u1UART_SIGNAL_CHANNEL_COUNT; iChannel++)
	{
		sectionIndex = QString::number(iChannel);
		m_oCfgOperator->beginGroup(CFGFILE_SECTION + sectionIndex);
		stData.m_enumInterfaceType = GetInterfaceType(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[INTERFACE_TYPE], InterfaceTypeDefaultValue).toInt());
		stData.m_enumInterfaceWorkmode = GetWorkmodeType(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[INTERFACE_WORKMODE], WorkModeDefaultValue).toInt());
		stData.m_fInterfaceBaudRate = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[INTERFACE_BAUDRATE], BaudRateDefaultValue).toFloat();
		stData.m_enumInterfaceCheckType = GetCheckType(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[INTERFACE_CHECK_TYPE], CheckTypeDefaultValue).toInt());
		stData.m_fInterfaceStopbitLen = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[INTERFACE_STOPBIT_LENGTH], StopBitLenDefaultValue).toFloat();
		stData.m_bInterfaceDoubleDundancy = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[INTERFACE_DOUBLE_DUNDANCY], DoubleRedundancyDefaultValue).toBool();
		stData.m_u4SendDataLen = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[SEND_DATA_LENGTH], SendDataLenDefaultValue).toInt();
		stData.m_u4ReceiveDataLen = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[RECEIVE_DATA_LENGTH], ReceiveDataLenDefaultValue).toInt();
		stData.m_u4FrameNumPos = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[FRAME_NUM_POSITION], FrameNumPosDefaultValue).toInt();
		//stData.m_pDigitInfo = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DIGIT_INFO], DigitOutInfoDefaultValue);
		m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DIGIT_INFO]).toList();
		GetInfoFromVariant(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DIGIT_INFO]).toList(), stData.m_pDigitInfo, stData.m_u4SendDataLen);
		//stData.m_pDigitInfo = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DIGIT_INFO]).toList();
		stData.m_u4DigitOutPer = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[DIGIT_OUT_PER], DigitOutPerDefaultValue).toInt();
		stData.m_enumPauseType = GetPauseType(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_OUT_TYPE], PauseTypeDefaultValue).toInt());
		stData.m_u4PauseWidth = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_OUT_WIDTH], PauseWidthDefaultValue).toInt();
		stData.m_u4PauseOutCount = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_OUT_COUNT], PauseOutCountDefaultValue).toInt();
		stData.m_u4PauseOutPer = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[PAUSE_OUT_PER], PauseOutPerDefaultValue).toInt();
		stData.m_u4CmdOutPer = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_OUT_PER], CmdOutPerDefaultValue).toInt();
		stData.m_u4CmdOutCount = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_OUT_COUNT], CmdOutCountDefaultValue).toInt();
		//stData.m_pCmdHeaderFormat = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_HEADER_FOAMAT], CMDHeaderFormatDefaultValue);
		//stData.m_pCmdInfo1 = m_oCfgOperator->value((arrCFG_DATAUNIT_NAME[CMD_INFO_1], CmdInfo1));
		//stData.m_pCmdInfo2 = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_INFO_2], CmdInfo2);
		GetInfoFromVariant(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_HEADER_FOAMAT]).toList(), stData.m_pCmdHeaderFormat, CmdHeaderLen);
		//stData.m_pCmdHeaderFormat = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_HEADER_FOAMAT]);
		GetInfoFromVariant(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_INFO_1]).toList(), stData.m_pCmdInfo1, SendReceiveInfoLen);
		//stData.m_pCmdInfo1 = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_INFO_1]);
		GetInfoFromVariant(m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_INFO_2]).toList(), stData.m_pCmdInfo2, SendReceiveInfoLen);
		//stData.m_pCmdInfo2 = m_oCfgOperator->value(arrCFG_DATAUNIT_NAME[CMD_INFO_2]);
		m_oCfgOperator->endGroup();
		/*���ص��ڴ�*/
		SetSignalDataUnit(stData, iChannel);
	}
	/*������ͨ���޹ص�ȫ��������Ϣ*/
	/*ͬ��*/
	m_oCfgOperator->sync();
	return true;
}
void CUartCfg::GetInfoFromVariant(const QVariantList &list, uchar* data, uint dataLen)
{
	QVariantList::ConstIterator pTem = list.constBegin();
	for (uint i =0;i<dataLen;i++)
	{
		*data = pTem->toUInt();/*��֪�����С�˶������ĸ����᲻�������*/
		data++;
		pTem++;
	}
}
/*����ͨ���Ļص�����,�ر�Ӧ�õ�ȫ�ֿ��أ�����ui����*/
void CUartCfg::CallfunctoChannelChanged()
{
	quint8 u1ShowedChannel = ui.combCfgChannel->currentIndex();
	QString strCMDHeaderFormat = "";
	uchar *pTem = NULL;
	uchar u1BaudIndex = 0;
	uchar u1StopbitIndex = 0;
	if (NULL != m_pStUartData)
	{
		ui.combInterfaceType->setCurrentIndex(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_enumInterfaceType);
		ui.combWorkMode->setCurrentIndex(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_enumInterfaceWorkmode);
		u1BaudIndex = GetBaudRateIndex(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_fInterfaceBaudRate);
		ui.combBaudRate->setCurrentIndex(u1BaudIndex);
		ui.combCheckType->setCurrentIndex(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_enumInterfaceCheckType);
		u1StopbitIndex = GetStopbitLenIndex(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_fInterfaceStopbitLen);
		ui.combStopBitLen->setCurrentIndex(u1StopbitIndex);
		ui.radioDoubleRedundancy->setChecked(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_bInterfaceDoubleDundancy);
		ui.spinSendDataLen->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4SendDataLen);
		ui.spinFrameNumPos->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4FrameNumPos);
		ui.comboPauseType->setCurrentIndex(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_enumPauseType);
		ui.spinPauseWidth->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4PauseWidth);
		pTem = m_pStUartData->m_stArrUartData[u1ShowedChannel].m_pCmdHeaderFormat;
		for (int i = 0; i < CmdHeaderLen; i++)
		{
			//qDebug() << *pTem++;
			strCMDHeaderFormat += QString::number(*m_pStUartData->m_stArrUartData[u1ShowedChannel].m_pCmdHeaderFormat++,16).toUpper().rightJustified(2, QChar('0'));;
		}
		m_pStUartData->m_stArrUartData[u1ShowedChannel].m_pCmdHeaderFormat = pTem;
		ui.lineCMDHeaderFormat->setText(strCMDHeaderFormat);
		ui.spinDigitOutPer->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4DigitOutPer);
		ui.spinPauseOutPer->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4PauseOutPer);
		ui.spinCmdOutPer->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4CmdOutPer);
		ui.spinCmdOutCount->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4CmdOutCount);
		ui.spinReceiveDataLen->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4ReceiveDataLen);
		ui.spinPauseOutCount->setValue(m_pStUartData->m_stArrUartData[u1ShowedChannel].m_u4PauseOutCount);
		/*�����༭������û��д*/
		  
		InPutChangedCallbackof_combWorkMode();
	}
	else
	{
		QMessageBox::critical(NULL,
			"����",
			"��ǰû��������Ϣ��CUartCfg::m_pStNoElecDataָ��Ϊ�գ�");
	}
}
/*ȡ�������ص�����*/
void CUartCfg::Cancel()
{
	QCloseEvent *event;
	closeEvent(event);
}


/*�����رհ�ť �޸�m_bApplyToAll��ֵ*/
void CUartCfg::closeEvent(QCloseEvent *event)
{
	m_bIfInitOpenCfgFile = true;
	/*���¼��������ļ����Ӷ������ڴ��������Ϣ*/
	OpenCfg();
	close();
}
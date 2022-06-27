#include "CEditData.h"
#include <QDebug>
#include <QFileDialog>
#include <QSettings>
using namespace editCfg;
CEditData::CEditData(unsigned int dataLen, uchar* pData, unsigned int iFrameNumPos, QWidget *parent)
	: QWidget(parent)
	, m_u4DataLen(dataLen)
	, m_pData(pData)
	, m_u4FrameNumPos(iFrameNumPos)
{
	ui.setupUi(this);
	setWindowFlags(Qt::WindowCloseButtonHint);
	setAttribute(Qt::WA_DeleteOnClose);
	Init();
}

CEditData::~CEditData()
{
}
void CEditData::Init()
{
	InitTableWidget(m_u4DataLen);
	m_bConnection = false;
	connect(ui.radioAddOne, SIGNAL(clicked()), this, SLOT(InPutChangedCallbackof_radioAddOne()));
	connect(ui.radioSubOne, SIGNAL(clicked()), this, SLOT(InPutChangedCallbackof_radioSubOne()));
	connect(ui.radioBConstant, SIGNAL(clicked()), this, SLOT(InPutChangedCallbackof_radioBConstant()));
	connect(ui.radioReadFile, SIGNAL(clicked()), this, SLOT(InPutChangedCallbackof_radioReadFile()));
	connect(ui.spinConstant, SIGNAL(valueChanged(QString)), this, SLOT(InPutChangedCallbackof_spinConstant()));
	connect(ui.tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(InPutChangedCallbackof_tableWidget(int, int)));
}

/*将m_pData中的数据 打印在界面中*/
void CEditData::SetTableData()
{
	uchar *pData = m_pData;
	uint i = 0;
	QString strItem = "";
	disconnect(ui.tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(InPutChangedCallbackof_tableWidget(int, int)));
	while (m_u4FrameNumPos != i && i < m_u4DataLen)
	{
	show:
		strItem = QString::number((unsigned char)*pData++, 16).toUpper().rightJustified(2, QChar('0'));
		ui.tableWidget->setItem(i / TABLECOLNUM, i % TABLECOLNUM, new QTableWidgetItem(strItem));
		i++;
	}
	/*帧计数位置*/
	if (m_u4FrameNumPos == i)
	{
		pData++;
		goto show;
	}
	connect(ui.tableWidget, SIGNAL(cellChanged(int, int)), this, SLOT(InPutChangedCallbackof_tableWidget(int, int)));
}

void CEditData::InPutChangedCallbackof_radioAddOne()
{
	CreateAddOneCode();
	SetTableData();
}
void CEditData::InPutChangedCallbackof_radioSubOne()
{
	CreateSubOneCode();
	SetTableData();
}
void CEditData::InPutChangedCallbackof_radioBConstant()
{
	CreateConstantCode();
	SetTableData();
}
void CEditData::InPutChangedCallbackof_radioReadFile()
{
	QString strCfgFilePath = QFileDialog::getOpenFileName(NULL, "选择文件", "./config/UartModule", "*.ini *.dat");
	if (0 == strCfgFilePath.length())
	{
		return;
	}
	if (ParseCfgFile(strCfgFilePath, m_pData))
	{
		/*解析成功，将m_pData中的信息更新界面*/
		SetTableData();
	}
}
bool CEditData::ParseCfgFile(const QString &file, uchar* pData)
{
	/*创建QSetting实例*/
	QSettings *oCfgOperator = new QSettings(file, QSettings::IniFormat);
	/*设置配置文件operator为utf-8编码*/
	oCfgOperator->setIniCodec("UTF-8");
	uint i = 0;
	QVariantList listTem = oCfgOperator->value(DATAKEY).toList();
	QVariantList::ConstIterator pTem = listTem.constBegin();
	while (m_u4FrameNumPos != i && i < m_u4DataLen && pTem != listTem.constEnd())
	{
	fill:
		*pData++ = pTem->toUInt();
		pTem++;
		i++;
	}
	/*帧计数位置*/
	if (m_u4FrameNumPos == i)
	{
		pData++;
		goto fill;
	}
	if (NULL != oCfgOperator)
	{
		delete oCfgOperator;
		oCfgOperator = NULL;
	}
	return true;
}
void CEditData::GetInfoFromVariant(const QVariantList &list, uchar* data, uint dataLen)
{
	QVariantList::ConstIterator pTem = list.constBegin();;
	for (uint i = 0; i < dataLen; i++)
	{
		*data = pTem->toUInt();/*不知道大端小端对齐是哪个，会不会出问题*/
		data++;
		pTem++;
	}
}
void CEditData::InPutChangedCallbackof_spinConstant() 
{
	if (ui.radioBConstant->isChecked())
	{
		InPutChangedCallbackof_radioBConstant();
	}
}
void CEditData::InPutChangedCallbackof_tableWidget(int row, int col)
{
	uchar *pData = m_pData;
	unsigned int u4ChangedPos = row * TABLECOLNUM + col;
	if (m_u4FrameNumPos <= u4ChangedPos)
	{
		u4ChangedPos++; 
	}
	/*指针[n]  这种形式就已经解引用了*/
	pData[u4ChangedPos] = ui.tableWidget->item(row, col)->text().toUInt(NULL, 16);
}
/*初始化表格控件，生成特定的行数列数*/
void CEditData::InitTableWidget(const unsigned int dataLen)
{
	uint rowCount = dataLen / TABLECOLNUM +1;
	if (0 == dataLen % TABLECOLNUM)
	{
		rowCount --;
	}
	QStringList strColHeader;
	for (int i = 0; i < rowCount; i++)
	{
		strColHeader.append(QString::number(i+1));
	}
	ui.spinRow->setValue(rowCount);
	ui.spinCol->setValue(TABLECOLNUM);
	ui.tableWidget->setRowCount(rowCount);
	ui.tableWidget->setHorizontalHeaderLabels(strColHeader);
	/*初始化为增一码*/
	InPutChangedCallbackof_radioAddOne();
}
void CEditData::CreateAddOneCode()
{
	uchar *pData = m_pData;
	uint i = 0;
	uchar data = 0;
	while (m_u4FrameNumPos != i && i < m_u4DataLen)
	{
	fill:
		*pData++ = data++;
		i++;
	}
	/*帧计数位置*/
	if (m_u4FrameNumPos == i)
	{
		pData++;
		goto fill;
	}
}
void CEditData::CreateSubOneCode()
{
	uchar *pData = m_pData;
	uint i = 0;
	uchar data = UCHAR_MAX;
	while (m_u4FrameNumPos != i && i < m_u4DataLen)
	{
	fill:
		*pData++ = data--;
		i++;
	}
	/*帧计数位置*/
	if (m_u4FrameNumPos == i)
	{
		pData++;
		goto fill;
	}
}
void CEditData::CreateConstantCode()
{
	
	uchar *pData = m_pData;
	uint i = 0;
	uchar data = ui.spinConstant->value();
	while (m_u4FrameNumPos != i && i < m_u4DataLen)
	{
	fill:
		*pData++ = data;
		i++;
	}
	/*帧计数位置*/
	if (m_u4FrameNumPos == i)
	{
		pData++;
		goto fill;
	}
}
bool CEditData::CreateCodeFromFile()
{
	return true;
}
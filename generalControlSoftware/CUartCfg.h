/*
m_u4SendDataLen:		发送数据长度，指再发送模式下，发送出去数据的长度
m_u4ReceiveDataLen:		接收信息长度，软件中用于命令取数模式、被动接收模式下的命令帧信息字长
*/
#pragma once
#include <QWidget>
#include "ui_CUartCfg.h"
#include "CEditData.h"
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include <QMessageBox>
using namespace editCfg;
QT_BEGIN_NAMESPACE
namespace uartCfg
{
#define CmdHeaderLen                                   4
#define SendReceiveInfoLen                             1024

#define CfgPathDefault "./config/UartModule/config.ini"
#define InterfaceTypeDefaultValue                       RS422_SEND_RS422_RECEIVE          
#define WorkModeDefaultValue						    SEND_RESPONSED_TO_PAUSE    
#define BaudRateDefaultValue						    921.6        
#define CheckTypeDefaultValue						    NO_CHECK         
#define StopBitLenDefaultValue							1            
#define DoubleRedundancyDefaultValue					true    

#define SendDataLenDefaultValue							1024
#define ReceiveDataLenDefaultValue						1024
#define FrameNumPosDefaultValue							0  

//#define DigitOutInfoDefaultValue						sendReceiveData  
#define DigitOutPerDefaultValue							1				       

#define PauseTypeDefaultValue							POSITIVE_PAUSE												
#define PauseWidthDefaultValue							1  
#define PauseOutCountDefaultValue						10000        /*暂定*/
#define PauseOutPerDefaultValue							1

#define CmdOutPerDefaultValue							1            /*ms*/
#define CmdOutCountDefaultValue							10000
#define StopbitLenGain									10 /*为区分停止位长1   1.5   2取整后的可以区分，乘上增益系数*/
//#define CMDHeaderFormatDefaultValue						cmdHeader     /*先暂定4个字节，全为0*/ 				   
//#define CmdInfo1										sendReceiveData	 
//#define CmdInfo2										sendReceiveData     
#pragma execution_character_set("utf-8") 
	/*ini配置文件数据单元节的前半部分名称*/
	const QString CFGFILE_SECTION = "UartUnit";
	/*ini配置文件模块内与通道无关的全局变量配置节名称*/
	const QString CFGFILE_GLOBAL_SECTION = "UartGlobal";
	/*电量信号通道数量设定*/
	const quint8  u1UART_SIGNAL_CHANNEL_COUNT = 8;
	/*配置文件全局变量的键的数量*/
	const quint8  u1DATAGLOBAL_COUNT = 0;
	/*配置文件数据单元中的键的数量*/
	const quint8  u1DATAUNIT_COUNT = 20;
	/*配置文件数据单元中全局变量键的名称，此类中没有，先注释掉
	const QString arrCFG_DATAGLOBAL_NAME[] = {}; */
	/*配置文件数据单元中的键名称,与下面的DATAUNIT_NAME组合使用*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "interfaceType","interfaceWorkmode" ,"interfaceBaudrate","interfaceCheckType", \
		"interfaceStopBitLen", "interfaceDoubleDundancy" , "sendDataLen", "ReceiveDatalen" , "frameNumPos", "digitInfo" , \
		"digitOutPer", "pauseType", "pauseWidth", "pauseOutCount", "pauseOutPer", "CmdOutPer", "CmdOutCount", "CmdHeaderInfo", "CmdInfo1",\
		"CmdInfo2" };
	enum DATAGLOBAL_NAME
	{
		/*此类没有与通道无关的全局变量*/
	};
	enum DATAUNIT_NAME      /*与arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT]组合使用，两者顺粗要保一致*/
	{
		INTERFACE_TYPE = 0x0,		    /*接口类型*/
		INTERFACE_WORKMODE,             /*接口工作模式*/
		INTERFACE_BAUDRATE,             /*波特率*/
		INTERFACE_CHECK_TYPE,		    /*校验类型*/
		INTERFACE_STOPBIT_LENGTH,	    /*停止位长*/
		INTERFACE_DOUBLE_DUNDANCY,      /*双冗余*/
		SEND_DATA_LENGTH,		        /*发送数据长度*/
		RECEIVE_DATA_LENGTH,			/*接收数据长度*/
		FRAME_NUM_POSITION,		        /*帧计数位置*/
		DIGIT_INFO,				        /*数字量信息*/
		DIGIT_OUT_PER,					/*数字量输出周期*/
		PAUSE_OUT_TYPE,				    /*脉冲类型*/
		PAUSE_OUT_WIDTH,			    /*脉冲信号宽度*/
		PAUSE_OUT_COUNT,				/*脉冲输出次数*/
		PAUSE_OUT_PER,		            /*脉冲输出周期*/
		CMD_OUT_PER,					/*命令输出周期*/
		CMD_OUT_COUNT,					/*命令输出次数*/
		CMD_HEADER_FOAMAT,		        /*命令头格式*/
		CMD_INFO_1,						/*命令1*/
		CMD_INFO_2 						/*命令2*/
	};
	enum UART_RECEIVE_SEND_TYPE
	{
		RS422_SEND_RS422_RECEIVE = 0,   /*差分收发*/
		RS422_SEND_OPTICAL_RECEIVE,     /*差分发送光耦接收*/
		RECEIVE_SEND_TYPE_COUNT
	};
	enum UART_WORKMODE
	{
		SEND_RESPONSED_TO_PAUSE = 0,	/*脉冲响应发送模式*/
		SEND_RESPONSED_TO_CMD,			/*命令响应发送模式*/
		SEND_CYCLIC,					/*周期发送模式*/
		RECEIVE_WITH_PAUSE,				/*脉冲取数模式*/
		RECEIVE_WITH_CMD,				/*命令取数模式*/
		RECEIVE_PASSIVELY,				/*被动接收模式*/
		STOP_WORK,						/*停止工作模式*/
		WORKMODE_COUNT
	};
	enum UART_CHENK_TYPE
	{
		NO_CHECK = 0,					/*无校验*/
		ODD_CHECK,						/*奇校验*/
		EVEN_CHECK,						/*偶校验*/
		CHECK_TYPE_COUNT
	};
	enum PAUSE_TYPE
	{
		POSITIVE_PAUSE = 0,				/*正脉冲*/
		NEGATIVE_PAUSE,
		PAUSE_TYPE_COUNT
	};
	/*数字信号单通道数据结构体*/
	typedef struct stUartDataUnit
	{
		/*接口相关*/
		UART_RECEIVE_SEND_TYPE	m_enumInterfaceType;
		UART_WORKMODE		    m_enumInterfaceWorkmode;
		float					m_fInterfaceBaudRate;
		UART_CHENK_TYPE			m_enumInterfaceCheckType;
		float					m_fInterfaceStopbitLen;
		bool					m_bInterfaceDoubleDundancy;
		/*信息长*/
		uint					m_u4SendDataLen;
		uint					m_u4ReceiveDataLen;
		uint					m_u4FrameNumPos;		/*帧计数位置*/

		uchar*					m_pDigitInfo;
		uchar*					m_pDigitInfoCopy;
		uint					m_u4DigitOutPer;
		PAUSE_TYPE				m_enumPauseType;
		uint					m_u4PauseWidth;
		uint					m_u4PauseOutCount;
		uint					m_u4PauseOutPer;
		uint					m_u4CmdOutPer;
		uint					m_u4CmdOutCount;
		uchar*					m_pCmdHeaderFormatCopy;
		uchar*					m_pCmdHeaderFormat;
		uchar*					m_pCmdInfo1;
		uchar*					m_pCmdInfo1Copy;
		uchar*					m_pCmdInfo2;
		uchar*					m_pCmdInfo2Copy;
		stUartDataUnit()
		{
			m_enumInterfaceType = InterfaceTypeDefaultValue;
		    m_enumInterfaceWorkmode = WorkModeDefaultValue;
			m_fInterfaceBaudRate = BaudRateDefaultValue;
			m_enumInterfaceCheckType = CheckTypeDefaultValue;
			m_fInterfaceStopbitLen = StopBitLenDefaultValue;
			m_bInterfaceDoubleDundancy = DoubleRedundancyDefaultValue;

			m_u4SendDataLen = SendDataLenDefaultValue;
			m_u4ReceiveDataLen = ReceiveDataLenDefaultValue;
			m_u4FrameNumPos = FrameNumPosDefaultValue;		/*帧计数位置*/

			//初始化为0;
			m_pDigitInfo = new uchar[SendReceiveInfoLen]();
			m_pDigitInfoCopy = m_pDigitInfo;
			m_u4DigitOutPer = DigitOutPerDefaultValue;
			m_enumPauseType = PauseTypeDefaultValue;
			m_u4PauseWidth = PauseWidthDefaultValue;
			m_u4PauseOutCount = PauseOutCountDefaultValue;
			m_u4PauseOutPer = PauseOutPerDefaultValue;
			m_u4CmdOutPer = CmdOutPerDefaultValue;
			m_u4CmdOutCount = CmdOutCountDefaultValue;
			//m_pCmdHeaderFormat = CMDHeaderFormatDefaultValue;
			//m_pCmdInfo1 = CmdInfo1;
			//m_pCmdInfo2 = CmdInfo2;
			m_pCmdHeaderFormat = new uchar[CmdHeaderLen]();
			m_pCmdHeaderFormatCopy = m_pCmdHeaderFormat;
			m_pCmdInfo1 = new uchar[SendReceiveInfoLen]();
			m_pCmdInfo1Copy = m_pCmdInfo1;
			m_pCmdInfo2 = new uchar[SendReceiveInfoLen]();
			m_pCmdInfo2Copy = m_pCmdInfo2;
		}
		~stUartDataUnit()
		{
			delete[]m_pDigitInfoCopy;
			delete[]m_pCmdHeaderFormatCopy;
			delete[]m_pCmdInfo1Copy;
			delete[]m_pCmdInfo2Copy;
			m_pDigitInfo = NULL;
			m_pCmdHeaderFormat = NULL;
			m_pCmdInfo1 = NULL;
			m_pCmdInfo2 = NULL;
		}

	}stDataUnit;

	/*数字量信号单通道数据及与通道无关数据的结构体*/
	typedef struct stUartUiShowedData
	{
	}stUartUiShowedData;

	typedef struct stUartFullData
	{ 
		stUartDataUnit m_stArrUartData[u1UART_SIGNAL_CHANNEL_COUNT];
		/*无模块全局变量*/
		stUartFullData()
		{
		}
	}stUartFullData;


	class CUartCfg : public QWidget
	{
		Q_OBJECT

	public:
		CUartCfg(stUartFullData *pUartCfgData, QWidget *parent = Q_NULLPTR);
		~CUartCfg();
		void test();//测试


	private:
		/*重写窗口关闭事件*/
		void closeEvent(QCloseEvent *event);
		/*初始化*/
		void Init();
		/*关联回调函数*/
		void SetCallbackFunc();
		/*从读取单元配置信息*/
		void GetSignalDataUnit(stUartDataUnit& stCfgData, const quint8 &channel = 0);
		void SetSignalDataUnit(const stUartDataUnit& stCfgData, const quint8 &channel = 0);
		/*应用到全部通道槽函数关联*/
		/*解析配置文件*/
		bool ParseCfgFile(const QString &strFileName, stUartFullData *arrData);
		/*更新创建配置文件读写实例，此实例创建以后配置的文件路径无法更改，故而每次用到都重新创建*/
		void CreateFileIOer();
		/*另存为从内存中把配置信息保存到本地的函数*/
		void SaveCfgDataFromMemoty();
		/*由Index返回枚举类型的内联函数*/
		inline	void InsertBuadrate();
		inline	void InsertStopbitLen();
		UART_RECEIVE_SEND_TYPE GetInterfaceType(quint8 index)
		{
			UART_RECEIVE_SEND_TYPE arrTem[RECEIVE_SEND_TYPE_COUNT] = { RS422_SEND_RS422_RECEIVE ,RS422_SEND_OPTICAL_RECEIVE};
			return arrTem[index];
		}
		UART_WORKMODE GetWorkmodeType(quint8 index)
		{
			UART_WORKMODE arrTem[WORKMODE_COUNT] = { SEND_RESPONSED_TO_PAUSE ,SEND_RESPONSED_TO_CMD,SEND_CYCLIC,
			RECEIVE_WITH_PAUSE, RECEIVE_WITH_CMD,RECEIVE_PASSIVELY,STOP_WORK };
			return arrTem[index];
		}
		UART_CHENK_TYPE GetCheckType(quint8 index)
		{
			UART_CHENK_TYPE arrTem[CHECK_TYPE_COUNT] = { NO_CHECK ,ODD_CHECK, EVEN_CHECK};
			return arrTem[index];
		}
		PAUSE_TYPE GetPauseType(quint8 index)
		{
			PAUSE_TYPE arrTem[PAUSE_TYPE_COUNT] = { POSITIVE_PAUSE ,NEGATIVE_PAUSE };
			return arrTem[index];
		}
		/*返回波特率索引*/
		uchar GetBaudRateIndex(float fbaudrate)
		{
			return m_mapBaudIndex.find(round(fbaudrate)).value();
		}
		/*返回停止位长索引*/
		uchar GetStopbitLenIndex(float fStopbitlen)
		{
			return m_mapStopbitLen.find(round(fStopbitlen*StopbitLenGain)).value();
		}
		void CopyInfoToVariant(QVariantList &list, uchar* data,uint dataLen);
		void GetInfoFromVariant(const QVariantList &list, uchar* data, uint dataLen);
		Ui::CUartCfg ui;
		CEditData* m_pEditData;
		/*ini文件中读取到的数据信息，此数据有有效数据*/
		stUartFullData * m_pStUartData;
		/*ini配置文件读写*/
		QSettings *m_oCfgOperator;
		/*配置文件路径*/
		QString m_strCfgFilePath;
		/*是否时在初始化时首次打开配置文件不弹框标识*/
		bool m_bIfInitOpenCfgFile;
		/*为另存为按键设置，是否从ui界面读取配置信息开关，默认关，只有在“另存为”才会打开*/
		bool m_bIfGetInfoFromUi;
		QMap<float, uchar>m_mapBaudIndex;
		QMap<float, uchar>m_mapStopbitLen;
	private slots:
		//void test1();//测试
				/*输入框数据发生变化更新内存的回调函数*/
		void InPutChangedCallbackof_combInterfaceType();
		void InPutChangedCallbackof_combWorkMode();
		void InPutChangedCallbackof_combBaudRate();
		void InPutChangedCallbackof_combCheckType();
		void InPutChangedCallbackof_combStopBitLen();
		void InPutChangedCallbackof_radioDoubleRedundancy();
		void InPutChangedCallbackof_spinSendDataLen();
		void InPutChangedCallbackof_spinFrameNumPos();
		void InPutChangedCallbackof_comboPauseType();
		void InPutChangedCallbackof_spinPauseWidth();
		void InPutChangedCallbackof_lineCMDHeaderFormat();
		void InPutChangedCallbackof_spinDigitOutPer();
		void InPutChangedCallbackof_spinPauseOutPer();
		void InPutChangedCallbackof_spinCmdOutPer();
		void InPutChangedCallbackof_spinCmdOutCount();
		void InPutChangedCallbackof_spinReceiveDataLen();
		void InPutChangedCallbackof_spinPauseOutCount();
		void InPutChangedCallbackof_pushDigitalEditor();
		void InPutChangedCallbackof_pushCmdEditor1();
		void InPutChangedCallbackof_pushCmdEditor2();
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
		/*三个btn信息编辑的回调函数*/
		//void CallfunctoBtnDigitalEditor();
		//void CallfunctoBtnCMDEditor1();
		//void CallfunctoBtnCMDEditor2();
		/*应用到所有通道*/
		void ApplyToAllChannel();
	};

}
QT_END_NAMESPACE

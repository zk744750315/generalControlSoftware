/*
m_u4SendDataLen:		�������ݳ��ȣ�ָ�ٷ���ģʽ�£����ͳ�ȥ���ݵĳ���
m_u4ReceiveDataLen:		������Ϣ���ȣ��������������ȡ��ģʽ����������ģʽ�µ�����֡��Ϣ�ֳ�
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
#define PauseOutCountDefaultValue						10000        /*�ݶ�*/
#define PauseOutPerDefaultValue							1

#define CmdOutPerDefaultValue							1            /*ms*/
#define CmdOutCountDefaultValue							10000
#define StopbitLenGain									10 /*Ϊ����ֹͣλ��1   1.5   2ȡ����Ŀ������֣���������ϵ��*/
//#define CMDHeaderFormatDefaultValue						cmdHeader     /*���ݶ�4���ֽڣ�ȫΪ0*/ 				   
//#define CmdInfo1										sendReceiveData	 
//#define CmdInfo2										sendReceiveData     
#pragma execution_character_set("utf-8") 
	/*ini�����ļ����ݵ�Ԫ�ڵ�ǰ�벿������*/
	const QString CFGFILE_SECTION = "UartUnit";
	/*ini�����ļ�ģ������ͨ���޹ص�ȫ�ֱ������ý�����*/
	const QString CFGFILE_GLOBAL_SECTION = "UartGlobal";
	/*�����ź�ͨ�������趨*/
	const quint8  u1UART_SIGNAL_CHANNEL_COUNT = 8;
	/*�����ļ�ȫ�ֱ����ļ�������*/
	const quint8  u1DATAGLOBAL_COUNT = 0;
	/*�����ļ����ݵ�Ԫ�еļ�������*/
	const quint8  u1DATAUNIT_COUNT = 20;
	/*�����ļ����ݵ�Ԫ��ȫ�ֱ����������ƣ�������û�У���ע�͵�
	const QString arrCFG_DATAGLOBAL_NAME[] = {}; */
	/*�����ļ����ݵ�Ԫ�еļ�����,�������DATAUNIT_NAME���ʹ��*/
	const QString arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT] = { "interfaceType","interfaceWorkmode" ,"interfaceBaudrate","interfaceCheckType", \
		"interfaceStopBitLen", "interfaceDoubleDundancy" , "sendDataLen", "ReceiveDatalen" , "frameNumPos", "digitInfo" , \
		"digitOutPer", "pauseType", "pauseWidth", "pauseOutCount", "pauseOutPer", "CmdOutPer", "CmdOutCount", "CmdHeaderInfo", "CmdInfo1",\
		"CmdInfo2" };
	enum DATAGLOBAL_NAME
	{
		/*����û����ͨ���޹ص�ȫ�ֱ���*/
	};
	enum DATAUNIT_NAME      /*��arrCFG_DATAUNIT_NAME[u1DATAUNIT_COUNT]���ʹ�ã�����˳��Ҫ��һ��*/
	{
		INTERFACE_TYPE = 0x0,		    /*�ӿ�����*/
		INTERFACE_WORKMODE,             /*�ӿڹ���ģʽ*/
		INTERFACE_BAUDRATE,             /*������*/
		INTERFACE_CHECK_TYPE,		    /*У������*/
		INTERFACE_STOPBIT_LENGTH,	    /*ֹͣλ��*/
		INTERFACE_DOUBLE_DUNDANCY,      /*˫����*/
		SEND_DATA_LENGTH,		        /*�������ݳ���*/
		RECEIVE_DATA_LENGTH,			/*�������ݳ���*/
		FRAME_NUM_POSITION,		        /*֡����λ��*/
		DIGIT_INFO,				        /*��������Ϣ*/
		DIGIT_OUT_PER,					/*�������������*/
		PAUSE_OUT_TYPE,				    /*��������*/
		PAUSE_OUT_WIDTH,			    /*�����źſ��*/
		PAUSE_OUT_COUNT,				/*�����������*/
		PAUSE_OUT_PER,		            /*�����������*/
		CMD_OUT_PER,					/*�����������*/
		CMD_OUT_COUNT,					/*�����������*/
		CMD_HEADER_FOAMAT,		        /*����ͷ��ʽ*/
		CMD_INFO_1,						/*����1*/
		CMD_INFO_2 						/*����2*/
	};
	enum UART_RECEIVE_SEND_TYPE
	{
		RS422_SEND_RS422_RECEIVE = 0,   /*����շ�*/
		RS422_SEND_OPTICAL_RECEIVE,     /*��ַ��͹������*/
		RECEIVE_SEND_TYPE_COUNT
	};
	enum UART_WORKMODE
	{
		SEND_RESPONSED_TO_PAUSE = 0,	/*������Ӧ����ģʽ*/
		SEND_RESPONSED_TO_CMD,			/*������Ӧ����ģʽ*/
		SEND_CYCLIC,					/*���ڷ���ģʽ*/
		RECEIVE_WITH_PAUSE,				/*����ȡ��ģʽ*/
		RECEIVE_WITH_CMD,				/*����ȡ��ģʽ*/
		RECEIVE_PASSIVELY,				/*��������ģʽ*/
		STOP_WORK,						/*ֹͣ����ģʽ*/
		WORKMODE_COUNT
	};
	enum UART_CHENK_TYPE
	{
		NO_CHECK = 0,					/*��У��*/
		ODD_CHECK,						/*��У��*/
		EVEN_CHECK,						/*żУ��*/
		CHECK_TYPE_COUNT
	};
	enum PAUSE_TYPE
	{
		POSITIVE_PAUSE = 0,				/*������*/
		NEGATIVE_PAUSE,
		PAUSE_TYPE_COUNT
	};
	/*�����źŵ�ͨ�����ݽṹ��*/
	typedef struct stUartDataUnit
	{
		/*�ӿ����*/
		UART_RECEIVE_SEND_TYPE	m_enumInterfaceType;
		UART_WORKMODE		    m_enumInterfaceWorkmode;
		float					m_fInterfaceBaudRate;
		UART_CHENK_TYPE			m_enumInterfaceCheckType;
		float					m_fInterfaceStopbitLen;
		bool					m_bInterfaceDoubleDundancy;
		/*��Ϣ��*/
		uint					m_u4SendDataLen;
		uint					m_u4ReceiveDataLen;
		uint					m_u4FrameNumPos;		/*֡����λ��*/

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
			m_u4FrameNumPos = FrameNumPosDefaultValue;		/*֡����λ��*/

			//��ʼ��Ϊ0;
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

	/*�������źŵ�ͨ�����ݼ���ͨ���޹����ݵĽṹ��*/
	typedef struct stUartUiShowedData
	{
	}stUartUiShowedData;

	typedef struct stUartFullData
	{ 
		stUartDataUnit m_stArrUartData[u1UART_SIGNAL_CHANNEL_COUNT];
		/*��ģ��ȫ�ֱ���*/
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
		void test();//����


	private:
		/*��д���ڹر��¼�*/
		void closeEvent(QCloseEvent *event);
		/*��ʼ��*/
		void Init();
		/*�����ص�����*/
		void SetCallbackFunc();
		/*�Ӷ�ȡ��Ԫ������Ϣ*/
		void GetSignalDataUnit(stUartDataUnit& stCfgData, const quint8 &channel = 0);
		void SetSignalDataUnit(const stUartDataUnit& stCfgData, const quint8 &channel = 0);
		/*Ӧ�õ�ȫ��ͨ���ۺ�������*/
		/*���������ļ�*/
		bool ParseCfgFile(const QString &strFileName, stUartFullData *arrData);
		/*���´��������ļ���дʵ������ʵ�������Ժ����õ��ļ�·���޷����ģ��ʶ�ÿ���õ������´���*/
		void CreateFileIOer();
		/*���Ϊ���ڴ��а�������Ϣ���浽���صĺ���*/
		void SaveCfgDataFromMemoty();
		/*��Index����ö�����͵���������*/
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
		/*���ز���������*/
		uchar GetBaudRateIndex(float fbaudrate)
		{
			return m_mapBaudIndex.find(round(fbaudrate)).value();
		}
		/*����ֹͣλ������*/
		uchar GetStopbitLenIndex(float fStopbitlen)
		{
			return m_mapStopbitLen.find(round(fStopbitlen*StopbitLenGain)).value();
		}
		void CopyInfoToVariant(QVariantList &list, uchar* data,uint dataLen);
		void GetInfoFromVariant(const QVariantList &list, uchar* data, uint dataLen);
		Ui::CUartCfg ui;
		CEditData* m_pEditData;
		/*ini�ļ��ж�ȡ����������Ϣ������������Ч����*/
		stUartFullData * m_pStUartData;
		/*ini�����ļ���д*/
		QSettings *m_oCfgOperator;
		/*�����ļ�·��*/
		QString m_strCfgFilePath;
		/*�Ƿ�ʱ�ڳ�ʼ��ʱ�״δ������ļ��������ʶ*/
		bool m_bIfInitOpenCfgFile;
		/*Ϊ���Ϊ�������ã��Ƿ��ui�����ȡ������Ϣ���أ�Ĭ�Ϲأ�ֻ���ڡ����Ϊ���Ż��*/
		bool m_bIfGetInfoFromUi;
		QMap<float, uchar>m_mapBaudIndex;
		QMap<float, uchar>m_mapStopbitLen;
	private slots:
		//void test1();//����
				/*��������ݷ����仯�����ڴ�Ļص�����*/
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
		/*����btn��Ϣ�༭�Ļص�����*/
		//void CallfunctoBtnDigitalEditor();
		//void CallfunctoBtnCMDEditor1();
		//void CallfunctoBtnCMDEditor2();
		/*Ӧ�õ�����ͨ��*/
		void ApplyToAllChannel();
	};

}
QT_END_NAMESPACE

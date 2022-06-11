#pragma once

#include <QWidget>
#include "ui_CEditData.h"
#pragma execution_character_set("utf-8") 

QT_BEGIN_NAMESPACE

#define TABLECOLNUM						 16
#define DATAKEY							 "Info"
namespace editCfg
{
	class CEditData : public QWidget
	{
		Q_OBJECT

	public:
		CEditData(unsigned int dataLen, uchar* pData, unsigned int iFrameNumPos, QWidget *parent = Q_NULLPTR);
		~CEditData();

	private:
		void Init();
		void InitTableWidget(const unsigned int dataLen);
		/*增一码减一码等*/
		void SetTableData();
		bool ParseCfgFile(const QString &file, uchar* pData);
		void GetInfoFromVariant(const QVariantList &list, uchar* data, uint dataLen);
		Ui::CEditData ui;
		const unsigned int m_u4DataLen;
		const unsigned int m_u4FrameNumPos;
		uchar *const m_pData;
		bool m_bConnection;
		
	private slots:
		void CreateAddOneCode();
		void CreateSubOneCode();
		void CreateConstantCode();
		bool CreateCodeFromFile();

		void InPutChangedCallbackof_radioAddOne();
		void InPutChangedCallbackof_radioSubOne();
		void InPutChangedCallbackof_radioBConstant();
		void InPutChangedCallbackof_radioReadFile();
		void InPutChangedCallbackof_spinConstant();
		void InPutChangedCallbackof_tableWidget(int row,int col);
	};
}
QT_END_NAMESPACE
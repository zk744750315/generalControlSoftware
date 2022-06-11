//构造QByteArray ba，传?参数为const char*
QByteArray ba("010203");
//ba保存的是?个?个字符
qDebug()<<"1:"<<ba;    //"010203"
//将?个个字符转成10进制数字对应的16进制数字
qDebug()<<"2:"<<ba.toHex();    //"303130323033"
//将?个个字符转成两个字符为?个数的16进制表?
qDebug()<<"3:"<<QByteArray::fromHex(ba);    //"\x01\x02\x03"


	/*16进制数据的打印*/
	char temp = 0xff;
	QString str = QString::number((unsigned char)temp, 16).toUpper().rightJustified(2, QChar('0'));



#include "QtWidgetsApplication3.h"
#include <QtWidgets/QApplication>
#include <QByteArray>
#include <QDebug>
#define CmdInfo2										"00000000" 
static unsigned char char_to_hex(unsigned char x)
{
	return (unsigned char)(x > 9 ? x + 55 : x + 48);
}

//单个字符
char ConvertHexChar(char c)
{
	if ((c >= '0') && (c <= '9'))
		return c - 0x30;
	else if ((c >= 'A') && (c <= 'F'))
		return c - 'A' + 10;//'A' = 65;
	else if ((c >= 'a') && (c <= 'f'))
		return c - 'a' + 10;
	else
		return -1;
}
//字符串
QByteArray QString2Hex(QString hexStr)			/*QString->QByteArray,从本地打开数据文件可以用这个函数解析*/
{
	QByteArray senddata;
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = hexStr.length();
	senddata.resize(len / 2);
	char lstr, hstr;
	for (int i = 0; i < len; )
	{
		//将第一个不为' '的字符赋给hstr;
		hstr = hexStr[i].toLatin1();
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		//当i >= len时，跳出循环
		if (i >= len)
			break;
		//当i < len时，将下一个字符赋值给lstr;
		lstr = hexStr[i].toLatin1();
		//将hstr和lstr转换为0-15的对应数值
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		//
		if ((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata * 16 + lowhexdata;
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	senddata.resize(hexdatalen);
	return senddata;
}

QString Byte2Acsii(uchar *Data, int iLength)
{
	QString ST = "", strT;
	int iB, iS;
	char cB, cS;

	//---
	for (int i = 0; i < iLength; i++)
	{
		iB = *(Data + i) / 16;
		if (iB >= 10)
		{
			cB = 'A' + (iB - 10);
		}
		else
			cB = '0' + iB;

		iS = *(Data + i) % 16;
		if (iS >= 10)
		{
			cS = 'A' + (iS - 10);
		}
		else
			cS = '0' + iS;
		strT = QString("%1%2 ").arg(cB).arg(cS);
		ST += strT;
	}
	return ST;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication3 w;
	///*QString  转成*/
	//QByteArray m = CmdInfo2;
	//qDebug() << QByteArray::fromHex(m);
	qDebug() << char_to_hex(90);
	char ab = 10;
	uchar arr[10] = "abcdef123";
	qDebug() << Byte2Acsii(arr, 9);
	uchar t1 = '5';
	uchar t2 = 0xff;
	qDebug() << "t1: " << t1;
	qDebug() << "t2: " << t2;
	unsigned char te = 6;
	QString i = "ff";
	bool bi = true;
	qDebug() << i.toUInt(&bi, 16);
	QString str= "aabbddeeff";
	QByteArray bytedata = str.toUtf8();
	bytedata = bytedata.toHex().toUpper();
	qDebug() << bytedata;
	qDebug() << QString2Hex(str);
	qDebug() << QString2Hex(str);

	//qDebug() << str.mid(0,2);
	//qDebug() << str.length();
	///*16进制数据的打印*/
	//uchar bo = str.mid(0, 2).toUInt(NULL, 16);
	//qDebug() << bo;
	//char temp = 0xff;
	//QString str1 = QString::number((unsigned char)temp, 16).toUpper().rightJustified(2, QChar('0'));
	//qDebug() << str1;

    w.show();
    return a.exec(); 
	
}

十六进制数据的一些问题：
1：读取
 	从ui界面读取上来的是16进制的字符串，转为整形的方法：uchar = str.mid(0, 2).toUInt(NULL, 16)；/从str中取最开始的两个字符进行转化,就转两个字符/
	从本地读取上来的是一些QList数据，可以直接放在内存数组中；从tcp口传过来的也是整形数据，可以直接读取；
2：16进制数据的打印问题，需要再界面上以16进制进行打印如下：
		char temp = 255;
		QString str1 = QString::number((unsigned char)temp, 16).toUpper().rightJustified(2, QChar('0'));
		qDebug() << str1;

/*二维数组的建立*/
int **edge = new int*[frame.rows];
for (int k = 0; k < frame.rows; ++k)
{
	edge[k] = new int[frame.cols];
	memset(edge[k], 0, sizeof(int)*frame.cols);
}

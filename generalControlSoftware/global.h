#pragma once
#pragma execution_character_set("utf-8")
#include <QApplication>
#include <QDebug>
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
uchar strHex2char(QString hex)
{
	uchar b = ConvertHexChar(hex[0].toLatin1()) * 16 + ConvertHexChar(hex[1].toLatin1());
	return b;
}
QByteArray QString2Hex(QString hexStr)
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
void  QStringtoHex(QString hexStr, uchar *rst, size_t &size)
{
	QByteArray senddata;
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = hexStr.length();
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
		rst[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	size = hexdatalen--;
	//return senddata;
	return;
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
int mymain(int argc, char *argv[])
{
	///*QString  转成*/
	//QByteArray m = CmdInfo2;
	//qDebug() << QByteArray::fromHex(m);
	qDebug() << "char_to_hex(90)" << char_to_hex(90);


	QString str = "aa bb dd ee ff";
	/*QString 转成十六进制字节数组*/
	qDebug() << QString2Hex(str);/*QString 转成十六进制字节数组*/


	/*16进制长字符串转为uchar数组     必用*/
	size_t num = str.length() / 2;
	uchar *rst = new uchar[num];
	uchar*rst_copy = rst;
	QStringtoHex(str, rst, num);
	for (int i = 0; i < num; i++)
	{
		qDebug() << "i(" << i << "):  " << *rst++;
	}
	/*指向原来的位置*/
	rst = rst - num;
	if (NULL != rst)
	{
		delete rst;
	}

	/*整形输出为16进制字符串*/
	char temp = 255;
	QString str1 = QString::number((unsigned char)temp, 16).toUpper().rightJustified(2, QChar('0'));
	qDebug() << str1;

	/*从16进制字符转为整形1*/
	uchar bo = str.mid(0, 2).toUInt(NULL, 16);
	//bo = str.toUInt(NULL, 16);
	qDebug() << "bo" << bo;

	/*从16进制字符转为整形2*/
	QString arr1 = "ff";
	qDebug() << "strHex2char(arr1):" << strHex2char(arr1);
}

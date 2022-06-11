#pragma once
#pragma execution_character_set("utf-8")
#include <QApplication>
#include <QDebug>
static unsigned char char_to_hex(unsigned char x)
{
	return (unsigned char)(x > 9 ? x + 55 : x + 48);
}

//�����ַ�
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
//�ַ���
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
		//����һ����Ϊ' '���ַ�����hstr;
		hstr = hexStr[i].toLatin1();
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		//��i >= lenʱ������ѭ��
		if (i >= len)
			break;
		//��i < lenʱ������һ���ַ���ֵ��lstr;
		lstr = hexStr[i].toLatin1();
		//��hstr��lstrת��Ϊ0-15�Ķ�Ӧ��ֵ
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
		//����һ����Ϊ' '���ַ�����hstr;
		hstr = hexStr[i].toLatin1();
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		//��i >= lenʱ������ѭ��
		if (i >= len)
			break;
		//��i < lenʱ������һ���ַ���ֵ��lstr;
		lstr = hexStr[i].toLatin1();
		//��hstr��lstrת��Ϊ0-15�Ķ�Ӧ��ֵ
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
	///*QString  ת��*/
	//QByteArray m = CmdInfo2;
	//qDebug() << QByteArray::fromHex(m);
	qDebug() << "char_to_hex(90)" << char_to_hex(90);


	QString str = "aa bb dd ee ff";
	/*QString ת��ʮ�������ֽ�����*/
	qDebug() << QString2Hex(str);/*QString ת��ʮ�������ֽ�����*/


	/*16���Ƴ��ַ���תΪuchar����     ����*/
	size_t num = str.length() / 2;
	uchar *rst = new uchar[num];
	uchar*rst_copy = rst;
	QStringtoHex(str, rst, num);
	for (int i = 0; i < num; i++)
	{
		qDebug() << "i(" << i << "):  " << *rst++;
	}
	/*ָ��ԭ����λ��*/
	rst = rst - num;
	if (NULL != rst)
	{
		delete rst;
	}

	/*�������Ϊ16�����ַ���*/
	char temp = 255;
	QString str1 = QString::number((unsigned char)temp, 16).toUpper().rightJustified(2, QChar('0'));
	qDebug() << str1;

	/*��16�����ַ�תΪ����1*/
	uchar bo = str.mid(0, 2).toUInt(NULL, 16);
	//bo = str.toUInt(NULL, 16);
	qDebug() << "bo" << bo;

	/*��16�����ַ�תΪ����2*/
	QString arr1 = "ff";
	qDebug() << "strHex2char(arr1):" << strHex2char(arr1);
}

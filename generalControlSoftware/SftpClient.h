#pragma once

#include "Include_LibSSH2/libssh2.h"
#include "Include_LibSSH2/libssh2_sftp.h"
#include "XSleep.h"
#include <QWidget>

#include <string>
using namespace std;

#pragma comment(lib, "./Lib_LibSSH2/libssh2.lib") 
#pragma comment(lib,"ws2_32.lib")

class CSftpClient
{
public:
	CSftpClient();
	virtual ~CSftpClient();
	
	void SetPara(const QString& strIp, int iPort, const QString& strUser, const QString& strPswd);

	bool Open(QString& strMsg);
	void Close();

	bool Upload(const QString& strLocalSwFile, const QString& strRemoteSwFile, QString& strMsg);
	
	bool Download(const QString& strLocalSwFile, const QString& strRemoteSwFile, QString& strMsg);


private:
	QString m_strIp;
	int     m_iPort;
	QString m_strUser;
	QString m_strPswd;

	LIBSSH2_SESSION *m_pSession;
	LIBSSH2_SFTP *m_pSftpSession;
	int m_sock;
};


//#include "stdafx.h"
#include <atlconv.h>
#include "stdio.h"
#include "SftpClient.h"
#include <Ws2tcpip.h>

using namespace std;

CSftpClient::CSftpClient()
{
	m_strIp = ("");
	m_iPort = -1;
	m_strUser = ("");
	m_strPswd = ("");

	m_pSession = NULL;
	m_pSftpSession = NULL;
	m_sock = -1;
}


CSftpClient::~CSftpClient()
{
	Close();
}

void CSftpClient::SetPara(const QString& strIp, int iPort, const QString& strUser, const QString& strPswd)
{
	m_strIp = strIp;
	m_iPort = iPort;
	m_strUser = strUser;
	m_strPswd = strPswd;
}

void CSftpClient::Close()
{
	if (NULL != m_pSftpSession)
	{
		libssh2_sftp_shutdown(m_pSftpSession);
		m_pSftpSession = NULL;
	}

	if (NULL != m_pSession)
	{
		libssh2_session_disconnect(m_pSession, "Normal Shutdown, Thank you for playing");
		libssh2_session_free(m_pSession);
		m_pSession = NULL;
	}

	if (-1 != m_sock)
	{
		closesocket(m_sock);
		m_sock = -1;
	}
}

bool CSftpClient::Open(QString& strMsg)
{
	USES_CONVERSION;
	
	int iRtn;

	try
	{
		WSADATA wsadata;
		iRtn = WSAStartup(MAKEWORD(2, 0), &wsadata);
		if (0 != iRtn)
		{
			strMsg = ("CSftpClient::SftpUpload()::WSAStartup() fail!");
			throw 1;
		}

		iRtn = libssh2_init(0);
		if (0 != iRtn)
		{
			strMsg = ("CSftpClient::SftpUpload()::libssh2_init() fail!");
			throw 1;
		}

		IN_ADDR oHostAddr;
		struct sockaddr_in oSocketAddr;

		const char *fingerprint = NULL;
		FILE *pLocalFile = NULL;
		LIBSSH2_SFTP_HANDLE *sftp_handle = NULL;
		//inet_pton(AF_INET, W2A(m_strIp), &oHostAddr);
		inet_pton(AF_INET, m_strIp.toStdString().c_str(), &oHostAddr);

		//新建连接  
		m_sock = socket(AF_INET, SOCK_STREAM, 0);
		if (-1 == m_sock)
		{
			strMsg = ("CSftpClient::SftpUpload()::socket() fail!");
			throw 1;
		}
		oSocketAddr.sin_family = AF_INET;
		oSocketAddr.sin_port = htons(m_iPort);
		oSocketAddr.sin_addr.s_addr = oHostAddr.S_un.S_addr;

		if (0 != connect(m_sock, (struct sockaddr*)(&oSocketAddr), sizeof(struct sockaddr_in)))
		{
			strMsg = ("CSftpClient::SftpUpload()::connect() fail!");
			throw 2;
		}

		//新建对话实例  
		m_pSession = libssh2_session_init();
		if (!m_pSession)
		{
			closesocket(m_sock);
			m_sock = -1;
			strMsg = ("CSftpClient::SftpUpload()::libssh2_session_init() fail!");
			throw 3;
		}

		//设置调用阻塞  
		libssh2_session_set_blocking(m_pSession, 1);

		//进行握手  
		iRtn = libssh2_session_startup(m_pSession, m_sock);
		if (iRtn)
		{
			libssh2_session_free(m_pSession);
			m_pSession = NULL;
			closesocket(m_sock);
			m_sock = -1;

			strMsg = ("CSftpClient::SftpUpload()::libssh2_session_startup() fail!");
			throw 4;
		}

		//检查主机指纹  
		fingerprint = libssh2_hostkey_hash(m_pSession, LIBSSH2_HOSTKEY_HASH_SHA1);

		//通过密码验证登陆用户身份  
		if (libssh2_userauth_password(m_pSession, m_strUser.toStdString().c_str(), m_strPswd.toStdString().c_str()))
		{
			strMsg = ("CSftpClient::SftpUpload()::libssh2_userauth_password() fail!");
			throw 5;
		}

		m_pSftpSession = libssh2_sftp_init(m_pSession);

		if (!m_pSftpSession)
		{
			strMsg = ("CSftpClient::SftpUpload()::libssh2_sftp_init() fail!");
			throw 6;
		}
	}
	catch (...)
	{
		return false;
	}

	return true;
}

bool CSftpClient::Upload(const QString& strLocalSwFile, const QString& strRemoteSwFile, QString& strMsg)
{
	if (0 >= strLocalSwFile.length())
	{
		strMsg = ("strLocalSwFile.GetLength() <= 0");
		return false;
	}

	USES_CONVERSION;

	LIBSSH2_SFTP_HANDLE *sftp_handle = NULL;
	FILE *pLocalFile = NULL;
	int iRtn = 0;

	try
	{
		//check file exist
		DWORD dwAttrib = ::GetFileAttributes(strLocalSwFile.toStdWString().c_str());
		if ((INVALID_FILE_ATTRIBUTES == dwAttrib) || (0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY)))
		{
			strMsg=("Error: local file: %s is not existed!", strLocalSwFile);
			throw 1;
		}

		char caLocalFile[512] = { 0 };
		WideCharToMultiByte(CP_ACP, NULL, strLocalSwFile.toStdWString().c_str(), -1, (char *)caLocalFile, 512, NULL, NULL);
		char caRemoteFileName[512] = { 0 };
		WideCharToMultiByte(CP_ACP, NULL, strRemoteSwFile.toStdWString().c_str(), -1, (char *)caRemoteFileName, 512, NULL, NULL);

		//向SFTP服务器发出新建文件请求  
		sftp_handle = libssh2_sftp_open(m_pSftpSession, strRemoteSwFile.toStdString().c_str(), LIBSSH2_FXF_WRITE | LIBSSH2_FXF_CREAT | LIBSSH2_FXF_TRUNC,
			LIBSSH2_SFTP_S_IRUSR | LIBSSH2_SFTP_S_IWUSR | LIBSSH2_SFTP_S_IRGRP | LIBSSH2_SFTP_S_IROTH);

		if (!sftp_handle)
		{
			strMsg = ("CSftpClient::SftpUpload()::libssh2_sftp_open() fail!");
			throw 6;
		}

		//if (fopen_s(&pLocalFile, W2A(strLocalSwFile), "rb") != 0)
		//{
		//	strMsg = ("CSftpClient::SftpUpload()::fopen_s() fail!");
		//	throw 6;
		//}

		if (NULL == (pLocalFile = _fsopen(strLocalSwFile.toStdString().c_str(), "rb", _SH_DENYWR)))
		{
			strMsg = ("CSftpClient::SftpUpload()::_fspen() fail!");
			throw 6;
		}

		//取待上传文件整个size_t.  
		fseek(pLocalFile, 0, SEEK_END);
		size_t filesize_t = ftell(pLocalFile);//local file大小，在readFromDisk中被引用  
		fseek(pLocalFile, 0, SEEK_SET);//文件指针重置到文件头  

		char mem[1024 * 16] = { 0 };
		size_t nread = 0;
		char *ptr = NULL;
		size_t count = 0;

		do
		{
			nread = fread(mem, 1, sizeof(mem), pLocalFile);
			if (0 >= nread)
			{
				//到达文件尾部  
				break;
			}

			ptr = mem;
			do
			{
				// 向服务器写数据，直到数据写完毕  
				iRtn = libssh2_sftp_write(sftp_handle, ptr, nread);
				if (iRtn < 0)
				{
					break;
				}
				ptr += iRtn;
				count += nread;
				nread -= iRtn;

			} while (nread);

		} while (iRtn > 0);
	}
	catch (...)
	{
		fclose(pLocalFile);
		return false;
	}
	fclose(pLocalFile);

	strMsg = ("SFTP Upload file OK!");
	return true;
}

bool CSftpClient::Download(const QString& strLocalSwFile, const QString& strRemoteSwFile, QString& strMsg)
{
	USES_CONVERSION;

	if (0 >= strRemoteSwFile.length())
	{
		strMsg = ("strRemoteSwFile.GetLength() <= 0");
		return false;
	}

	LIBSSH2_SFTP_HANDLE *sftp_handle = NULL;
	FILE *pLocalFile = NULL;
	int iRtn = 0;

	try
	{
		//download file
		//向服务器发出文件请求  
		sftp_handle = libssh2_sftp_open(m_pSftpSession, strRemoteSwFile.toStdString().c_str(), LIBSSH2_FXF_READ, 0);
		if (!sftp_handle)
		{
			strMsg = ("CSftpClient::SftpDownload()::libssh2_sftp_open() fail!");
			throw 1;
		}

		FILE *stream;
		if (fopen_s(&stream, strLocalSwFile.toStdString().c_str(), "wb") == 0)
		{
			size_t rc;
			char mem[1024] = { 0 };
			do 
			{
				memset(mem, 0, 1024);
				/* loop until we fail */
				rc = libssh2_sftp_read(sftp_handle, mem, sizeof(mem));

				if (rc > 0) 
				{
					//从内存到磁盘
					fwrite(mem, 1, rc, stream);
				}
				else 
				{
					break;
				}
			} while (1);

			fclose(stream);
		}
		else 
		{
			strMsg = ("CSftpClient::SftpDownload()::fopen_s() fail!");
			throw 2;
		}
	}
	catch (...)
	{
		return false;
	}

	return true;
}


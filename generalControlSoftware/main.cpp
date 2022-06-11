#include "CgeneralControlSoftware.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <Windows.h>

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
	/*创建唯一实例*/
	HANDLE hAppMutex = CreateMutex(NULL,false,(LPCWSTR)"generalControlSoftware");
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		QMessageBox::critical(NULL,
			"消息",
			"已经有一个应用程序正在运行！");
		return -1;
	}
    CGeneralControlSoftware w;
    w.show();
    return a.exec();
}

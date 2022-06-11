#include "CgeneralControlSoftware.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <Windows.h>

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QApplication a(argc, argv);
	/*����Ψһʵ��*/
	HANDLE hAppMutex = CreateMutex(NULL,false,(LPCWSTR)"generalControlSoftware");
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		QMessageBox::critical(NULL,
			"��Ϣ",
			"�Ѿ���һ��Ӧ�ó����������У�");
		return -1;
	}
    CGeneralControlSoftware w;
    w.show();
    return a.exec();
}

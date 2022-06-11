#ifndef _XSLEEP_H_
#define _XSLEEP_H_
struct XSleep_Structure
{
	int duration;
	HANDLE eventHandle;
};
DWORD WINAPI XSleepThread(LPVOID pWaitTime);
void XSleep(int nWaitInMSecs);

#endif // _XSLEEP_H_

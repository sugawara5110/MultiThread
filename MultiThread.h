//*****************************************************************************************//
//**                                                                                     **//
//**                              MultiThread                                            **//
//**                                                                                     **//
//*****************************************************************************************//

#include <windows.h>
#include <process.h>
#include <iostream>

struct ThreadData {
	bool end = false;
	void(*pfunc)(void) = nullptr;
};

class MultiThread {

private:
	static const int numMaxThread = 10;
	static unsigned int numThread;
	static bool UpDateThreadLoop;
	static HANDLE ThreadHandle[numMaxThread];
	static HANDLE eventBigin[numMaxThread];
	static HANDLE eventEnd[numMaxThread];
	static ThreadData th[numMaxThread];

	static unsigned __stdcall thread0(void* data);
	static unsigned __stdcall thread1(void* data);
	static unsigned __stdcall thread2(void* data);
	static unsigned __stdcall thread3(void* data);
	static unsigned __stdcall thread4(void* data);
	static unsigned __stdcall thread5(void* data);
	static unsigned __stdcall thread6(void* data);
	static unsigned __stdcall thread7(void* data);
	static unsigned __stdcall thread8(void* data);
	static unsigned __stdcall thread9(void* data);
	static void setThread();

public:
	static void setFunc(void (*pf)(void));
	static void start();
	static void wait();
	static void end();
};

class MultiThread_NotSync {

private:
	static const int numMaxThread = 10;
	static unsigned int numThread;
	static HANDLE ThreadHandle[numMaxThread];
	static ThreadData th[numMaxThread];

	static unsigned __stdcall thread0(void* data);
	static unsigned __stdcall thread1(void* data);
	static unsigned __stdcall thread2(void* data);
	static unsigned __stdcall thread3(void* data);
	static unsigned __stdcall thread4(void* data);
	static unsigned __stdcall thread5(void* data);
	static unsigned __stdcall thread6(void* data);
	static unsigned __stdcall thread7(void* data);
	static unsigned __stdcall thread8(void* data);
	static unsigned __stdcall thread9(void* data);
	static void setThread();

public:
	static void setFunc(void (*pf)(void));
	static void start();
	static bool Status();
	static void end();
};
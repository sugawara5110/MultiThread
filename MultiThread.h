//*****************************************************************************************//
//**                                                                                     **//
//**                              MultiThread                                            **//
//**                                                                                     **//
//*****************************************************************************************//

#ifndef Class_MultiThread_Header
#define Class_MultiThread_Header

#include <windows.h>
#include <process.h>
#include <iostream>

struct ThreadData {
	bool end = false;
	void(*pfunc)(void) = nullptr;
	int eventNo = 0;
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

	static unsigned __stdcall thread(void* data);
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

	static unsigned __stdcall thread(void* data);
	static void setThread();

public:
	static void setFunc(void (*pf)(void));
	static void start();
	static bool Status();
	static void end();
};

#endif
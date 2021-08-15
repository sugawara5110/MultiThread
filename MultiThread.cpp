//*****************************************************************************************//
//**                                                                                     **//
//**                              MultiThread                                            **//
//**                                                                                     **//
//*****************************************************************************************//

#include "MultiThread.h"

unsigned int MultiThread::numThread = 0;
bool MultiThread::UpDateThreadLoop = false;
HANDLE MultiThread::ThreadHandle[numMaxThread] = {};
HANDLE MultiThread::eventBigin[numMaxThread] = {};
HANDLE MultiThread::eventEnd[numMaxThread] = {};
ThreadData MultiThread::th[numMaxThread] = {};

void MultiThread::setFunc(void (*pf)(void)) {
	ThreadData& t = th[numThread];
	t.pfunc = pf;
	numThread++;
}

void MultiThread::setThread() {
	for (unsigned int i = 0; i < numThread; i++)
		ThreadHandle[i] = (HANDLE*)_beginthreadex(NULL, 0, thread, &th[i], 0, NULL);

	bool f = true;
	while (f) {
		f = false;
		for (unsigned int i = 0; i < numThread; i++) {
			if (!ThreadHandle[i])f = true;
		}
	}
}

void MultiThread::start() {
	UpDateThreadLoop = true;
	for (unsigned int i = 0; i < numThread; i++) {
		eventBigin[i] = CreateEvent(NULL, FALSE, FALSE, NULL);
		eventEnd[i] = CreateEvent(NULL, FALSE, FALSE, NULL);
	}
	for (unsigned int i = 0; i < numThread; i++) {
		ThreadData& t = th[i];
		t.end = false;
		t.eventNo = i;
	}
	th[numThread - 1].end = true;
	setThread();
}

void MultiThread::wait() {
	SetEvent(eventBigin[0]);//ここから全スレッドが動き出す
	WaitForSingleObject(eventEnd[numThread - 1], INFINITE);//全スレッド終了まで待機
}

void MultiThread::end() {
	UpDateThreadLoop = false;
	SetEvent(eventBigin[0]);
	WaitForSingleObject(eventEnd[numThread - 1], INFINITE);
	for (unsigned int i = 0; i < numThread; i++) {
		CloseHandle(ThreadHandle[i]);
		ThreadHandle[i] = nullptr;
	}
	for (unsigned int i = 0; i < numThread; i++) {
		CloseHandle(eventBigin[i]);
		CloseHandle(eventEnd[i]);
		eventBigin[i] = nullptr;
		eventEnd[i] = nullptr;
	}
	numThread = 0;
}

unsigned __stdcall MultiThread::thread(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[da->eventNo], INFINITE);
		if (!da->end)SetEvent(eventBigin[da->eventNo + 1]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - (da->eventNo + 2)], INFINITE);
		SetEvent(eventEnd[numThread - (da->eventNo + 1)]);
	}
	return 0;
}

unsigned int MultiThread_NotSync::numThread = 0;
HANDLE MultiThread_NotSync::ThreadHandle[numMaxThread] = {};
ThreadData MultiThread_NotSync::th[numMaxThread] = {};

void MultiThread_NotSync::setFunc(void (*pf)(void)) {
	ThreadData& t = th[numThread];
	t.pfunc = pf;
	numThread++;
}

void MultiThread_NotSync::setThread() {
	for (unsigned int i = 0; i < numThread; i++)
		ThreadHandle[i] = (HANDLE*)_beginthreadex(NULL, 0, thread, &th[i], 0, NULL);

	bool f = true;
	while (f) {
		f = false;
		for (unsigned int i = 0; i < numThread; i++) {
			if (!ThreadHandle[i])f = true;
		}
	}
}

void MultiThread_NotSync::start() {
	setThread();
}

bool MultiThread_NotSync::Status() {
	DWORD dw = WaitForMultipleObjects((DWORD)numThread, ThreadHandle, true, 0);
	if (dw == WAIT_OBJECT_0 + numThread - 1)
		return true;
	else
		return false;
}

void MultiThread_NotSync::end() {
	WaitForMultipleObjects((DWORD)numThread, ThreadHandle, true, INFINITE);
	for (unsigned int i = 0; i < numThread; i++) {
		CloseHandle(ThreadHandle[i]);
		ThreadHandle[i] = nullptr;
	}
	numThread = 0;
}

unsigned __stdcall MultiThread_NotSync::thread(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

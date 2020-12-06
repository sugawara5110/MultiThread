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
	if (numThread > 0)ThreadHandle[0] = (HANDLE*)_beginthreadex(NULL, 0, thread0, &th[0], 0, NULL);
	if (numThread > 1)ThreadHandle[1] = (HANDLE*)_beginthreadex(NULL, 0, thread1, &th[1], 0, NULL);
	if (numThread > 2)ThreadHandle[2] = (HANDLE*)_beginthreadex(NULL, 0, thread2, &th[2], 0, NULL);
	if (numThread > 3)ThreadHandle[3] = (HANDLE*)_beginthreadex(NULL, 0, thread3, &th[3], 0, NULL);
	if (numThread > 4)ThreadHandle[4] = (HANDLE*)_beginthreadex(NULL, 0, thread4, &th[4], 0, NULL);
	if (numThread > 5)ThreadHandle[5] = (HANDLE*)_beginthreadex(NULL, 0, thread5, &th[5], 0, NULL);
	if (numThread > 6)ThreadHandle[6] = (HANDLE*)_beginthreadex(NULL, 0, thread6, &th[6], 0, NULL);
	if (numThread > 7)ThreadHandle[7] = (HANDLE*)_beginthreadex(NULL, 0, thread7, &th[7], 0, NULL);
	if (numThread > 8)ThreadHandle[8] = (HANDLE*)_beginthreadex(NULL, 0, thread8, &th[8], 0, NULL);
	if (numThread > 9)ThreadHandle[9] = (HANDLE*)_beginthreadex(NULL, 0, thread9, &th[9], 0, NULL);
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
}

unsigned __stdcall MultiThread::thread0(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[0], INFINITE);
		if (!da->end)SetEvent(eventBigin[1]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 2], INFINITE);
		SetEvent(eventEnd[numThread - 1]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread1(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[1], INFINITE);
		if (!da->end)SetEvent(eventBigin[2]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 3], INFINITE);
		SetEvent(eventEnd[numThread - 2]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread2(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[2], INFINITE);
		if (!da->end)SetEvent(eventBigin[3]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 4], INFINITE);
		SetEvent(eventEnd[numThread - 3]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread3(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[3], INFINITE);
		if (!da->end)SetEvent(eventBigin[4]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 5], INFINITE);
		SetEvent(eventEnd[numThread - 4]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread4(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[4], INFINITE);
		if (!da->end)SetEvent(eventBigin[5]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 6], INFINITE);
		SetEvent(eventEnd[numThread - 5]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread5(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[5], INFINITE);
		if (!da->end)SetEvent(eventBigin[6]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 7], INFINITE);
		SetEvent(eventEnd[numThread - 6]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread6(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[6], INFINITE);
		if (!da->end)SetEvent(eventBigin[7]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 8], INFINITE);
		SetEvent(eventEnd[numThread - 7]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread7(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[7], INFINITE);
		if (!da->end)SetEvent(eventBigin[8]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 9], INFINITE);
		SetEvent(eventEnd[numThread - 8]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread8(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[8], INFINITE);
		if (!da->end)SetEvent(eventBigin[9]);
		da->pfunc();
		if (!da->end)WaitForSingleObject(eventEnd[numThread - 10], INFINITE);
		SetEvent(eventEnd[numThread - 9]);
	}
	return 0;
}

unsigned __stdcall MultiThread::thread9(void* data) {
	ThreadData* da = (ThreadData*)data;
	while (UpDateThreadLoop) {
		WaitForSingleObject(eventBigin[9], INFINITE);
		da->pfunc();
		SetEvent(eventEnd[numThread - 10]);
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
	if (numThread > 0)ThreadHandle[0] = (HANDLE*)_beginthreadex(NULL, 0, thread0, &th[0], 0, NULL);
	if (numThread > 1)ThreadHandle[1] = (HANDLE*)_beginthreadex(NULL, 0, thread1, &th[1], 0, NULL);
	if (numThread > 2)ThreadHandle[2] = (HANDLE*)_beginthreadex(NULL, 0, thread2, &th[2], 0, NULL);
	if (numThread > 3)ThreadHandle[3] = (HANDLE*)_beginthreadex(NULL, 0, thread3, &th[3], 0, NULL);
	if (numThread > 4)ThreadHandle[4] = (HANDLE*)_beginthreadex(NULL, 0, thread4, &th[4], 0, NULL);
	if (numThread > 5)ThreadHandle[5] = (HANDLE*)_beginthreadex(NULL, 0, thread5, &th[5], 0, NULL);
	if (numThread > 6)ThreadHandle[6] = (HANDLE*)_beginthreadex(NULL, 0, thread6, &th[6], 0, NULL);
	if (numThread > 7)ThreadHandle[7] = (HANDLE*)_beginthreadex(NULL, 0, thread7, &th[7], 0, NULL);
	if (numThread > 8)ThreadHandle[8] = (HANDLE*)_beginthreadex(NULL, 0, thread8, &th[8], 0, NULL);
	if (numThread > 9)ThreadHandle[9] = (HANDLE*)_beginthreadex(NULL, 0, thread9, &th[9], 0, NULL);
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
}

unsigned __stdcall MultiThread_NotSync::thread0(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread1(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread2(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread3(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread4(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread5(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread6(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread7(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread8(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}

unsigned __stdcall MultiThread_NotSync::thread9(void* data) {
	ThreadData* da = (ThreadData*)data;
	da->pfunc();
	return 0;
}
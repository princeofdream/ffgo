#include "stdafx.h"
#include "include\PThread_ffgo.h"
#include "include/grabScreen.h"

Ffmpeg_Encoder *mFfmpeg_Encoder;

PThread_ffgo::PThread_ffgo()
{
	mFfmpeg_Encoder = new Ffmpeg_Encoder();
}


PThread_ffgo::~PThread_ffgo()
{
	delete mFfmpeg_Encoder;
}



UINT __cdecl ThreadProc(LPVOID pParam)
{
	int i0 = 0;
	int ret = 0;
	CString * pStr = (CString*)pParam;
	//*pStr = _T("Hello World!");
#if 0
	while (true)
	{
		printf("Thread test loop: %d.\n", i0);
		i0++;
		if (i0 > 20)
			break;
		Sleep(500);
	}
#else
	//ProcessManager mproc;
	//mproc.Start_New_Process("ping", "127.0.0.1", "-n 10", NULL);
	printf("=================== Start Rec ================\n");
#if 1
	//Start_Rec(0, NULL);
	//Start_SDL_Rec(0, NULL);
	mFfmpeg_Encoder->get_encoder_info();
#endif
	printf("=================== Stop Rec ================\n");
#endif
	AfxEndThread(ret,TRUE/*�Ƿ�ɾ���ֳ���ռ�õ��ڴ�*/ ); //��ǰ�˳��̺߳���
	return 0;
}



UINT PThread_ffgo::Start_PThread(long* pParam)
{
#if 1	//thread test
	CWinThread *pThread = NULL;
	CString strArg = _T("");

	pThread = AfxBeginThread(
		ThreadProc,         //�߳���������
		&strArg,          //�߳���������
		THREAD_PRIORITY_NORMAL,       //�߳����ȼ�
		0,            //Windowsϵͳһ���߳�ջ��СΪ1 MB�������̵߳���Ŀ�������ڴ��ջ�ռ��С�й�
		0,            //�̴߳�����־���磺CREATE_SUSPENDED
		NULL);           //ϵͳ��ȫ������NULL

	if (pThread < 0)
	{
		printf("Start PThread Fail!!!\n");
	}
#if 0
	else
	{
		printf("Start PThread Sucess!\n");
		//pThread->m_bAutoDelete = TRUE;     //���߳̽������Զ�����̶߳���,Ĭ����TRUE
		//WaitForSingleObject(pThread->m_hThread, INFINITE); //�ȴ��߳̽���
													   //AfxMessageBox(strArg);
	}
#endif
#endif
	return 0;
}



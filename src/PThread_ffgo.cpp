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
	AfxEndThread(ret,TRUE/*是否删除现成所占用的内存*/ ); //提前退出线程函数
	return 0;
}



UINT PThread_ffgo::Start_PThread(long* pParam)
{
#if 1	//thread test
	CWinThread *pThread = NULL;
	CString strArg = _T("");

	pThread = AfxBeginThread(
		ThreadProc,         //线程启动函数
		&strArg,          //线程启动函数
		THREAD_PRIORITY_NORMAL,       //线程优先级
		0,            //Windows系统一般线程栈大小为1 MB，创建线程的数目与物理内存和栈空间大小有关
		0,            //线程创建标志，如：CREATE_SUSPENDED
		NULL);           //系统安全描述，NULL

	if (pThread < 0)
	{
		printf("Start PThread Fail!!!\n");
	}
#if 0
	else
	{
		printf("Start PThread Sucess!\n");
		//pThread->m_bAutoDelete = TRUE;     //当线程结束是自动清除线程对象,默认是TRUE
		//WaitForSingleObject(pThread->m_hThread, INFINITE); //等待线程结束
													   //AfxMessageBox(strArg);
	}
#endif
#endif
	return 0;
}



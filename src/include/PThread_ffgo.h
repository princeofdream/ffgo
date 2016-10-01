#pragma once
#include "afxwin.h"
#include "ProcessManager.h"
#include "../CapScreenAndAudio.h"

UINT __cdecl ThreadProc(LPVOID pParam);

class PThread_ffgo :
	public CWinThread
{
public:
	PThread_ffgo();
	~PThread_ffgo();

public:
	UINT Start_PThread(long* pParam);

};


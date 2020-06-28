#include "Win32MessageDebug.h"

#define DEBUG_DEFINE(MESSAGE) \
	case MESSAGE: \
		OutputDebugString(L#MESSAGE L"\n"); \
		break;
		

void DebugWin32Message(UINT8 message)
{
	switch (message)
	{
	DEBUG_DEFINE(WM_NCCREATE)
	DEBUG_DEFINE(WM_CREATE)
	DEBUG_DEFINE(WM_DESTROY)
	DEBUG_DEFINE(WM_PAINT)
	DEBUG_DEFINE(WM_COMMAND)
	default: break;
	}
}
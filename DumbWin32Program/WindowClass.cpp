#include "Window.h"
#include "WindowClass.h"
#include "Win32MessageDebug.h"

// Change text command ID
#define ID_CHANGETEXT 1

LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	// Debug message
	OutputDebugString(L"WndProc ");
	DebugWin32Message(message);

	// Get Window
	Window* pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK WndProcSetup(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	// Debug message
	OutputDebugString(L"WndProcSetup ");
	DebugWin32Message(message);

	if (message == WM_NCCREATE)
	{
		// Initialize window before doing stuff
		const CREATESTRUCT* const pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
		Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc));
		return pWnd->HandleMsg(hWnd, message, wParam, lParam);
	}
	else
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}


void RegisterWindowClass(HINSTANCE hInstance, const TCHAR className[])
{
	// Create window class
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProcSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = className;

	// Register window class (exit if it doesn't work)
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Dumb Win32 Program"),
			NULL);
		exit(1);
	}
}
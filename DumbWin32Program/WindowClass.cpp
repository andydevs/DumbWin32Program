#include "WindowClass.h"
#include "Win32MessageDebug.h"

// Change text command ID
#define ID_CHANGETEXT 1

// Text cycler stuff
extern TextCycler* cycler;

// Window stuff
HWND hButton;

LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	// Debug message
	DebugWin32Message(message);

	// Paint stuff
	PAINTSTRUCT ps;
	HDC hdc;

	// Handle incoming messages
	switch (message)
	{
	case WM_CREATE:
		hButton = CreateWindow(
			_T("BUTTON"),
			_T("Change Text"),
			WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			350, 30, 100, 25,
			hWnd,
			(HMENU)ID_CHANGETEXT,
			GetModuleHandle(NULL),
			NULL
		);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 5, 5, cycler->current_text(), _tcslen(cycler->current_text()));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_CHANGETEXT:
			cycler->next_text();
			InvalidateRect(hWnd, 0, TRUE);
			break;
		default:
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}


void RegisterWindowClass(HINSTANCE hInstance, const TCHAR className[])
{
	// Create window class
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
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
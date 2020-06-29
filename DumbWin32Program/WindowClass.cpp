#include "Window.h"
#include "WindowClass.h"
#include "Win32MessageDebug.h"

const TCHAR* WindowClass::WINDOW_CLASS_NAME = _T("DesktopApp");

WindowClass::WindowClass()
{
	// Set name of member
	m_name = (LPTSTR)WINDOW_CLASS_NAME;

	// Get Module Name
	HINSTANCE hInstance = GetModuleHandle(NULL);

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
	wc.lpszClassName = m_name;

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

WindowClass::~WindowClass()
{
	UnregisterClass(m_name, GetModuleHandle(NULL));
}

LPTSTR WindowClass::GetName()
{
	return m_name;
}

WindowClass* WindowClass::GetInstance()
{
	static WindowClass s_instance;
	return &s_instance;
}

LRESULT CALLBACK WindowClass::WndProcSetup(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	if (message == WM_NCCREATE)
	{
		// Initialize window before doing stuff
		const CREATESTRUCT* const pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
		Window* const pWnd = reinterpret_cast<Window*>(pCreate->lpCreateParams);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WindowClass::WndProcDelegate));
		return pWnd->HandleMsg(hWnd, message, wParam, lParam);
	}
	else
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

LRESULT CALLBACK WindowClass::WndProcDelegate(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	// Get Window
	Window* pWnd = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hWnd, message, wParam, lParam);
}
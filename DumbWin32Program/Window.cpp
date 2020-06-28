#include "Window.h"
#include "Win32MessageDebug.h"
#include <tchar.h>

Window::Window(const TCHAR windowClass[], const TCHAR title[], int width, int height)
{
	m_hWnd = CreateWindow(
		windowClass,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, // Position
		width, height, // Size
		NULL,
		NULL,
		GetModuleHandle(NULL),
		this // Pass reference to window class
	);
	if (!m_hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Dumb Win32 Program"),
			NULL);
		exit(1);
	}
}

Window::~Window()
{
	DestroyWindow(m_hWnd);
}

void Window::Show(int nCmdShow)
{
	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);
}

HWND Window::GetHandle()
{
	return m_hWnd;
}

LRESULT CALLBACK Window::HandleMsg(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	OutputDebugString(L"Window::HandleMsg ");
	DebugWin32Message(message);

	// Switch message
	switch (message)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
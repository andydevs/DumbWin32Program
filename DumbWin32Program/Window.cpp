#include "Window.h"
#include "WindowClass.h"
#include "Win32MessageDebug.h"
#include <tchar.h>

Window::Window(const TCHAR title[], int width, int height)
{
	m_hWnd = CreateWindow(
		WINDOW_CLASS,
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
// Message mapping macro
#define MAPMESSAGE(MESSAGE, Handler) \
	case MESSAGE: return Handler(hWnd, message, wParam, lParam);

	// Switch message
	switch (message)
	{
	MAPMESSAGE(WM_CREATE, OnCreate)
	MAPMESSAGE(WM_PAINT, OnPaint)
	MAPMESSAGE(WM_CLOSE, OnClose)
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

LRESULT Window::OnCreate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT Window::OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TCHAR text[] = L"Example Text";
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc, 25, 10, text, _tcslen(text));
	EndPaint(hWnd, &ps);
	return 0;
}

LRESULT Window::OnClose(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}
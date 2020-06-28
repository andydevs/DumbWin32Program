#include "TextCyclerFactory.h"
#include "BushworldTextCyclerFactory.h"
#include "TomskaTextCyclerFactory.h"
#include "WindowClass.h"
#include "Window.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>

// String buffers for window class name and window title
const TCHAR szTitle[] = _T("Dumb Win32 Program");

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	// Register window class
	RegisterWindowClass();

	// Initialize texts system
	TomskaTextCyclerFactory factory;

	// Create that window!
	Window appWindow(szTitle, 500, 100);
	appWindow.Show(nCmdShow);

	// Message Loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Unregister Window Class
	UnregisterWindowClass();

	// Return final message status?
	return msg.wParam;
}
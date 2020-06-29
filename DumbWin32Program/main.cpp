#include "TextCyclerFactory.h"
#include "BushworldTextCyclerFactory.h"
#include "TomskaTextCyclerFactory.h"
#include "WindowClass.h"
#include "Window.h"
#include "UIWindow.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	// String buffer for window title
	TCHAR windowTitle[] = _T("Dumb Win32 Program");

	// Initialize texts system
	BushworldTextCyclerFactory factory;

	// Create that window!
	UIWindow appWindow(factory, windowTitle, 500, 125);
	appWindow.Show(nCmdShow);

	// Message Loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Return final message status?
	return msg.wParam;
}
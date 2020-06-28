#include "TextCyclerFactory.h"
#include "BushworldTextCyclerFactory.h"
#include "TomskaTextCyclerFactory.h"
#include "WindowClass.h"
#include "Window.h"
#include <Windows.h>
#include <tchar.h>
#include <iostream>

// String buffers for window class name and window title
const TCHAR szWindowClass[] = _T("DesktopApp");
const TCHAR szTitle[] = _T("Dumb Win32 Program");

TextCycler* cycler;

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	// Initialize texts system
	TextCyclerFactory *factory = new TomskaTextCyclerFactory();
	cycler = factory->createTextCycler();

	// Register window class
	RegisterWindowClass(hInstance, szWindowClass); 

	// Create that window!
	Window appWindow(szWindowClass, szTitle, 500, 100);
	appWindow.Show(nCmdShow);

	// Message Loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Clear memory
	delete factory;
	delete cycler;

	// Return final message status?
	return msg.wParam;
}
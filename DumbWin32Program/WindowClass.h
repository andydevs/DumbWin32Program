#pragma once
#include "TextCycler.h"
#include <Windows.h>
#include <tchar.h>

class WindowClass
{
private:
	// Window class name
	static const TCHAR* WINDOW_CLASS_NAME;
public:
	static WindowClass* GetInstance();
	static LRESULT CALLBACK WndProcSetup(
		_In_ HWND hWnd,
		_In_ UINT message,
		_In_ WPARAM wParam,
		_In_ LPARAM lParam
	);
	static LRESULT CALLBACK WndProcDelegate(
		_In_ HWND hWnd,
		_In_ UINT message,
		_In_ WPARAM wParam,
		_In_ LPARAM lParam
	);
private:
	LPTSTR m_name;
	WindowClass();
	~WindowClass();
	WindowClass(const WindowClass&) = delete;
	void operator=(const WindowClass&) = delete;
public:
	LPTSTR GetName();
};
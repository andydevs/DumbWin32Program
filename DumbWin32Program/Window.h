#pragma once
#include <Windows.h>

class Window
{
private:
	HWND m_hWnd;
public:
	Window(const TCHAR windowClass[], const TCHAR title[], int width, int height);
	~Window();
	void Show(int nCmdShow);
	HWND GetHandle();
};


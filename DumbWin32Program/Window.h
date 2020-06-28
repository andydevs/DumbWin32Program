#pragma once
#include <Windows.h>

class Window
{
private:
	HWND m_hWnd;
public:
	Window(const TCHAR title[], int width, int height);
	~Window();
	void Show(int nCmdShow);
	HWND GetHandle();
	LRESULT CALLBACK HandleMsg(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnCreate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT OnClose(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
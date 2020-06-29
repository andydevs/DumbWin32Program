#pragma once
#include "Window.h"
#include "TextCyclerFactory.h"

class UIWindow : public Window
{
private:
	HWND m_hButton;
	TextCycler* m_textCycler;
public:
	UIWindow(TextCyclerFactory& factory, const TCHAR title[], int width, int height);
	~UIWindow();
	LRESULT OnCreate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


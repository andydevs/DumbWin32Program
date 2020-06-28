#pragma once
#include "TextCycler.h"
#include <Windows.h>
#include <tchar.h>

void RegisterWindowClass(HINSTANCE hInstance, const TCHAR className[]);

LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);
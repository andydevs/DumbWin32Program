#pragma once
#include "TextCycler.h"
#include <Windows.h>
#include <tchar.h>

const TCHAR WINDOW_CLASS[] = _T("DesktopApp");

void RegisterWindowClass();

void UnregisterWindowClass();
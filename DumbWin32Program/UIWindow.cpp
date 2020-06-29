#include "UIWindow.h"
#include <Windows.h>

#define ID_CHANGETEXT 0x01

UIWindow::UIWindow(TextCyclerFactory& factory, const TCHAR title[], int width, int height)
{
    Init(title, width, height);
    m_hButton = nullptr;
	m_textCycler = factory.createTextCycler();
}

UIWindow::~UIWindow()
{
	delete m_textCycler;
	DestroyWindow(m_hButton);
}

LRESULT UIWindow::OnCreate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    m_hButton = CreateWindow(
        _T("BUTTON"),                             // Predefined class; Unicode assumed 
        _T("Change Text"),                        // Button text 
        WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Styles 
        360,                                      // x position 
        50,                                       // y position 
        100,                                      // Button width
        25,                                       // Button height
        hWnd,                                     // Parent window
        (HMENU)ID_CHANGETEXT,                     // Menu Command
        GetModuleHandle(NULL),                    // Module handle
        NULL);                                    // Pointer not needed.
	return 0;
}

LRESULT UIWindow::OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(m_hWnd, &ps);
    TextOut(hdc, 20, 10,
        m_textCycler->current_text(), 
        _tcslen(m_textCycler->current_text()));
    EndPaint(m_hWnd, &ps);
    return 0;
}

LRESULT UIWindow::OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (wParam)
    {
    case ID_CHANGETEXT:
        m_textCycler->next_text();
        InvalidateRect(m_hWnd, 0, TRUE);
        break;
    default:
        break;
    }
    return 0;
}
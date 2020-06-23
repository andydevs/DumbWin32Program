#include <Windows.h>
#include <tchar.h>
#include <iostream>

// Change text command ID
#define ID_CHANGETEXT 1

// String buffers for window class name and window title
const TCHAR szWindowClass[] = _T("DesktopApp");
const TCHAR szTitle[] = _T("Dumb Win32 Program");

// String buffers for text
#define NTEXTS 5
const TCHAR* texts[NTEXTS] = {
	L"I'm Yute Uncle Barry!",
	L"NAAAAAaaaAAAAAH",
	L"GET IN THE CAAAAH MORTYY",
	L"They're Bureaucrats Morty, I don't Respect  them",
	L"Oh don't worry you little morty head morty"
};
// Current text to display
int currText = 0;

// Window stuff
HWND hButton;

LRESULT CALLBACK WndProc(
	_In_ HWND hWnd,
	_In_ UINT message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	// Paint stuff
	PAINTSTRUCT ps;
	HDC hdc;

	// Handle incoming messages
	switch (message)
	{
	case WM_CREATE:
		hButton = CreateWindow(
			_T("BUTTON"),
			_T("Change Text"),
			WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			350, 30, 100, 25,
			hWnd,
			(HMENU)ID_CHANGETEXT,
			GetModuleHandle(NULL),
			NULL
		);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc, 5, 5, texts[currText], _tcslen(texts[currText]));
		EndPaint(hWnd, &ps);
		return 0;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_CHANGETEXT:
			currText = (currText + 1) % NTEXTS;
			InvalidateRect(hWnd, 0, TRUE);
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	// Create window class
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szWindowClass;

	// Register window class (exit if it doesn't work)
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Dumb Win32 Program"),
			NULL);
		return 1;
	}

	// Create that window!
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, // Position
		500, 100, // Size
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Dumb Win32 Program"),
			NULL);
		return 1;
	}

	// Show that window!
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// Message Loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Return final message status?
	return (int)msg.wParam;
}
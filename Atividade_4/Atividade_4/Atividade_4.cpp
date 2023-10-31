#include <windows.h>

#define WM_MY_CUSTOM_MESSAGE (WM_USER + 1)

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND editBox;
HWND button;

enum ComponentID {
	MainWindow = 0,
	TextBox = 1,
	Button = 2
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	const wchar_t CLASS_NAME[] = L"The fourth Exercise!";

	WNDCLASS wc = { };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindow(
		CLASS_NAME,
		L"Exercise 4 - Making a window with Win32",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		500,
		500,
		NULL,
		(HMENU)ComponentID::MainWindow,
		hInstance,
		NULL
	);

	if (hwnd == NULL)
		return 0;

	ShowWindow(hwnd, nCmdShow);

	MSG message = { };

	while (GetMessage(&message, NULL, 0, 0) > 0) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_COMMAND:
			if (LOWORD(wParam) == ComponentID::Button){
				TCHAR buffer[100];
				GetWindowText(editBox, buffer, 100);
				MessageBox(hwnd, buffer, L"Message Box called from Command", MB_OK | MB_ICONINFORMATION);
				PostMessage(hwnd, WM_MY_CUSTOM_MESSAGE, ComponentID::Button, ComponentID::Button);
				break;
			}
		case WM_MY_CUSTOM_MESSAGE:
			if (LOWORD(wParam) == ComponentID::Button) {
				MessageBox(hwnd, L"Congratulations, you made a custom event message!", L"Custom message", MB_OK | MB_ICONINFORMATION);
				break;
			}
		case WM_CREATE:
			if (LOWORD(wParam) == ComponentID::MainWindow) {
				editBox = CreateWindow(TEXT("Edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_LEFT, 50, 100, 400, 18, hwnd, (HMENU)ComponentID::TextBox, NULL, NULL);
				button = CreateWindow(L"BUTTON", L"Get Text", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 170, 130, 140, 20, hwnd, (HMENU)ComponentID::Button, NULL, NULL);
				auto textBlock = CreateWindow(L"STATIC", L"Type something here", WS_VISIBLE | WS_CHILD | SS_LEFT, 50, 80, 400, 18, hwnd, (HMENU)3, NULL, NULL);

				MessageBox(hwnd, L"Initializing app", L"Exercise 4", MB_OK | MB_ICONINFORMATION);

				break;
			}
		case WM_DESTROY:
			if (LOWORD(wParam) == ComponentID::MainWindow) {
				MessageBox(hwnd, L"Closing App", L"Exercise 4", MB_OK | MB_ICONINFORMATION);
				PostQuitMessage(0);
				return 0;
			}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
#include<Windows.h>
#include<windowsx.h>
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HPEN hRedPen, hGreenPen, hBluePen, hOrangePen;
HBRUSH hRedBrush, hGreenBrush, hBlueBrush, hGoldBrush;
POINT pt[6] = { {550,40},{575,140},{500,75}, {600,75}, {525,140}, {550,40} };
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hMainWnd;
	TCHAR szClassName[] = _T("MyClass");
	MSG msg;
	WNDCLASSEX wc;
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 142, 126));
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassExW(&wc)) {
		MessageBoxW(NULL, _T("Cannot registr class"), _T("Error"), MB_OK);
		return 0;
	}
	hMainWnd = CreateWindow(szClassName, _T("A Hello1 Application"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
		hInstance, NULL);

	if (!hMainWnd) {
		MessageBox(NULL, _T("Cannot create main window"), _T("Error"), MB_OK);
		return 0;
	}
	ShowWindow(hMainWnd, nCmdShow);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	switch (uMsg) {
	case WM_CREATE:
		hRedBrush = CreateSolidBrush(RGB(240, 128, 128));
		hBlueBrush = CreateSolidBrush(RGB(70, 130, 180));
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SelectBrush(hdc, hRedBrush);
		Ellipse(hdc, 100, 40, 300, 240);
		SelectBrush(hdc, hBlueBrush);
		Pie(hdc, 100, 40, 300, 240, 200, 40, 300, 140);
		break;
	case WM_DESTROY:
		DeleteObject(hRedBrush);
		DeleteObject(hBlueBrush);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;

}
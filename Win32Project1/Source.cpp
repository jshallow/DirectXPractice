// practice dx to make a game
// current page: http://www.directxtutorial.com/Lesson.aspx?lessonid=9-4-1

// includes
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>

// globals
LPDIRECT3D9			d3d;						// pointer to our Direct3D Interface
LPDIRECT3DDEVICE9 d3ddev;						// pointer to the device class

// prototypes
LRESULT CALLBACK WindowProc(HWND hWnd, 
	UINT message, 
	WPARAM wParam, 
	LPARAM lParam);

// Windows Program Main
int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// use messagebox
	//MessageBox(NULL, L"Body Text", L"Header", MB_ICONEXCLAMATION | MB_OK);

	HWND hWnd;									// handle to window
	WNDCLASSEX wc;								// holds info for window class in a struct
	ZeroMemory(&wc, sizeof(WNDCLASSEX));		// clear out any data in this window class
	// set up window class struct
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass1";
	RegisterClassEx(&wc);						// register the window class using the struct we set up

	// create window and save it as the handle
	hWnd = 	CreateWindowEx(NULL, L"WindowClassName", L"Title of Window", 
		WS_OVERLAPPEDWINDOW, 300, 300, 500, 400, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);					// display window

	// hold event messages
	MSG msg;

	// main loop
	while (TRUE) {
		// do messages in the queue
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);			// translate keystrokes to right format
			DispatchMessage(&msg);			// send message to WindowProc
		}
		// if message is WM_QUIT, break
		if (msg.message == WM_QUIT)
			break;

		// game code
	}

	// return message to WM_QUIT
	return msg.wParam;
}

// main message handler
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_DESTROY:				// if message was to quit
		{
			PostQuitMessage(0);
			return 0;
		} break;

	}
	// else
	return DefWindowProc(hWnd, message, wParam, lParam);
}
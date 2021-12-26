#include <Windows.h>

#define APP_NAME L"MWGA"
#define TESTDEF 101

HINSTANCE hinst;
HWND clickinerval, textbox1, hour, textbox2, minute, textbox3, textbox4, second, milisecond, holdduration, testbutton;

void OnCreate(HWND hwnd)
{
    clickinerval = CreateWindow(L"Button", L"Click inerval", BS_GROUPBOX | WS_VISIBLE | WS_CHILD, 10, 10, 416, 55, hwnd, NULL, hinst, NULL);
    textbox1 = CreateWindow(L"Edit", L"", ES_NUMBER | WS_CHILD | WS_VISIBLE | WS_BORDER, 20, 31, 42, 22, hwnd, NULL, hinst, NULL);
    hour = CreateWindow(L"Static", L"Hour", WS_CHILD | WS_VISIBLE, 67, 33, 27, 22, hwnd, NULL, hinst, NULL);
    textbox2 = CreateWindow(L"Edit", L"", ES_NUMBER | WS_CHILD | WS_VISIBLE | WS_BORDER, 99, 31, 42, 22, hwnd, NULL, hinst, NULL);
    minute = CreateWindow(L"Static", L"Minutes", WS_CHILD | WS_VISIBLE, 146, 33, 47, 22, hwnd, NULL, hinst, NULL);
    textbox3 = CreateWindow(L"Edit", L"", ES_NUMBER | WS_CHILD | WS_VISIBLE | WS_BORDER, 198, 31, 42, 22, hwnd, NULL, hinst, NULL);
    second = CreateWindow(L"Static", L"Seconds", WS_CHILD | WS_VISIBLE, 245, 33, 50, 22, hwnd, NULL, hinst, NULL);
    textbox4 = CreateWindow(L"Edit", L"", ES_NUMBER | WS_CHILD | WS_VISIBLE | WS_BORDER, 300, 31, 42, 22, hwnd, NULL, hinst, NULL);
    milisecond = CreateWindow(L"Static", L"Miliseconds", WS_CHILD | WS_VISIBLE, 347, 33, 74, 22, hwnd, NULL, hinst, NULL);
    holdduration = CreateWindow(L"Button", L"Hold duration", WS_CHILD | WS_VISIBLE | BS_GROUPBOX, 10, 65, 416, 55, hwnd, NULL, hinst, NULL);
    testbutton = CreateWindow(L"Button", L"Click me", WS_CHILD | WS_VISIBLE, 10, 100, 50, 50, hwnd, (HMENU)TESTDEF, hinst, NULL);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch(msg) {
        default:
            return DefWindowProc(hwnd, msg, wparam, lparam);
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_CREATE:
            OnCreate(hwnd);
            return 0;
    }
}

INT APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    hinst = hInstance;

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = APP_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
            APP_NAME,
            APP_NAME,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            CW_USEDEFAULT, CW_USEDEFAULT,
            NULL,
            NULL,
            hInstance,
            NULL);
    if(!hwnd)
        return -1;
    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}




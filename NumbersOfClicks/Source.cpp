#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Framework Application");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;
    WNDCLASSEX wcl;
    wcl.cbSize = sizeof(wcl);
    wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcl.lpfnWndProc = WindowProc;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hInstance = hInst;
    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcl.hCursor = LoadCursor(NULL, IDC_HAND);
    wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcl.lpszMenuName = NULL;
    wcl.lpszClassName = szClassWindow;
    wcl.hIconSm = NULL;
    if (!RegisterClassEx(&wcl))
        return 0;
    hWnd = CreateWindowEx(
        0,
        szClassWindow,
        TEXT("Framework Application Windows"),
        WS_OVERLAPPEDWINDOW,
        200,
        200,
        500,
        500,
        NULL,
        NULL,
        hInst,
        NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&lpMsg, NULL, 0, 0))
    {
        TranslateMessage(&lpMsg);
        DispatchMessage(&lpMsg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    switch (uMessage)
    {
    case WM_LBUTTONDOWN:
        MessageBox(0, TEXT("Left mouse button pressed"), TEXT("WM_LBUTTON"), MB_OK | MB_ICONINFORMATION);
        break;
    case WM_RBUTTONDOWN:
        MessageBox(0, TEXT("Right mouse button pressed"), TEXT("WM_RBUTTON"), MB_OK | MB_ICONINFORMATION);
        break;
    case WM_MBUTTONDOWN:
        MessageBox(0, TEXT("Middle mouse button pressed"), TEXT("WM_MBUTTON"), MB_OK | MB_ICONINFORMATION);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, uMessage, wParam, lParam);
    }
    return 0;
}
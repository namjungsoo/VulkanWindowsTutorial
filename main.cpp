#include "stdafx.h"

extern VkInstance instance;
extern HWND hWnd;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 1. enum instance layers

    // 2. create instance
    createInstance();
    setupDebugMessenger();

    // 2. create surface
    createSurface(hInstance, hWnd);

    // 4. create device
    createDevice();

    // 5. create logical device
    createLogicalDevice();

    // 6. create swap chain
    createSwapChain();

    MSG msg = {};

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, nullptr, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    // 99. clean up
    cleanup();

    return (int)msg.wParam;
}
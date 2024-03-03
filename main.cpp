#include "stdafx.h"

extern VkInstance instance;

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

    // 3. create device
    createDevice();

    // 4. create logical device
    createLogicalDevice();

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
    vkDestroyInstance(instance, nullptr);

    return (int)msg.wParam;
}
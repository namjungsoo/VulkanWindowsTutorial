#include "stdafx.h"

extern VkInstance instance;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    // 1. enum instance layers

    // 2. create instance
    createInstance();

    // 3. create device
    createDevice();

    // 4. create logical device
    createLogicalDevice();

    // 99. clean up
    vkDestroyInstance(instance, nullptr);
	return 0;
}
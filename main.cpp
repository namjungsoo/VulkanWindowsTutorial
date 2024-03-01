// before vulkan.h
#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    VkInstanceCreateInfo info = {};
    info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

    VkInstance inst;
    VkResult res;

    res = vkCreateInstance(&info, NULL, &inst);
    if (res == VK_ERROR_INCOMPATIBLE_DRIVER) {
        fprintf(stderr, "cannot find a compatible Vulkan ICD\n");
        exit(-1);
    }
    else if (res) {
        fprintf(stderr, "unknown error\n");
        exit(-1);
    }
    // else -> success
    printf("Hello Vulkan\n");

    vkDestroyInstance(inst, NULL);
	return 0;
}
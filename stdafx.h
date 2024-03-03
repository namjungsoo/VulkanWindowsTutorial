// before vulkan.h
#define VK_USE_PLATFORM_WIN32_KHR
// for std::numeric_limits<uint32_t>::max()
#define NOMINMAX 
#include <vulkan/vulkan.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <optional>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;

void createInstance();
void createSurface(HINSTANCE hInstance, HWND hWnd);
void createDevice();
void createLogicalDevice();
void createSwapChain();

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

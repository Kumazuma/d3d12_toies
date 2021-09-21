#pragma once
#include <windows.h>
#include <stdint.h>
#include <inttypes.h>

class RenderManager;
class PhysicalDeviceManager;
class RenderTarget;

typedef struct _PhysicalDeviceDesc
{
    uintptr_t handle;
    const char* name;
} PhysicalDeviceDesc;

class PhysicalDeviceManager
{
public:
    static PhysicalDeviceManager* Create();
    virtual void Destroy() = 0;
    virtual int GetPhysicalDevices(PhysicalDeviceDesc* arr, size_t* length) = 0;
    virtual int CreateRenderManager(PhysicalDeviceDesc* desc, RenderManager** renderManager) = 0;
};

class RenderManager
{
public:
    virtual void Destroy() = 0;
    virtual int CreateRenderTarget(HWND hWnd, RenderTarget* renderTarget) = 0;
};


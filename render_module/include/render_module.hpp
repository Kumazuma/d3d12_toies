#pragma once
#include <windows.h>
#include <stdint.h>
#include <inttypes.h>
#include <memory>
class RenderManager;
class PhysicalDeviceManager;
class RenderTarget;

#ifdef _WIN64
using Char = wchar_t; 
#else
using Char = char;
#endif

#if defined(_WIN64) && defined(RENDER_MODULE_EXPORT)
#define RENDER_EXPORT __declspec(dllexport)
#else
#define RENDER_EXPORT __declspec(dllimport)
#endif

typedef struct _PhysicalDeviceDesc
{
    uintptr_t handle;
    Char name[128];
} PhysicalDeviceDesc;

class PhysicalDeviceManager
{
    inline static void Delete(PhysicalDeviceManager*);
public:
    using SharedPtr = std::shared_ptr<PhysicalDeviceManager>;
    inline static SharedPtr MakeShared();
    static RENDER_EXPORT PhysicalDeviceManager* Create();
    virtual void Destroy() = 0;
    virtual int GetPhysicalDevices(PhysicalDeviceDesc* arr, size_t length) = 0;
    virtual size_t GetPhysicalDeviceCount() const = 0;
    virtual int CreateRenderManager(PhysicalDeviceDesc* desc, RenderManager** renderManager) = 0;
};

inline auto PhysicalDeviceManager::MakeShared() -> SharedPtr
{
    return SharedPtr(Create(), &Delete);
}

inline void PhysicalDeviceManager::Delete(PhysicalDeviceManager* self)
{
    self->Destroy();
}

class RenderManager
{
public:
    virtual void Destroy() = 0;
    virtual int CreateRenderTarget(HWND hWnd, RenderTarget* renderTarget) = 0;
};


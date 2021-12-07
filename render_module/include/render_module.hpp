#pragma once
#include <windows.h>
#include <stdint.h>
#include <inttypes.h>
#include <memory>
class RenderManager;
class PhysicalDeviceManager;
class RenderTarget;
class ResourceManager;
class PhysicalDevice;
class Monitor;
class Mesh;

#if defined(_WIN64) && defined(RENDER_MODULE_EXPORT)
#define RENDER_EXPORT __declspec(dllexport)
#else
#define RENDER_EXPORT __declspec(dllimport)
#endif

class PhysicalDeviceManager
{
    inline static void Delete(PhysicalDeviceManager*);
public:
    using SharedPtr = std::shared_ptr<PhysicalDeviceManager>;
    inline static SharedPtr MakeShared();
    static RENDER_EXPORT PhysicalDeviceManager* Create();
    virtual void Destroy() = 0;
    virtual bool GetPhysicalDevice(size_t index, PhysicalDevice** out) = 0;
    virtual int CreateRenderManager(const PhysicalDevice* desc, RenderManager** renderManager) = 0;
};

inline auto PhysicalDeviceManager::MakeShared() -> SharedPtr
{
    return SharedPtr(Create(), &Delete);
}

inline void PhysicalDeviceManager::Delete(PhysicalDeviceManager* self)
{
    self->Destroy();
}

class PhysicalDevice
{
public:
    virtual const char* GetName() const = 0;
    virtual bool GetMonitor(size_t index, Monitor** out) const = 0;
    virtual uintptr_t GetHandle() const = 0;
};

class Monitor
{
public:
    virtual bool GetSupportResolution(size_t index, uint32_t* width, uint32_t* height) const = 0;
    virtual const char* GetName() const = 0;
    virtual uintptr_t GetHandle() const = 0;
};

class RenderManager
{
public:
    virtual void Destroy() = 0;
    virtual int CreateRenderTarget(HWND hWnd, RenderTarget** renderTarget) = 0;
};

class ResourceManager
{
public:
    virtual int LoadMeshFromFile(const char* filepath) = 0;
};
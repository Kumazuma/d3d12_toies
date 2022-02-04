#pragma once
#include "render_module.hpp"

#include<d3d12.h>
#include<dxgi1_5.h>
#include<wrl.h>
#include<vector>
#include<unordered_map>
#include<string>

using namespace Microsoft::WRL;

class MonitorDXGI;
struct PhysicalDeviceDescDXGI: public PhysicalDevice
{
public:
    virtual const char* GetName() const override;
    virtual bool GetMonitor(size_t index, Monitor const** out) const override;
    virtual uintptr_t GetHandle() const override;

    uintptr_t handle;
    char name[128];
    std::vector<MonitorDXGI> monitors;
};

class MonitorDXGI: public Monitor {
public:
    virtual bool GetSupportResolution(size_t index, uint32_t* width, uint32_t* height) const;
    virtual const char* GetName() const;
    virtual uintptr_t GetHandle() const;
    ComPtr<IDXGIOutput> monitor_;
    char name[128];
};

class PhysicalDeviceManagerD3D12 : public PhysicalDeviceManager {
public:
    PhysicalDeviceManagerD3D12();
    virtual void Destroy() override;
    virtual bool GetPhysicalDevice(size_t index, PhysicalDevice** out) override;
    virtual int CreateRenderManager(const PhysicalDevice* desc, RenderManager** renderManager) override;
private:
    ComPtr<IDXGIFactory5> swapChain_;
    std::unordered_map<uintptr_t, ComPtr<IDXGIAdapter1>> adapters_;
    std::vector<PhysicalDeviceDescDXGI> adapterNames_;
};

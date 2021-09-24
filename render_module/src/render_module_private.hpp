#pragma once
#include "render_module.hpp"

#include<d3d12.h>
#include<dxgi1_5.h>
#include<wrl.h>
#include<vector>
#include<unordered_map>
#include<string>

using namespace Microsoft::WRL;

class PhysicalDeviceManagerD3D12 : public PhysicalDeviceManager 
{
public:
    PhysicalDeviceManagerD3D12();
    virtual void Destroy() override;
    virtual int GetPhysicalDevices(PhysicalDeviceDesc* arr, size_t length) override;
    virtual size_t GetPhysicalDeviceCount() const override;
    virtual int CreateRenderManager(PhysicalDeviceDesc* desc, RenderManager** renderManager) override;
private:
    ComPtr<IDXGIFactory5> swapChain_;
    std::unordered_map<uintptr_t, ComPtr<IDXGIAdapter1>> adapters_;
    std::vector<PhysicalDeviceDesc> adapterNames_;
};

#include "render_module_private.hpp"
#include "render_manager.hpp"
#undef min
#undef max
PhysicalDeviceManager* PhysicalDeviceManager::Create()
{
    return new PhysicalDeviceManagerD3D12();
}

PhysicalDeviceManagerD3D12::PhysicalDeviceManagerD3D12()
{
    HRESULT hr;
    ComPtr<IDXGIFactory3> swapChain;
    CreateDXGIFactory2(0, __uuidof(IDXGIFactory3), &swapChain);
    swapChain.As(&swapChain_);

    ComPtr<IDXGIAdapter1> adapter;

    for(UINT i = 0; SUCCEEDED(swapChain_->EnumAdapters1(i, &adapter)) ; ++i)
    {
        DXGI_ADAPTER_DESC1 desc{};
        adapter->GetDesc1(&desc);
        if(desc.Flags == 0)
        {
            PhysicalDeviceDescDXGI deviceDesc{};
            deviceDesc.handle = reinterpret_cast<uintptr_t>(adapter.Get());
            ComPtr<IDXGIOutput> dxgiOutput;
            for(UINT j = 0; SUCCEEDED(adapter->EnumOutputs(j, &dxgiOutput)); ++j)
            {
                MonitorDXGI monitor;
                monitor.monitor_ = dxgiOutput;
                DXGI_OUTPUT_DESC outputDesc{};
                dxgiOutput->GetDesc(&outputDesc);
                WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, outputDesc.DeviceName, -1, monitor.name, 128, nullptr, nullptr);
                deviceDesc.monitors.push_back(monitor);
            }
            WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, desc.Description, -1, deviceDesc.name, 128, nullptr, nullptr);
            adapterNames_.push_back(std::move(deviceDesc));

            adapters_.emplace(deviceDesc.handle, std::move(adapter));
        }
    }
}

void PhysicalDeviceManagerD3D12::Destroy()
{
    delete this;
}

bool PhysicalDeviceManagerD3D12::GetPhysicalDevice(size_t index, PhysicalDevice** out)
{
    if(index >= adapterNames_.size() )
        return false;

    *out = &adapterNames_[index];
    return true;
}

int PhysicalDeviceManagerD3D12::CreateRenderManager(const PhysicalDevice* desc, RenderManager** renderManager)
{
    if(auto it = adapters_.find(desc->GetHandle()); it == adapters_.end())
    {
        return -1;
    }

    auto adaptor{reinterpret_cast<IDXGIAdapter1*>(desc->GetHandle())};
    auto manager{new RenderManagerD3D12{adaptor}};
    *renderManager = manager;
    return 0;
}

const char* PhysicalDeviceDescDXGI::GetName() const
{
    return name;
}

bool PhysicalDeviceDescDXGI::GetMonitor(size_t index, Monitor const** out) const
{
    if(index >= monitors.size())
        return false;

    *out = &monitors[index];
    return true;
}

uintptr_t PhysicalDeviceDescDXGI::GetHandle() const
{
    return handle;
}

 bool MonitorDXGI::GetSupportResolution(size_t index, uint32_t* width, uint32_t* height) const
 {
    return false;
 }

 const char* MonitorDXGI::GetName() const
 {
    return name;
 }

 uintptr_t MonitorDXGI::GetHandle() const
 {
    return reinterpret_cast<uintptr_t>(monitor_.Get());
 }

#include "render_module_private.hpp"
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
    CreateDXGIFactory2(0, __uuidof(swapChain), &swapChain);
    swapChain.As(&swapChain_);

    ComPtr<IDXGIAdapter1> adapter;

    for(UINT i = 0; SUCCEEDED(swapChain_->EnumAdapters1(i, &adapter)) ; ++i)
    {
        DXGI_ADAPTER_DESC1 desc{};
        adapter->GetDesc1(&desc);
        if(desc.Flags == 0)
        {
            PhysicalDeviceDesc deviceDesc{};
            deviceDesc.handle = reinterpret_cast<uintptr_t>(adapter.Get());
            memcpy(deviceDesc.name, desc.Description, sizeof(wchar_t) * 128);
            adapterNames_.push_back(deviceDesc);
            adapters_.emplace(deviceDesc.handle, std::move(adapter));
        }
    }
}

void PhysicalDeviceManagerD3D12::Destroy()
{
    delete this;
}

int PhysicalDeviceManagerD3D12::GetPhysicalDevices(PhysicalDeviceDesc* arr, size_t length)
{
    if(length == 0)
        return -1;

    if(adapterNames_.size() == 0)
        return 0;

    size_t copyCount = std::min(length, adapterNames_.size());
    memcpy(arr, adapterNames_.data(), sizeof(PhysicalDeviceDesc) * copyCount);
    return 0;
}

size_t PhysicalDeviceManagerD3D12::GetPhysicalDeviceCount() const
{
    return this->adapterNames_.size();
}

int PhysicalDeviceManagerD3D12::CreateRenderManager(PhysicalDeviceDesc* desc, RenderManager** renderManager)
{
    return 0;
}

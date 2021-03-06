//
// Created by STK on 2022-01-09.
//

#include "Manager.h"
namespace Kuma::Render {
	ReturnCode ManagerD3D12::GetPhysicalDeviceCount(size_t* out_count) {
		if(out_count == nullptr)
			return -1;

		*out_count = adapterNames_.size();
		return 0;
	}

	ReturnCode ManagerD3D12::GetPhysicalDevice(size_t i, PhysicalDevice **out_device) {
		if(out_device == nullptr || i >= adapterNames_.size())
			return -1;

		*out_device = &adapterNames_[i];
		return 0;
	}

	ReturnCode ManagerD3D12::CreateRenderer(PhysicalDevice *device, Renderer **out_renderer) {
		//*out_renderer = new
		return 0;
	}

	void ManagerD3D12::Destroy() {
		delete this;
	}

	ManagerD3D12::ManagerD3D12() {
		HRESULT hr;
		ComPtr<IDXGIFactory3> swapChain;
		CreateDXGIFactory2(0, __uuidof(IDXGIFactory3), &swapChain);
		swapChain.As(&swapChain_);

		ComPtr<IDXGIAdapter1> adapter;

		for(UINT i = 0; SUCCEEDED(swapChain_->EnumAdapters1(i, &adapter)) ; ++i) {
			DXGI_ADAPTER_DESC1 desc{};
			adapter->GetDesc1(&desc);
			if(desc.Flags == 0) {
				uintptr_t handle{reinterpret_cast<uintptr_t>(adapter.Get())};
				PhysicalDeviceD3D12 device{adapter};
				adapters_.emplace(handle, std::move(adapter));
				adapterNames_.emplace_back(std::move(device));
			}
		}
	}
}

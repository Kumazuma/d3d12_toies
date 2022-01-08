//
// Created by STK on 2022-01-09.
//

#include "PhysicalDevice.h"

namespace Kuma::Render {
	const char *PhysicalDeviceD3D12::GetName() const {
		return name;
	}

	ReturnCode PhysicalDeviceD3D12::GetOutputCount(size_t *out_count) {
		if(out_count == nullptr)
			return -1;

		*out_count = outputs_.size();
		return 0;
	}

	ReturnCode PhysicalDeviceD3D12::GetOutput(size_t index, Output **out_output) {
		if(index >= outputs_.size())
			return -1;

		*out_output = &outputs_[index];
		return 0;
	}

	uintptr_t PhysicalDeviceD3D12::GetHandle() const {
		return reinterpret_cast<uintptr_t>(adapter_.Get());
	}

	PhysicalDeviceD3D12::PhysicalDeviceD3D12(ComPtr<IDXGIAdapter1> adapter):
		adapter_{adapter}{
		DXGI_ADAPTER_DESC1 desc{};
		adapter->GetDesc1(&desc);
		WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, desc.Description, -1, name, 256, nullptr, nullptr);

		ComPtr<IDXGIOutput> dxgiOutput;
		for(UINT j = 0; SUCCEEDED(adapter->EnumOutputs(j, &dxgiOutput)); ++j) {
			outputs_.push_back(OutputD3D12{dxgiOutput});
		}
	}
}

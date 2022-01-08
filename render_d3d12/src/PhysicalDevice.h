//
// Created by STK on 2022-01-09.
//

#ifndef D3D12_TOIES_PHYSICALDEVICE_H
#define D3D12_TOIES_PHYSICALDEVICE_H
#include <dxgi1_5.h>
#include <vector>
#include "Output.h"
#include "render_d3d12.h"

namespace Kuma::Render {
	class PhysicalDeviceD3D12: public PhysicalDevice {
	public:
		explicit PhysicalDeviceD3D12(ComPtr<IDXGIAdapter1> adapter);
		const char* GetName() const override;
		ReturnCode GetOutputCount(size_t* out_count) override;
		ReturnCode GetOutput(size_t index, Output** out_output) override;
		uintptr_t GetHandle() const override;

		char name[256];
		ComPtr<IDXGIAdapter1> adapter_;
		std::vector<OutputD3D12> outputs_;
	};
}

#endif //D3D12_TOIES_PHYSICALDEVICE_H

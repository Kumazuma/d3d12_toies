//
// Created by STK on 2022-01-09.
//

#ifndef D3D12_TOIES_MANAGER_H
#define D3D12_TOIES_MANAGER_H
#include <render_module.hpp>
#include <vector>
#include <dxgi1_5.h>
#include <wrl.h>
#include <unordered_map>

#include "render_d3d12.h"
#include "PhysicalDevice.h"

namespace Kuma::Render {
	class ManagerD3D12: public Kuma::Render::Manager {
	public:
		ManagerD3D12();
		void Destroy() override;
		ReturnCode GetPhysicalDeviceCount(size_t* out_count) override;
		ReturnCode GetPhysicalDevice(size_t i, PhysicalDevice** out_device) override;
		ReturnCode CreateRenderer(PhysicalDevice* device, Renderer** out_renderer) override;
	private:
		ComPtr<IDXGIFactory5> factory_;
		std::unordered_map<uintptr_t, ComPtr<IDXGIAdapter1>> adapters_;
		std::vector<PhysicalDeviceD3D12> adapterNames_;
	};
}

#endif //D3D12_TOIES_MANAGER_H

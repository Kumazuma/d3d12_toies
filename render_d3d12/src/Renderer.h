//
// Created by STK on 2022-01-09.
//

#ifndef D3D12_TOIES_RENDERER_H
#define D3D12_TOIES_RENDERER_H

#include <d3d12.h>

#include "render_d3d12.h"
#include "PhysicalDevice.h"


namespace Kuma::Render {
	class RendererD3D12: public Renderer {
	public:
		explicit RendererD3D12(PhysicalDeviceD3D12* physicalDevice);
		~RendererD3D12();
		void Destroy() override;
		PhysicalDevice* GetPhysicalDevice() override;
		ReturnCode CreateSwapChain(HWND hWnd, SwapChain** out_swapChain) override;
		ReturnCode Render(Camera* mainCamera) override;
		static DWORD __stdcall  RenderThread(void* param);

	private:
		bool running_;
		Camera* currentCamera_;
		HANDLE threadHandle_;
		PhysicalDeviceD3D12* physicalDevice_;
		ComPtr<ID3D12Device> device;
		ComPtr<ID3D12CommandQueue> queue;
	};
}

#endif //D3D12_TOIES_RENDERER_H

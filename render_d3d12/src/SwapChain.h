//
// Created by STK on 2022-01-10.
//

#ifndef D3D12_TOIES_SWAPCHAIN_H
#define D3D12_TOIES_SWAPCHAIN_H

#include "render_d3d12.h"
#include <dxgi1_5.h>
#include <d3d12.h>

namespace Kuma::Render {
	class SwapChainD3D12: public SwapChain {
	public:
		static constexpr uint32_t BACK_BUFFER_COUNT = 2;
	public:
		SwapChainD3D12(ComPtr <IDXGIFactory5> factory_, ComPtr <ID3D12Device> device_, HWND hWindow_, uint32_t width_, uint32_t height_);
		ComPtr<IDXGISwapChain3> GetDxgiObject();
	private:
		ComPtr<IDXGISwapChain3> swapChain_;
		ComPtr<ID3D12Resource> backBuffer_[BACK_BUFFER_COUNT];
	};
}

#endif //D3D12_TOIES_SWAPCHAIN_H

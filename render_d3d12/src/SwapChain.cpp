//
// Created by STK on 2022-01-10.
//

#include "SwapChain.h"

namespace Kuma::Render {
	SwapChainD3D12::SwapChainD3D12(
			ComPtr <IDXGIFactory5> factory_,
			ComPtr <ID3D12Device> device_,
			HWND hWindow_,
			uint32_t width_,
			uint32_t height_) {
		DXGI_SWAP_CHAIN_DESC1 swapChainDesc1{};
		swapChainDesc1.Width = width_;
		swapChainDesc1.Height = height_;
		swapChainDesc1.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapChainDesc1.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
		swapChainDesc1.Format = DXGI_FORMAT_R8G8B8A8_UINT;
		swapChainDesc1.Scaling = DXGI_SCALING_STRETCH;
		swapChainDesc1.BufferCount = BACK_BUFFER_COUNT;


	}

	ComPtr<IDXGISwapChain3> Kuma::Render::SwapChainD3D12::GetDxgiObject() {
		return swapChain_;
	}


}


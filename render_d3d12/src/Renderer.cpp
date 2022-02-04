//
// Created by STK on 2022-01-09.
//

#include "Renderer.h"
#include <windows.h>

namespace Kuma::Render {
	PhysicalDevice *RendererD3D12::GetPhysicalDevice() {
		return physicalDevice_;
	}

	RendererD3D12::~RendererD3D12() {
		running_ = false;
		if(threadHandle_ != nullptr) {
			WaitForSingleObject(threadHandle_, INFINITE);
		}
	}

	RendererD3D12::RendererD3D12(PhysicalDeviceD3D12 *physicalDevice) :
	physicalDevice_{physicalDevice},
	running_{false} {
		auto adapter{physicalDevice_->GetAdapter()};
		D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_1, __uuidof(decltype(device)::InterfaceType), &device);
		D3D12_COMMAND_QUEUE_DESC queueDesc{};
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		device->CreateCommandQueue(&queueDesc, __uuidof(decltype(queue)::InterfaceType), &queue);

		DWORD threadID{};
		running_ = true;
		threadHandle_ = CreateThread(nullptr, 0, &RendererD3D12::RenderThread, this, 0, &threadID);
	}

	void RendererD3D12::Destroy() {
		delete this;
	}

	ReturnCode RendererD3D12::CreateSwapChain(HWND hWnd, SwapChain **out_swapChain) {
		return 0;
	}

	ReturnCode RendererD3D12::Render(Camera *mainCamera) {
		return 0;
	}

	DWORD __stdcall RendererD3D12::RenderThread(void *param) {
		auto renderer = reinterpret_cast<RendererD3D12*>(param);
		// TODO: Rendering in here
		while(renderer->running_) {

		}

		return 0;
	}
}

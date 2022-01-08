#pragma once
#include <windows.h>
#include <stdint.h>
#include <inttypes.h>
#include <memory>
class Manager;
class PhysicalDeviceManager;
class RenderTarget;
class ResourceManager;
class PhysicalDevice;
class Monitor;
class Mesh;

#if defined(_WIN64) && defined(RENDER_MODULE_EXPORT)
#define RENDER_EXPORT __declspec(dllexport)
#else
#define RENDER_EXPORT __declspec(dllimport)
#endif

namespace Kuma::Render {
	using ReturnCode = int;
	template<typename T>
	using SharedPtr = std::shared_ptr<T>;
	struct PhysicalDevice;
	struct Output;
	struct Renderer;
	struct SwapChain;

	enum class API {
		None,
		D3D12
	};

	struct Object {
		virtual void Destroy() = 0;
	};

	struct Manager: public Object {
		static RENDER_EXPORT ReturnCode Create(API api, Manager** out_manager);

		virtual ReturnCode GetPhysicalDeviceCount(size_t* out_count) = 0;
		virtual ReturnCode GetPhysicalDevice(size_t i, PhysicalDevice** out_device) = 0;
		virtual ReturnCode CreateRenderer(PhysicalDevice* device, Renderer** out_renderer) = 0;

		static SharedPtr<Manager> Create(API api);
		SharedPtr<Renderer> CreateRenderer(PhysicalDevice* device);
	};

	struct PhysicalDevice {
		virtual const char* GetName() const = 0;
		virtual ReturnCode GetOutputCount(size_t* out_count) = 0;
		virtual ReturnCode GetOutput(size_t index, Output** out_output) = 0;
		virtual uintptr_t GetHandle() const = 0;
	};

	struct Renderer: public Object {
		virtual PhysicalDevice* GetPhysicalDevice() = 0;
		virtual ReturnCode CreateSwapChain(HWND hWnd, SwapChain** out_swapChain) = 0;

		SharedPtr<SwapChain> CreateSwapChain(HWND hWnd);
	};

	struct SwapChain: public Object {

	};

	struct Output {
		virtual const char* GetName() = 0;
	};

	inline SharedPtr<Manager> Manager::Create(API api) {
		Manager* manager{};
		Create(api, &manager);
		return SharedPtr<Manager>{manager, [](Manager* manager){manager->Destroy();}};
	}

	inline SharedPtr<Renderer> Manager::CreateRenderer(PhysicalDevice* device) {
		Renderer* renderer{};
		CreateRenderer(device, &renderer);
		return SharedPtr<Renderer>{renderer, [](Renderer* ptr){ptr->Destroy();}};
	}

	inline SharedPtr<SwapChain> Renderer::CreateSwapChain(HWND hWnd) {
		SwapChain* swapChain{};
		CreateSwapChain(hWnd, &swapChain);
		return SharedPtr<SwapChain>{swapChain, [](SwapChain* ptr){ptr->Destroy();}};
	}
}

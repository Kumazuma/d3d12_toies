//
// Created by STK on 2022-01-09.
//

#ifndef D3D12_TOIES_RENDER_D3D12_H
#define D3D12_TOIES_RENDER_D3D12_H

#include <wrl.h>
#include <render_module.hpp>

#if defined(_WIN64) && defined(RENDER_MODULE_D3D12_EXPORT)
#define RENDER_D3D12_EXPORT __declspec(dllexport)
#else
#define RENDER_D3D12_EXPORT __declspec(dllimport)
#endif

namespace Kuma::Render {
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
}


#endif //D3D12_TOIES_RENDER_D3D12_H

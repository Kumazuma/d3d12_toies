//
// Created by STK on 2022-01-09.
//

#include "Output.h"

namespace Kuma::Render {

	OutputD3D12::OutputD3D12(ComPtr<IDXGIOutput> monitor):
		monitor_{monitor}{
		DXGI_OUTPUT_DESC outputDesc{};
		monitor->GetDesc(&outputDesc);
		WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, outputDesc.DeviceName, -1, name, 128, nullptr, nullptr);
	}

	const char *OutputD3D12::GetName() {
		return name;
	}
}

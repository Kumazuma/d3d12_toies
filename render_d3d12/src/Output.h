//
// Created by STK on 2022-01-09.
//

#ifndef D3D12_TOIES_OUTPUT_H
#define D3D12_TOIES_OUTPUT_H

#include <dxgi1_5.h>
#include "render_d3d12.h"

namespace Kuma::Render {
	class OutputD3D12: public Output {
	public:
		explicit OutputD3D12(ComPtr<IDXGIOutput> monitor);
		const char* GetName() override;

		ComPtr<IDXGIOutput> monitor_;
		char name[128];
	};
}



#endif //D3D12_TOIES_OUTPUT_H

//
// Created by STK on 2022-01-09.
//

#include <render_module.hpp>
#include "Manager.h"

extern "C" int RENDER_D3D12_EXPORT CreateManager(Kuma::Render::Manager** out) {
	*out = new Kuma::Render::ManagerD3D12{};
	return 0;
}

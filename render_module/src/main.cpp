#include "render_module.hpp"



namespace Kuma::Render {
	API render_manager_pai{API::None};
	HMODULE hDLL{};
	ReturnCode Manager::Create(API api, Manager** out_manager) {
		if(render_manager_pai != API::None)
			return -1;

		switch(api) {
			case API::None:
				return -1;
			case API::D3D12:
				hDLL = LoadLibraryW(L"render_d3d12.dll");
				if(hDLL == nullptr) {
					return -1;
				} else {
					auto createFunc{((int(*)(Manager**))GetProcAddress(hDLL, "CreateManager"))};
					auto ret{createFunc(out_manager)};
					if(ret == 0) {
						render_manager_pai = api;
						return 0;
					}

					FreeLibrary(hDLL);
					hDLL = nullptr;
				}
				break;
			default:
				return -1;
		}

		return -1;
	}
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
	// Perform actions based on the reason for calling.
	if(Kuma::Render::hDLL == nullptr || fdwReason != DLL_PROCESS_DETACH)
		return TRUE;

	FreeLibrary(Kuma::Render::hDLL);
	return TRUE;
}

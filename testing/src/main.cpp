#include <iostream>
#include <vector>
#include "render_module.hpp"
int main()
{
    size_t devicesCount{};
	auto manager{Kuma::Render::Manager::Create(Kuma::Render::API::D3D12)};
	Kuma::Render::PhysicalDevice* device{};
    for(int i = 0 ; manager->GetPhysicalDevice(i, &device) == 0; ++i)
    {
        std::cout << device->GetName() << std::endl;
        std::cout << "Monitor" << std::endl;

        Kuma::Render::Output* monitor{};
        for(int j = 0; device->GetOutput(j, &monitor) == 0; ++j) {
            std::cout << "name: " << monitor->GetName() << std::endl;
        }
    }

	manager->GetPhysicalDevice(1, &device);
	auto renderer{manager->CreateRenderer(device)};


    return 0;
}

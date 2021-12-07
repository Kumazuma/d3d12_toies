#include <iostream>
#include <vector>
#include "render_module.hpp"
int main()
{
    size_t devicesCount{};
    auto tv = PhysicalDeviceManager::MakeShared();
    PhysicalDevice* device;
    for(int i = 0 ; tv->GetPhysicalDevice(i, &device); ++i)
    {
        std::cout << device->GetName() << std::endl;
    }

    RenderManager* renderManager;
    tv->CreateRenderManager(device, &renderManager);
    renderManager->Destroy();
    return 0;
}

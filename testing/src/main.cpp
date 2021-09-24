#include <stdio.h>
#include "render_module.hpp"
int main()
{
    size_t devicesCount{};
    auto tv = PhysicalDeviceManager::MakeShared();
    tv->GetPhysicalDevices(nullptr, &devicesCount);
}
#pragma once
#include "render_module_private.hpp"

class ResourceManagerD3D12 : public ResourceManager
{
public:
    virtual int LoadMeshFromFile(const char* filepath) override;
private:
    ComPtr<ID3D12Device> device;
    
};
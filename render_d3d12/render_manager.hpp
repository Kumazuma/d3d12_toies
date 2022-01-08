#pragma once
#include "render_module_private.hpp"
class RenderManagerD3D12: public RenderManager
{
public:
    RenderManagerD3D12(IDXGIAdapter* adapter);
    virtual void Destroy() override;
    virtual int CreateRenderTarget(HWND hWnd, RenderTarget** renderTarget) override;
private:
    ComPtr<ID3D12Device> device;
    ComPtr<ID3D12CommandQueue> queue;
};
 
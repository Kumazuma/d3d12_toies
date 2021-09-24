#pragma once
#include "render_module_private.hpp"
class RenderManagerD3D12: public RenderManager
{
public:
    virtual void Destroy() = 0;
    virtual int CreateRenderTarget(HWND hWnd, RenderTarget* renderTarget) override;
private:

};

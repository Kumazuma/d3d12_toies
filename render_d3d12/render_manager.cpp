#include "render_manager.hpp"

RenderManagerD3D12::RenderManagerD3D12(IDXGIAdapter* adapter)
{
    D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_1, __uuidof(decltype(device)::InterfaceType), &device);
    D3D12_COMMAND_QUEUE_DESC queueDesc{};
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    device->CreateCommandQueue(&queueDesc, __uuidof(decltype(queue)::InterfaceType), &queue);
}

void RenderManagerD3D12::Destroy()
{
    delete this;
}

int RenderManagerD3D12::CreateRenderTarget(HWND hWnd, RenderTarget** renderTarget)
{
    return -1;
}

#ifndef MIRAGE_TEXTURE_RENDERER_HPP
#define MIRAGE_TEXTURE_RENDERER_HPP
#include "vecmath.hpp"
#include "window.hpp"

namespace mirage
{

class TextureRenderer
{
public:
    
    TextureRenderer(WindowMode pWindowMode, unsigned pResX, unsigned pResY);
    ~TextureRenderer();
    void Update(Vector4<uint8_t>* pColorBuffer, unsigned pDimensionX, unsigned pDimensionY);
    void WriteToFile(Vector4<uint8_t>* pColorBuffer, unsigned pDimensionX, unsigned pDimensionY);
    void Render();

    bool ShouldWinodwClose() const { return mWindowShouldClose; }

private:
    
    struct RenderingObjects;
    RenderingObjects* mRenderingObjects;
    Window mWindow;
    bool mWindowShouldClose;
};

} // namespace mirage

#endif
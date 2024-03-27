#include "texture_renderer.hpp"

#include "check.hpp"
#include <shaderdirect.hpp>

namespace mirage
{

struct TextureRenderer::RenderingObjects
{
    GLuint vao, vbo, tex;
    ShaderWrapper quad_shader;
};

TextureRenderer::TextureRenderer(WindowMode pWindowMode, unsigned pResX, unsigned pResY)
    : mWindow(pWindowMode, pResX, pResY)
    , mWindowShouldClose(false)
{
    mRenderingObjects = new RenderingObjects();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenVertexArrays(1, &mRenderingObjects->vao);
    glGenBuffers(1, &mRenderingObjects->vbo);
    glBindVertexArray(mRenderingObjects->vao);
    glBindBuffer(GL_ARRAY_BUFFER, mRenderingObjects->vbo);

    const float quad_vertices[] =
    {
        -1.f, -1.f, 0.f, 0.f,
        1.f, -1.f, 1.f, 0.f,
        1.f, 1.f, 1.f, 1.f,

        -1.f, -1.f, 0.f, 0.f,
        1.f, 1.f, 1.f, 1.f,
        -1.f, 1.f, 0.f, 1.f
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    glGenTextures(1, &mRenderingObjects->tex);
    glBindTexture(GL_TEXTURE_2D, mRenderingObjects->tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTextureUnit(0, mRenderingObjects->tex);

    ShaderWrapper shader(
        false,
        shader_p(GL_VERTEX_SHADER, "C:/users/flora/dev/mirage/mirage/shaders/basic.glsl.vs"),
        shader_p(GL_FRAGMENT_SHADER, "C:/users/flora/dev/mirage/mirage/shaders/basic.glsl.fs")
    );
    mRenderingObjects->quad_shader = std::move(shader);
}

TextureRenderer::~TextureRenderer()
{
    glDeleteVertexArrays(1, &mRenderingObjects->vao);
    glDeleteBuffers(1, &mRenderingObjects->vbo);
    glDeleteTextures(1, &mRenderingObjects->tex);
    delete mRenderingObjects;
}

void TextureRenderer::Update(Vector4<uint8_t>* pColorBuffer, unsigned pDimensionX, unsigned pDimensionY)
{
    glBindTexture(GL_TEXTURE_2D, mRenderingObjects->tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pDimensionX, pDimensionY, 0, GL_RGBA, GL_UNSIGNED_BYTE, pColorBuffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);
}

void TextureRenderer::WriteToFile(Vector4<uint8_t>* pColorBuffer, unsigned pDimensionX, unsigned pDimensionY)
{
    std::ofstream outs("C:/users/flora/dev/mirage/mirage/ref.ppm");
    outs << "P3\n" << pDimensionX << ' ' << pDimensionY << "\n255\n";
    for (int y = 0; y < pDimensionY; ++y)
    {
        for (int x = 0; x < pDimensionX; ++x)
        {
            int idx = x + y * pDimensionX;
            Vector4<uint8_t> c = pColorBuffer[idx];
            outs << (int)c.x << ' ' << (int)c.y << ' ' << (int)c.z << '\n';
        }
    }
}

void TextureRenderer::Render()
{
    if (glfwWindowShouldClose(mWindow.mWindowPtr))
    {
        mWindowShouldClose = true;
    }

    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    mRenderingObjects->quad_shader.bind();
    glBindVertexArray(mRenderingObjects->vao);
    glBindTextureUnit(0, mRenderingObjects->tex);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glfwSwapBuffers(mWindow.mWindowPtr);
    glfwPollEvents();
}

} // namespace mirage
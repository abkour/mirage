#ifndef MIRAGE_RUN_TESTS

#include <cassert>
#include <iostream>
#include "tmp_runtests_macro.hpp"
#include "stringprintf.hpp"
#include "vecmath.hpp"

#include <shaderdirect.hpp>
#include "texture_renderer.hpp"
#include "triangle_p0.hpp"

void opengl_reference()
{
    mirage::Window mWindow(mirage::WindowMode::WINDOWED, 1000, 1000);

    const float quad_vertices[] =
    {
        -1.f, 0.f, 0.f, 0.f,
        0.5f, 0.f, 1.f, 0.f,
        0.f, 0.25f, 1.f, 1.f,
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_vertices), quad_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    ShaderWrapper shader(
        false,
        shader_p(GL_VERTEX_SHADER, "C:/users/flora/dev/mirage/mirage/shaders/ref.glsl.vs"),
        shader_p(GL_FRAGMENT_SHADER, "C:/users/flora/dev/mirage/mirage/shaders/ref.glsl.fs")
    );
    shader.bind();

    while (!glfwWindowShouldClose(mWindow.mWindowPtr))
    {
        glClearColor(0.f, 0.f, 0.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(mWindow.mWindowPtr);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}

int main()
{
    //opengl_reference();
    //return 0;

    mirage::Point2<unsigned> res(1024, 1024);
    mirage::TextureRenderer renderer(mirage::WindowMode::WINDOWED, res.x(), res.y());

    std::vector<mirage::Vector4<uint8_t>> color_buffer;
    color_buffer.resize(res.x() * res.y());
    for (int i = 0; i < color_buffer.size(); ++i)
    {
        color_buffer[i] = mirage::Vector4<uint8_t>(0, 0, 0, 0);
    }

    mirage::Point2<float> vertices[] =
    {
        {-1.f, 0.f}, {0.5f, 0.f}, {0.f, 0.25f}
    };
    mirage::Vector3<uint8_t> colors[] =
    {
        {255, 0, 0}, {0, 255, 0}, {255, 255, 255}
    };
    
    FormTriangle(color_buffer.data(), res.x(), res.y(), 
        vertices[0], vertices[1], vertices[2], 
        colors[0], colors[1], colors[2]
    );

    renderer.Update(color_buffer.data(), res.x(), res.y());

    while (!renderer.ShouldWinodwClose())
    {
        renderer.Render();
    }
}

#endif
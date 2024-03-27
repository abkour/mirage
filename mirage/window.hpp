#ifndef MIRAGE_WINDOW_HPP
#define MIRAGE_WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "point.hpp"

namespace mirage
{

enum class WindowMode 
{
    WINDOWED = 0, BORDERLESS, FULLSCREEN
};

struct Window
{
    Window(WindowMode pWindowMode, unsigned pResolutionX, unsigned pResolutionY);
    ~Window();

    float GetXOffset() const;
    float GetYOffset() const;
    void ResetCursorOffset() const;
    
    Point2<unsigned> GetWindowResolution() const { return mResolution; }

    WindowMode          mWindowMode;
    GLFWmonitor*        mPrimaryMonitor;
    GLFWwindow*         mWindowPtr;
    GLFWvidmode*        mVideoMode;
    Point2<int>         mCursorPosition;
    Point2<unsigned>    mWindowSize;

private:

    Point2<unsigned> mResolution;
};

} // namespace mirage

#endif
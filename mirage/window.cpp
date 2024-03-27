#include "window.hpp"

namespace mirage
{

void KeyCallback(GLFWwindow*, int, int, int, int);

Window::Window(WindowMode pWindowMode, unsigned pResolutionX, unsigned pResolutionY)
{
    if (!glfwInit())
        assert(false, "Error. GLFW could not be initialized!");
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE);

    mPrimaryMonitor = glfwGetPrimaryMonitor();
    if (!mPrimaryMonitor)
        assert(false, "Error. GLFW could not detect any monitor!");

    mVideoMode = const_cast<GLFWvidmode*>(glfwGetVideoMode(mPrimaryMonitor));
    if (!mVideoMode)
        assert(false, "Error. GLFW coudln't retrieve video mode of current monitor!");

    switch (pWindowMode) {
    case WindowMode::WINDOWED:
        mWindowPtr = glfwCreateWindow(pResolutionX, pResolutionY, "Default", NULL, NULL);
        break;
    case WindowMode::BORDERLESS:
        glfwWindowHint(GLFW_RED_BITS, mVideoMode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mVideoMode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mVideoMode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mVideoMode->refreshRate);
        mWindowPtr = glfwCreateWindow(pResolutionX, pResolutionY, "Default", mPrimaryMonitor, NULL);
        break;
    case WindowMode::FULLSCREEN:
        mWindowPtr = glfwCreateWindow(pResolutionX, pResolutionY, "Default", mPrimaryMonitor, NULL);
        break;
    default:
        assert(false, "Error. (Note to programmer) WindowMode structure should not contain cases outside the once handled from this location!");
        break;
    }

    if (!mWindowPtr)
        assert(false, "Error. GLFW could not create window!");

    mWindowSize = Point2<unsigned>(pResolutionX, pResolutionY);
    mWindowMode = mWindowMode;

    glfwMakeContextCurrent(mWindowPtr);
    if (glfwGetError(NULL))
        assert(false, "Error. GLFW could not make context current!");

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        assert(false, "Error. GLAD could not be loaded!");

    glfwSetKeyCallback(mWindowPtr, KeyCallback);

    mResolution = Point2<unsigned>(pResolutionX, pResolutionY);
}

Window::~Window()
{
    glfwDestroyWindow(mWindowPtr);
    glfwTerminate();
}

void KeyCallback(GLFWwindow* pWindow, int pKey, int pScancode, int pAction, int pMods)
{
    if (pKey == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(pWindow, true);
}

struct Cursor
{
    Cursor(float xpos, float ypos)
        : xpos(xpos)
        , ypos(ypos)
        , xoff(0.f)
        , yoff(0.f)
        , cursorZoom(0.f)
    {}

    float xpos;
    float ypos;
    float xoff;
    float yoff;

    float cursorZoom;

    bool initialEntry = true;
};

static Cursor uniqueCursor(0.f, 0.f);

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (uniqueCursor.initialEntry) {
        uniqueCursor.xpos = xpos;
        uniqueCursor.ypos = ypos;
        uniqueCursor.initialEntry = false;
    }

    uniqueCursor.xoff = xpos - uniqueCursor.xpos;
    uniqueCursor.yoff = uniqueCursor.ypos - ypos;
    uniqueCursor.xpos = xpos;
    uniqueCursor.ypos = ypos;
}

float Window::GetXOffset() const {
    return uniqueCursor.xoff;
}

float Window::GetYOffset() const {
    return uniqueCursor.yoff;
}

void Window::ResetCursorOffset() const {
    uniqueCursor.xoff = 0.f;
    uniqueCursor.yoff = 0.f;
}



} // namespace mirage
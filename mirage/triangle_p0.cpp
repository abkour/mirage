#include "triangle_p0.hpp"
#include "util.hpp"

namespace mirage
{

static void FormLine(
    Vector4<uint8_t>* pColorBuffer,
    unsigned pResolutionX, unsigned pResolutionY,
    Point2<float> v0, Point2<float> v1,
    Vector3<uint8_t> pColor0, Vector3<uint8_t> pColor1
);

void FormTriangle(
    Vector4<uint8_t>* pColorBuffer, 
    unsigned pResolutionX, unsigned pResolutionY,
    Point2<float> v0, Point2<float> v1, Point2<float> v2,
    Vector3<uint8_t> pColor0, Vector3<uint8_t> pColor1, Vector3<uint8_t> pColor2)
{
    FormLine(pColorBuffer, pResolutionX, pResolutionY, v0, v1, pColor0, pColor1);
    FormLine(pColorBuffer, pResolutionX, pResolutionY, v1, v2, pColor1, pColor2);
    FormLine(pColorBuffer, pResolutionX, pResolutionY, v2, v0, pColor2, pColor0);
}

static float Sign(float x)
{
    return (x < 0.f) ? -1.f : 1.f;
}

static void FormLine(
    Vector4<uint8_t>* pColorBuffer,
    unsigned pResolutionX, unsigned pResolutionY,
    Point2<float> v0, Point2<float> v1,
    Vector3<uint8_t> pColor0, Vector3<uint8_t> pColor1)
{
    const float dx = 1.f / pResolutionX;
    const float dy = 1.f / pResolutionY;
    Point2<float> nv0(v0.x() * 0.5f + 0.5f, v0.y() * 0.5f + 0.5f);
    Point2<float> nv1(v1.x() * 0.5f + 0.5f, v1.y() * 0.5f + 0.5f);
    Point2<float> dist = AbsDistBetweenPoints(nv0, nv1);
    Point2<float> sdist = SignedDistBetweenPoints(nv0, nv1);
    float cx = dist.x() / dx;
    float cy = dist.y() / dy;
    int LoopIterations = std::max(cx, cy);

    // Add small epsilon to avoid round-off errors.
    // This needs further investigation and is potentially cause of many errors.
    // Instead, shift v0 to be at the nearest pixel center.
    constexpr float eps = 1e-4f;
    Point2<float> S(nv0.x() + eps, nv0.y() + eps);
    Point2<float> StepSize(
        std::max(cx, cy) == cx ? Sign(sdist.x())*dx : sdist.x() / cy,
        std::max(cx, cy) == cy ? Sign(sdist.y())*dy : sdist.y() / cx
    );

    for (int i = 0; i < LoopIterations; ++i)
    {
        float IdxX = S.x() + i * StepSize.x();
        IdxX *= pResolutionX;
        float IdxY = S.y() + i * StepSize.y();
        IdxY *= pResolutionY;
        int Idx = IdxX + static_cast<int>(IdxY) * pResolutionX;

        if (Idx > pResolutionX * pResolutionY || Idx < 0)
            assert(false, "False idx");

        float a = static_cast<float>(i) / LoopIterations;
        uint8_t colorx = Lerp(pColor0.x, pColor1.x, a);
        uint8_t colory = Lerp(pColor0.y, pColor1.y, a);
        uint8_t colorz = Lerp(pColor0.z, pColor1.z, a);
        pColorBuffer[Idx] = Vector4<uint8_t>(colorx, colory, colorz, 255);
    }
}

} // namespace mirage
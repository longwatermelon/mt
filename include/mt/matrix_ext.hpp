#pragma once
#include "matrix.hpp"
#include <cmath>

namespace mt
{
    typedef mat<float, 3> mat3;
    typedef mat<float, 4> mat4;

    inline mat4 perspective(float fov, float aspect, float near, float far)
    {
        float ys = 1.f / std::tan(fov / 2.f);
        float xs = ys / aspect;
        float nf = near - far;

        mat_data<float, 4> data = {{
            { xs, 0.f, 0.f, 0.f },
            { 0.f, ys, 0.f, 0.f },
            { 0.f, 0.f, (far + near) / nf, -1.f },
            { 0.f, 0.f, 2.f * far * near / nf, 0.f }
        }};

        return mat4(data);
    }
}


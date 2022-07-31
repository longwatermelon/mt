#pragma once
#include "vec_ext.hpp"

namespace mt
{
    class quat : public vec4
    {
    public:
        quat() = default;
        quat(float x, float y, float z, float w)
            : vec4(x, y, z, w) {}
    };
}


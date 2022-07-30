#pragma once
#include "vec.hpp"

namespace mt
{
    class vec2 : public vec<float, 2>
    {
    public:
        vec2() = default;
        vec2(float x, float y)
            : vec(x, y) {}

        float &x{ m_data[0] }, &y{ m_data[1] };
    };

    class vec3 : public vec<float, 3>
    {
    public:
        vec3() = default;
        vec3(float x, float y, float z)
            : vec(x, y, z) {}

        vec3 cross(const vec3 &v) const
        {
            vec3 res;
            res.x = y * v.z - z * v.y;
            res.y = z * v.x - x * v.z;
            res.z = x * v.y - y * v.x;

            return res;
        }

        float &x{ m_data[0] }, &y{ m_data[1] }, &z{ m_data[2] };
    };

    class vec4: public vec<float, 4>
    {
    public:
        vec4() = default;
        vec4(float x, float y, float z, float w)
            : vec(x, y, z, w) {}

        float &x{ m_data[0] }, &y{ m_data[1] }, &z{ m_data[2] }, &w{ m_data[3] };
    };
}


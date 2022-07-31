#pragma once
#include "vec.hpp"

#define VEC_ASSIGN_OP(type) \
    type &operator=(const type &v) \
    { \
        m_data = v.data(); \
        return *this; \
    }

namespace mt
{
    class vec2 : public vec<float, 2>
    {
    public:
        vec2() = default;
        vec2(float x, float y)
            : vec(x, y) {}

        VEC_ASSIGN_OP(vec2);

        float &x{ m_data[0] }, &y{ m_data[1] };
    };

    class vec3 : public vec<float, 3>
    {
    public:
        vec3() = default;
        vec3(float x, float y, float z)
            : vec(x, y, z) {}

        VEC_ASSIGN_OP(vec3);

        float &x{ m_data[0] }, &y{ m_data[1] }, &z{ m_data[2] };
    };

    class vec4: public vec<float, 4>
    {
    public:
        vec4() = default;
        vec4(float x, float y, float z, float w)
            : vec(x, y, z, w) {}

        VEC_ASSIGN_OP(vec4);

        float &x{ m_data[0] }, &y{ m_data[1] }, &z{ m_data[2] }, &w{ m_data[3] };
    };

    template <typename T, std::size_t N>
    inline float dot(const vec<T, N> &a, const vec<T, N> &b)
    {
        float res = 0.f;
        for (std::size_t i = 0; i < N; ++i)
            res += a.data()[i] * b.data()[i];

        return res;
    }

    inline vec3 cross(const vec3 &a, const vec3 &b)
    {
        vec3 res;
        res.x = a.y * b.z - a.z * b.y;
        res.y = a.z * b.x - a.x * b.z;
        res.z = a.x * b.y - a.y * b.x;

        return res;
    }

    template <typename T, std::size_t N>
    inline float length(const vec<T, N> &v)
    {
        float len = 0.f;
        for (std::size_t i = 0; i < v.data().size(); ++i)
            len += v.data()[i] * v.data()[i];

        return std::sqrt(len);
    }

    template <typename T, std::size_t N>
    inline vec<T, N> normalize(const vec<T, N> &v)
    {
        /* return v / length(v); */
        return v / 2.f;
    }
}


#pragma once
#include <cctype>
#include <type_traits>
#include <array>

namespace mt
{
    template <typename T, std::size_t N>
    class vec
    {
    public:
        vec() = default;

        template <typename ...Args>
        vec(Args ...args)
            : m_data{ args... } {}

        vec(const std::array<T, N> &arr)
            : m_data(arr) {}

        vec(T value)
            : m_data{ value } {}

        vec<T, N> operator-() const
        {
            std::array<T, N> res;
            for (std::size_t i = 0; i < N; ++i)
                res[i] = -m_data[i];

            return vec<T, N>(res);
        }

        vec<T, N> operator+(const vec<T, N> &v) const
        {
            std::array<T, N> res;
            for (std::size_t i = 0; i < N; ++i)
                res[i] = m_data[i] + v.data()[i];

            return vec<T, N>(res);
        }

        vec<T, N> operator-(const vec<T, N> &v) const
        {
            return *this + -v;
        }

        const std::array<T, N> &data() const { return m_data; }

    protected:
        std::array<T, N> m_data;
    };

    class vec2 : public vec<float, 2>
    {
    public:
        vec2(float x, float y)
            : vec(x, y), x(m_data[0]), y(m_data[1]) {}

        float &x, &y;
    };

    class vec3 : public vec<float, 3>
    {
    public:
        vec3(float x, float y, float z)
            : vec(x, y, z), x(m_data[0]), y(m_data[1]), z(m_data[2]) {}

        float &x, &y, &z;
    };

    class vec4: public vec<float, 4>
    {
    public:
        vec4(float x, float y, float z, float w)
            : vec(x, y, z, w), x(m_data[0]), y(m_data[1]), z(m_data[2]), w(m_data[3]) {}

        float &x, &y, &z, &w;
    };
}


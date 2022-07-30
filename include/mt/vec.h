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
            : m_data{ args... }
        {
            /* static_assert(sizeof...(args) == N, "[vec::vec()] Constructor does not take right no. of args."); */
        }

        vec(T value)
            : m_data{ value } {}

        void add(const vec<T, N> &v)
        {
            for (std::size_t i = 0; i < m_data.size(); ++i)
                m_data[i] += v.data()[i];
        }

        const std::array<T, N> &data() const { return m_data; }

    protected:
        std::array<T, N> m_data;
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


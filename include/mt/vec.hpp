#pragma once
#include <cctype>
#include <type_traits>
#include <array>
#include <cmath>

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

        vec<T, N> operator*(float s) const
        {
            std::array<T, N> res;
            for (std::size_t i = 0; i < N; ++i)
                res[i] = m_data[i] * s;

            return vec<T, N>(res);
        }

        vec<T, N> operator/(float s) const
        {
            std::array<T, N> res;
            for (std::size_t i = 0; i < N; ++i)
                res[i] = m_data[i] / s;

            return res;
        }

        void operator+=(const vec<T, N> &v) { *this = *this + v; }
        void operator-=(const vec<T, N> &v) { *this = *this - v; }
        void operator*=(float s) { *this = *this * s; }
        void operator/=(float s) { *this = *this / s; }

        const std::array<T, N> &data() const { return m_data; }

    protected:
        std::array<T, N> m_data;
    };
}


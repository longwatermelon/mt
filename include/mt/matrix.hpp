#pragma once
#include <cctype>
#include <array>

namespace mt
{
    template <typename T, std::size_t N>
    class mat
    {
    public:
        mat()
        {
            m_data.fill({});
        }

        mat(float s)
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                m_data[i][i] = s;
            }
        }

        const std::array<std::array<T, N>, N> &data() const { return m_data; }

    private:
        std::array<std::array<T, N>, N> m_data{};
    };
}


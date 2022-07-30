#pragma once
#include <cctype>
#include <array>


namespace mt
{
    template <typename T, std::size_t N>
    using mat_data = std::array<std::array<T, N>, N>;

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

        mat(const mat_data<T, N> &data)
            : m_data(data) {}

        mat<T, N> operator*(mat<T, N> m) const
        {
            mat_data<T, N> res;

            for (std::size_t r = 0; r < N; ++r) // Row of this
            {
                for (std::size_t c = 0; c < N; ++c) // Column of m
                {
                    float f = m_data[r][0] * m.data()[0][c] +
                              m_data[r][1] * m.data()[1][c] +
                              m_data[r][2] * m.data()[2][c];
                    res[r][c] = f;
                }
            }

            return mat<T, N>(res);
        }

        mat<T, N> transpose() const
        {
            mat_data<T, N> tr;

            for (std::size_t r = 0; r < N; ++r)
            {
                for (std::size_t c = 0; c < N; ++c)
                {
                    tr[c][r] = m_data[r][c];
                }
            }

            return tr;
        }

        const mat_data<T, N> &data() const { return m_data; }

    private:
        mat_data<T, N> m_data{};
    };
}


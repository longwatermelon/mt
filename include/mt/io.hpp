#pragma once
#include "vec.hpp"
#include "matrix.hpp"
#include "quaternion.hpp"
#include <iostream>

namespace mt::io
{
    template <typename T, std::size_t N>
    inline void print_vec(const mt::vec<T, N> &v)
    {
        std::cout << "{ ";

        for (std::size_t i = 0; i < v.data().size(); ++i)
            std::cout << v.data()[i] << (i == v.data().size() - 1 ? "" : ", ");

        std::cout << " }\n";
    }

    template <typename T, std::size_t N>
    inline void print_mat(const mt::mat<T, N> &m)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            std::cout << "{ ";

            for (std::size_t j = 0; j < N; ++j)
                std::cout << m.data()[i][j] << (j == N - 1 ? "" : ", ");

            std::cout << " }\n";
        }
    }

    inline void print_quat(const mt::quat &q) { print_vec(q); }
}


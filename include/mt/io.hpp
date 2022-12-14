#pragma once
#include "vec.hpp"
#include "matrix.hpp"
#include "quaternion.hpp"
#include <iostream>
#include <iomanip>

namespace mt::io
{
    inline int precision = 3;

    template <typename T, std::size_t N>
    inline void print_array(const std::array<T, N> &arr)
    {
        std::ios old(0);
        old.copyfmt(std::cout);
        std::cout << "{ ";

        for (std::size_t i = 0; i < arr.size(); ++i)
            std::cout << std::fixed << std::setprecision(precision) << arr[i] << (i == arr.size() - 1 ? "" : ", ");

        std::cout.copyfmt(old);

        std::cout << " }\n";
    }

    template <typename T, std::size_t N>
    inline void print_vec(const mt::vec<T, N> &v)
    {
        print_array<T, N>(v.data());
    }

    template <typename T, std::size_t N>
    inline void print_mat(const mt::mat<T, N> &m)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            print_array<T, N>(m.data()[i]);
        }
    }

    inline void print_quat(const mt::quat &q)
    {
        print_array<float, 4>(q.data());
    }
}


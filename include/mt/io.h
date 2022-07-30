#pragma once
#include "vec.h"
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
}


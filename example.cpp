#include <iostream>
#include <mt/vec.hpp>
#include <mt/io.hpp>

int main()
{
    mt::vec3 v(1.f, 2.f, 3.f);
    mt::vec3 v2(3.f, 2.f, 1.f);

    mt::io::print_vec(v - v2);
}


#include <iostream>
#include <mt/mt.hpp>

int main()
{
    mt::vec3 v(1.f, 2.f, 3.f);
    mt::vec3 v2(3.f, 2.f, 1.f);
    v -= v2;
    v /= 5.f;

    mt::io::print_vec(v);
}


#include <iostream>
#include <mt/mt.hpp>

int main()
{
    mt::io::print_vec(mt::vec3(1.f, 2.f, 3.f).cross(mt::vec3(2.f, 5.f, 3.f)));
}


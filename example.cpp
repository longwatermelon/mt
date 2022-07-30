#include <iostream>
#include <mt/mt.hpp>

int main()
{
    mt::vec3 v(1.f, 2.f, 3.f);

    /* mt::io::print_vec(mt::vec3(1.f, 2.f, 3.f).cross(mt::vec3(2.f, 5.f, 3.f))); */
    /* mt::io::print_vec(mt::vec3(1.f, 5.f, 1.f).normalize()); */

    mt::mat4 mat(1.f);
    mt::io::print_mat(mat);
}


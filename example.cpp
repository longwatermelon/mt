#include <iostream>
#include <mt/mt.hpp>

int main()
{
    mt::vec3 v(1.f, 2.f, 3.f);

    /* mt::io::print_vec(mt::vec3(1.f, 2.f, 3.f).cross(mt::vec3(2.f, 5.f, 3.f))); */
    /* mt::io::print_vec(mt::vec3(1.f, 5.f, 1.f).normalize()); */

    mt::mat_data<float, 3> data = {
        std::array<float, 3>{ 1.f, 2.f, 3.f },
        std::array<float, 3>{ 4.f, 5.f, 6.f },
        std::array<float, 3>{ 7.f, 8.f, 9.f }
    };

    mt::mat3 m(data);
    mt::io::print_mat(m);

    mt::mat3 t = m.transpose();
    mt::io::print_mat(t);

    /* mt::mat4 mat(1.f); */
    /* mt::io::print_mat(mat); */
}


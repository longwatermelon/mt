#include <iostream>
#include <mt/mt.hpp>

int main()
{
    /* mt::vec3 v(1.f, 2.f, 3.f); */

    /* mt::io::print_vec(mt::vec3(1.f, 2.f, 3.f).cross(mt::vec3(2.f, 5.f, 3.f))); */
    /* mt::io::print_vec(mt::vec3(1.f, 5.f, 1.f).normalize()); */

/*     mt::mat_data<float, 3> data = {{ */
/*         { 1.f, 2.f, 3.f }, */
/*         { 4.f, 5.f, 6.f }, */
/*         { 7.f, 8.f, 9.f } */
/*     }}; */

/*     mt::mat3 m(data); */
/*     mt::io::print_mat(m); */

/*     std::cout << "\n"; */

/*     mt::mat3 t = m.transpose(); */
/*     mt::io::print_mat(t); */

    /* mt::mat4 mat(1.f); */
    /* mt::io::print_mat(mat); */

    mt::mat_data<float, 3> d0 = {{
        { -1.f, 1.f, -4.f },
        { -3.f, 0.f, 5.f },
        { 2.f, 4.f, 3.f }
    }};

    mt::mat_data<float, 3> d1 = {{
        { 6.f, -1.f, 7.f },
        { -2.f, 0.f, -3.f },
        { 1.f, 2.f, 3.f }
    }};

    mt::mat3 m0(d0);
    mt::mat3 m1(d1);
    mt::mat3 m = m0 * m1;

    mt::io::print_mat(m);
    std::cout << "\n";
    mt::io::print_mat(m * 2.f);
}


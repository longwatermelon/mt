#include <iostream>
#include <mt/mt.hpp>

int main()
{
    mt::quat q(mt::vec3(0.f, .5f, 1.f));
    /* mt::io::print_quat(q); */
    mt::quat inv = q.inverse();
    /* mt::io::print_quat(inv); */
    mt::io::print_quat(q * inv);

    return 0;
}


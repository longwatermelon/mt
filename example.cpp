#include <iostream>
#include <mt/vec.h>
#include <mt/io.h>

int main()
{
    mt::vec3 v(1.f, 2.f, 3.f);
    mt::vec4 v2(1.f, 2.f, 3.f, 4.f);
    mt::io::print_vec(v);
    mt::io::print_vec(v2);
}


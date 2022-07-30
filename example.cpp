#include <iostream>
#include <mt/vec.h>
#include <mt/io.h>

int main()
{
    mt::vec2 v2(1.f, 2.f);
    mt::vec3 v3(1.f, 2.f, 3.f);
    mt::vec4 v4(1.f, 2.f, 3.f, 4.f);
    mt::io::print_vec(v2);
    mt::io::print_vec(v3);
    mt::io::print_vec(v4);
}


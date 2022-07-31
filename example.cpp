#include <iostream>
#include <mt/mt.hpp>

int main()
{
    mt::quat quat(1.f, 2.f, 3.f, 4.f);
    mt::io::print_quat(quat);

    return 0;
}


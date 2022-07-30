#include "vec.hpp"


namespace mt
{
    class vec2 : public vec<float, 2>
    {
    public:
        vec2(float x, float y)
            : vec(x, y), x(m_data[0]), y(m_data[1]) {}

        float &x, &y;
    };

    class vec3 : public vec<float, 3>
    {
    public:
        vec3(float x, float y, float z)
            : vec(x, y, z), x(m_data[0]), y(m_data[1]), z(m_data[2]) {}

        float &x, &y, &z;
    };

    class vec4: public vec<float, 4>
    {
    public:
        vec4(float x, float y, float z, float w)
            : vec(x, y, z, w), x(m_data[0]), y(m_data[1]), z(m_data[2]), w(m_data[3]) {}

        float &x, &y, &z, &w;
    };
}


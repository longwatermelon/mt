#pragma once
#include "vec_ext.hpp"
#include <cmath>
#include <array>

namespace mt
{
    class quat;
    inline float length(const quat &q);

    class quat
    {
        std::array<float, 4> m_data{ 0.f };
    public:
        quat() = default;
        quat(float w, float x, float y, float z)
            : m_data{ w, x, y, z } {}

        quat(const std::array<float, 4> &data)
            : m_data(data) {}

        quat &operator=(const quat &q)
        {
            m_data = q.data();
            return *this;
        }

        quat(vec3 euler)
        {
            float yaw = euler.z;
            float pitch = euler.y;
            float roll = euler.x;

            float cy = cosf(yaw * .5f);
            float sy = sinf(yaw * .5f);
            float cp = cosf(pitch * .5f);
            float sp = sinf(pitch * .5f);
            float cr = cosf(roll * .5f);
            float sr = sinf(roll * .5f);

            x = sr * cp * cy - cr * sp * sy;
            y = cr * sp * cy + sr * cp * sy;
            z = cr * cp * sy - sr * sp * cy;
            w = cr * cp * cy + sr * sp * sy;
        }

        quat operator/(float s) const
        {
            return quat(w / s, x / s, y / s, z / s);
        }

        quat operator*(const quat &q) const
        {
            float a = this->w, b = this->x, c = this->y, d = this->z;
            float e = q.w, f = q.x, g = q.y, h = q.z;

            return quat(
                a*e - b*f - c*g - d*h,
                b*e + a*f + c*h - d*g,
                a*g - b*h + c*e + d*f,
                a*h + b*g - c*f + d*e
            );
        }

        quat conjugate() const
        {
            return quat(w, -x, -y, -z);
        }

        quat inverse() const
        {
            return conjugate() / (length(*this) * length(*this));
        }

        const std::array<float, 4> data() const { return m_data; }

        float &x{ m_data[1] }, &y{ m_data[2] }, &z{ m_data[3] }, &w{ m_data[0] };
    };

    inline float length(const quat &q)
    {
        return std::sqrt(
            q.x * q.x +
            q.y * q.y +
            q.z * q.z +
            q.w * q.w
        );
    }

    inline quat normalize(const quat &q)
    {
        return q / length(q);
    }

    inline float dot(const quat &a, const quat &b)
    {
        return a.x * b.x +
               a.y * b.y +
               a.z * b.z +
               a.w * b.w;
    }
}


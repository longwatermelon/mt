# mt
Header-only templated math library

# Features
## vec
Supports vec2, vec3, vec4 (float vectors)
* `mt::vec*(...)`
* `mt::vec*(std::array<T, N>)`
* `mt::vec*(T)`
* `mt::length(vec<T, N>)`
* `mt::normalize(vec<T, N>)`
* `mt::dot(vec<T, N>)`
* `mt::cross(vec<T, N>)`
* `operator+(vec<T, N>)`
* `operator-(vec<T, N>)`
* `operator*(vec<T, N>)`
* `operator/(vec<T, N>)`
* `operator+=(vec<T, N>)`
* `operator-=(vec<T, N>)`
* `operator*=(vec<T, N>)`
* `operator/=(vec<T, N>)`

## mat
Supports mat3 and mat4 (float matrices)
* `mt::mat(float)`
* `mt::mat(mat_data<T, N>)`
* `operator*(float)`
* `operator*(mat<T, N>)`
* `transpose()`

## quat
Represented as `w, x, y, z` when printed
* `quat(float w, float x, float y, float z)`
* `quat(std::array<float, 4>)`
* `quat(vec3)`
* `operator/(float)`
* `operator*(quat)`
* `conjugate()`
* `inverse()`
* `length(quat)`
* `normalize(quat)`
* `dot(quat, quat)`

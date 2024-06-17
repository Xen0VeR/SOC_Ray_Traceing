#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

using std::sqrt;

class vec3 {
public:
    double v[3];
    // constructor for vec3 class
    vec3 (){
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }

    vec3 (double v0 ,double v1, double v2){
        v[0] = v0;
        v[1] = v1;
        v[2] = v2;
    }

    double x() const {
        return v[0];
    }

    double y() const {
        return v[1];
    }

    double z() const {
        return v[2];
    }

    vec3 operator-() const { return vec3(-v[0], -v[1], -v[2]); }
    double operator[](int i) const { return v[i]; }
    double& operator[](int i) { return v[i]; }

    vec3& operator+=(const vec3& e){
        v[0] += e.v[0];
        v[1] += e.v[1];
        v[2] += e.v[2];
        return *this;
    }

    vec3& operator*=(double t) {
        v[0] *= t;
        v[1] *= t;
        v[2] *= t;
        return *this;
    }

    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
    }
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& e) {
    return out << e.v[0] << ' ' << e.v[1] << ' ' << e.v[2];
}

inline vec3 operator+(const vec3& u, const vec3& e) {
    return vec3(u.v[0] + e.v[0], u.v[1] + e.v[1], u.v[2] + e.v[2]);
}

inline vec3 operator-(const vec3& u, const vec3& e) {
    return vec3(u.v[0] - e.v[0], u.v[1] - e.v[1], u.v[2] - e.v[2]);
}

inline vec3 operator*(double t, const vec3& e) {
    return vec3(e.v[0] * t, e.v[1] * t, e.v[2] * t);
}

inline vec3 operator*(const vec3& e, double t) {
    return vec3(e.v[0] * t, e.v[1] * t, e.v[2] * t);
}

inline vec3 operator/(const vec3& e, double t) {
    return vec3(e.v[0] / t, e.v[1] / t, e.v[2] / t);
}

inline double dot(const vec3& u, const vec3& e) {
    return u.v[0] * e.v[0]
         + u.v[1] * e.v[1]
         + u.v[2] * e.v[2];
}

inline vec3 cross(const vec3& u, const vec3& e) {
    return vec3(u.v[1] * e.v[2] - u.v[2] * e.v[1],
                u.v[2] * e.v[0] - u.v[0] * e.v[2],
                u.v[0] * e.v[1] - u.v[1] * e.v[0]);
}

inline vec3 unit_vector(const vec3& e) {
    return e / e.length();
}

#endif

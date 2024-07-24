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

    bool near_zero() const {
        // Return true if  vector is close to 0 in all Dim.
        auto s = 1e-8;
        return (fabs(v[0]) < s) && (fabs(v[1]) < s) && (fabs(v[2]) < s);
    }


    static vec3 random() {
        return vec3(random_double(), random_double(), random_double());
    }

    static vec3 random(double min, double max) {
        return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
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

inline vec3 operator*(const vec3& v1, const vec3& v2) {
    return vec3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
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

inline vec3 random_in_unit_disk() {
    while (true) {
        auto p = vec3(random_double(-1,1), random_double(-1,1), 0);
        if (p.length_squared() < 1)
            return p;
    }
}

inline vec3 random_in_unit_sphere() {
    while (true)
    {
        auto p = vec3::random(-1,1);
        if (p.length_squared()<1){
            return p;
        }
    }
}

inline vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) {
        return on_unit_sphere;
    }
    else{
        return -on_unit_sphere;
    }
}

inline vec3 reflect(const vec3& n, const vec3& v){
    return v - 2*dot(v,n)*n;
}

inline vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat) {
    auto cos_theta = fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}

#endif

#ifndef HITTABLE_H
#define HITTABLE_H

#include "RAY.h"

class hit_record {
  public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        if (dot(r.direction(),outward_normal) < 0){
            normal = outward_normal;
            front_face = true;
        }
        else{
            normal = -outward_normal;
            front_face = false;
        }
    }
};

class hittable {
  public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif
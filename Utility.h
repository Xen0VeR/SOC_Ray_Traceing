#ifndef UTILITY_H
#define UTILITY_H

#include<cmath>
#include<iostream>
#include<limits>
#include<memory>

#include "color.h"
#include "RAY.h"
#include "vec3.h"

using std::sqrt;
using std::make_shared;
using std::shared_ptr;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees){
    return degrees * pi / 180;
}

#endif

#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

using namespace std;

// this function checks if the ray is hitting the sphere.
// (the error img was caused bc i did not changed bool to double, lol)
// double sphere_intersection(const point3& center, double radius, const ray& r){
//     vec3 oc = center - r.origin();
//     auto a = dot(r.direction(), r.direction());
//     auto b = -2.0 * dot(r.direction(), oc);
//     auto c = dot(oc, oc) - radius*radius;
//     auto discriminant = b*b - 4*a*c;
    
//     if (discriminant < 0){
//         return -1;
//     }
//     else{
//         return ((-b - sqrt(discriminant)) / 2*a);
//     }
// }

// imporved sphere intersection
double sphere_intersection(const point3& center, double radius, const ray& r){
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = h*h - a*c;
    
    if (discriminant < 0){
        return -1;
    }
    else{
        return (h - sqrt(discriminant)) / a;
    }
}

// experiment with this function to do something crazy with img.
// color ray_color(const ray& r){
//     vec3 unit_direction = unit_vector(r.direction());
//     auto alpha = 0.5 * (unit_direction.y() + 1.0);
//     return (1.0 - alpha) * color(1.0, 1.0, 1.0) + alpha * color(0.0, 0.0, 1.0);
// };

// just trying something different. (it works:))
// color ray_color(const ray& r) {
//     if (sphere_intersection(point3(0,0,-1), 0.5, r)){
//         return color(1, 0, 0);
//     }

//     vec3 unit_direction = unit_vector(r.direction());
    
//     double alpha = 0.5 * (unit_direction.x() + 1.0);
//     double beta = 0.5 * (unit_direction.y() + 1.0);
//     double gamma = 0.5 * (unit_direction.z() + 1.0);

//     color blended_color = (1.0 - alpha) * color(1.0, 0.7, 0.0) + alpha * color(0.0, 1.0, 0.0);
//     blended_color = (1.0 - beta) * blended_color + beta * color(0.0, 0.0, 1.0);
//     blended_color = (1.0 - gamma) * blended_color + gamma * color(1.0, 1.0, 0.0);
    
//     return blended_color;
// }

color ray_color(const ray& r) {
    auto temp = sphere_intersection(point3(0,0,-1), 0.5, r);
    if (temp > 0.0){
        vec3 Nor = unit_vector(r.at(temp) - vec3(0,0,-1));
        return 0.5*color(Nor.x()+1, Nor.y()+1, Nor.z()+1);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}


int main(){
    auto aspect_ratio = 16.0 / 9.0;
    int img_width = 400;

    int img_height = int(img_width / aspect_ratio);
    img_height = (img_height < 1) ? 1 : img_height;

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(img_width)/img_height);
    auto camera_center = point3(0, 0, 0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    auto pixel_delta_u = viewport_u / img_width;
    auto pixel_delta_v = viewport_v / img_height;

    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // rendering img

    cout<<"P3\n"<<img_width<<" "<<img_height<<"\n255\n";

    for (int j = 0; j < img_height; j++) {
        std::clog << "\rScanlines remaining: " << (img_height - j) << ' ' << std::flush;
        for (int i = 0; i < img_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";

    return 0;
}
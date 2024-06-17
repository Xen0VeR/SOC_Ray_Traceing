#include<iostream>
#include<random>

using namespace std;

int main(){
    // defining the image height and width
    int img_width = 256;
    int img_height = 256;

    // code to genrate an image
    cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = 0; j < img_height; j++) {

        std::clog << "\rScanlines remaining: " << (img_height - j) << ' ' << std::flush;
        
        for (int i = 0; i < img_width; i++) {
            auto r = double(i) / (img_width-1);
            auto g = 0.0;
            auto b = double(j) / (img_height-1);

            // this genrates the img with random rgb values.
            // auto r = rand() % 256;
            // auto g = rand() % 256;
            // auto b = rand() % 256;
            // if using this then multipy rgb with 1, as rand % 256 randomly asign it values

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.               \n";

    return 0;
}
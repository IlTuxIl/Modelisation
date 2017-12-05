#include <iostream>

#include "HeightField.h"
#include "Image.h"

int main() {

    Array a(vector2(0,0), vector2(1,2), 10, 10);
    HeightField hf;
    hf.load("data/img.ppm", vector2(0,0), vector2(500,500), 30, 500);
    int x,y;
    hf.getGridIndex(vector2(2,0), x,y);
    std::cout << x<< " " <<y <<std::endl;
    hf.saveImg("data/toto.ppm");
    return 0;
}

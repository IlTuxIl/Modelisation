#include <iostream>

#include "HeightField.h"
#include "Tools.h"

int main() {

    Array a(vector2(0,0), vector2(1,2), 10, 10);
    Tools t;
    Image i = t.load("data/img.ppm");

    return 0;
}
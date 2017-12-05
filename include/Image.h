#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "HeightField.h"

class Image
{
private:
    int height, width;
    int* values;

public:
    Image(std::string filename);
    int getHeight(){return height;}
    int getWidth(){return width;}
    int getValue(int x, int y){return values[x + width * y];};

    int* getValues(){return values;};
    ~Image();
};
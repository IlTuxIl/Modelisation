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
    Image() = default;
    Image(std::string filename);
    Image(std::string filename, int height, int width, const int* vals);

    int getHeight(){return height;}
    int getWidth(){return width;}
    void setHeight(int val){height = val;}
    void setWidth(int val){width = val;}
    int getValue(int x, int y){return values[x + width * y];};
    int* getValues(){return values;};
    ~Image();
};
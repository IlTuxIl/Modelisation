#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "HeightField.h"

class Image
{
private:
    int height, width;
    double* values;

public:
    Image(std::string filename);
    double* getValues(){return values;};
    ~Image();
};
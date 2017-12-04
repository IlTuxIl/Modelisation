#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "HeightField.h"

class Image
{
private:
    int height, width;
    std::vector< std::vector< double > > values;

public:
    Image(int x, int y);
    void setValue(int x, int y, double value);
    double getValue(int x, int y);
};

class Tools
{
  Image load(std::string filename);
  save(HeightField hf);
};




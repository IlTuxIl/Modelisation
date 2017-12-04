#include"../include/Tools.h"

Image::Image(int x, int y) : width(x), height(y)
{
    std::vector<double> line;
    for(int i = 0; i < x; i++)
            line.push_back(0);

    for(int j = 0; j < y; j++)
        this->values.push_back(line);
}

void Image::setValue(int x, int y, double value)
{
    this->values[x][y] = value;
}

double Image::getValue(int x, int y)
{
    return this->values[x][y];
}

Image Tools::load(std::string filename)
{
    std::string CodePPM;
    int height;
    int width;
    double max_value;
    double value;

    std::ifstream fichier(filename, std::ios::out | std::ios::binary);
    if(!fichier.is_open())
    {
        std::cout << "Impossible d'ouvrir le fichier en lecture !" << std::endl;
    }

    fichier >> CodePPM >> height >> width >> max_value;

    Image img = Image(width, height);

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            fichier >> value;
            img.setValue(i, j, value);
        }
    }

    fichier.close();  // on ferme le fichier
    return img;
}


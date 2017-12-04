#include"Image.h"

Image::Image(std::string filename)
{
    std::string CodePPM;
    double max_value;

    std::ifstream fichier(filename, std::ios::out | std::ios::binary);
    if(!fichier.is_open())
    {
        std::cout << "Impossible d'ouvrir le fichier en lecture !" << std::endl;
    }

    std::string toto;
    fichier >> CodePPM;
    fichier >> height >> width >> max_value;

    values = new double[height * width];

    for(int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            fichier >> values[i + j * width];

    fichier.close();  // on ferme le fichier
}


Image::~Image() {
    delete[] values;
}

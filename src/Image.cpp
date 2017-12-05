#include"Image.h"

Image::Image(std::string filename)
{
    std::string CodePPM;
    int max_value;

    std::ifstream fichier(filename, std::ios::out | std::ios::binary);
    if(!fichier.is_open())
    {
        std::cout << "Impossible d'ouvrir le fichier en lecture !" << std::endl;
    }

    std::string toto;
    fichier >> CodePPM;
    fichier >> height >> width >> max_value;
    values = new int[height * width];

    unsigned char octet;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            fichier >> octet;
            values[j + height * i] = octet;
        }
    }
    fichier.close();  // on ferme le fichier
}


Image::~Image() {
    delete[] values;
}

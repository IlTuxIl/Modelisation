#include"Image.h"

Image::Image(std::string filename)
{
    std::string CodePPM;
    int max_value;
    unsigned char trash;
    std::ifstream fichier(filename, std::ios::out | std::ios::binary);
    if(!fichier.is_open())
    {
        std::cout << "Impossible d'ouvrir le fichier en lecture !" << std::endl;
    }

    std::string toto;
    fichier >> CodePPM;
    fichier >> height >> width >> max_value;
    values = new unsigned char[height * width];

    unsigned char octet;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            fichier >> octet >> trash >> trash;
            values[j + width * i] = octet;
        }
    }
    fichier.clear();
    fichier.close();  // on ferme le fichier
}

Image::Image(std::string filename, int _height, int _width, const unsigned char *vals) {
    height = _height;
    width = _width;
    values = new unsigned char[height * width * 3];
    int j = 0;
    for(int i = 0; i < height * width * 3; ++i){
        values[i] = vals[j];
        ++i;
        values[i] = vals[j];
        ++i;
        values[i] = vals[j];
        ++j;
    }

    std::ofstream fichier(filename, std::ios::binary);

    fichier << "P6" << std::endl;
    fichier << height << " " << width << std::endl;
    fichier << 255 << std::endl;
    fichier.write((char*) values, height * width * 3);

    fichier.clear();
    fichier.close();
}

Image::~Image() {
    delete[] values;
}

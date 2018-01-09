#include "Image.h"

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
    fichier >> width >> height >> max_value;
    values = new int[height * width];

    int r,g,b;

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            fichier >> r >> g >> b;
            if(r != g || r != b)
                std::cout << "r != b != g" << std::endl;
            values[j + width * i] = r;

        }
    }
    fichier.clear();
    fichier.close();  // on ferme le fichier
}

Image::Image(std::string filename, int _width, int _height, const int *vals) {
    height = _height;
    width = _width;
    values = new int[height * width * 3];
    int j = 0;
    for(int i = 0; i < height * width * 3; i+=3){
        values[i] = vals[j];   //R
        values[i+1] = vals[j]; //G
        values[i+2] = vals[j]; //B
        ++j;
    }

    std::ofstream fichier(filename, std::ios::binary);

    fichier << "P3" << std::endl;
    fichier << width << " " << height << std::endl;
    fichier << 255 << std::endl;

    for(int i = 0; i < width * height; ++i)
        fichier << vals[i] << std::endl << vals[i] << std::endl << vals[i] << std::endl;

//    fichier.clear();
    fichier.close();
}

Image::~Image() {
    delete[] values;
}

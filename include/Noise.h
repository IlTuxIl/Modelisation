//
// Created by julien on 04/12/17.
//
#include "Vector.h"

#ifndef MODELISATION_NOISE_H
#define MODELISATION_NOISE_H

// Struct Noise copie de SimplexNoise obtenu ici -> http://liris.cnrs.fr/eric.galin/Doc/DocCore/class_simplex_noise.html
class Noise {

    private :
        static const int grad2[8][2]; // Gradients
        static const int perm[512]; //Permutation table

    public:
        int Integer(const double & x) const;
        double At(const vector2 & p) const;
        double AtRidg(const vector2 & p) const;

        inline double dot(const int *g, const double & x, const double & y) const
        { return g[0] * x + g[1] * y; }

        inline double dot(const int *g, const double & x, const double & y, const double & z) const
        { return g[0] * x + g[1] * y + g[2] * z; }
};


#endif //MODELISATION_NOISE_H

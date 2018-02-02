//
// Created by julien on 23/10/17.
//

#ifndef GEOALGO_MAILLAGE_H
#define GEOALGO_MAILLAGE_H

#include <vector>
#include <cstdio>
#include <string>
/*!
 * \file Maillage.h
 * \brief Structure dédié à l'affichage
 * \author FLECKINGER Julien
 */
/*!\class Maillage
 * \brief Class dédié à l'affichage
 */
class Maillage{
  public:
    /*!
     * 2 = segments, 3 = triangles
     * @param v :format tableau indice
     */
    void setNbIndiceFace(int v);

    /*!
     *
     * @param p tableau de points
     */
    void setVertexBuffer(std::vector<float>& p);

    /*!
     *
     * @param p tableau d'indices
     */
    void setIndiceBuffer(const std::vector<unsigned int>& p);

    /*!
     *
     * @return format du tableau d'indice.
     */
    int getNbIndiceFace() const;

    /*!
     *
     * @return récupére les points sous forme de tableau de 3 floats
     */
    std::vector<float> getVertex();
    /*!
     *
     * @return récupére les indices
     */
    std::vector<unsigned int> getIndice();

    /*!
     *
     * @return taille en bit du tableau de points renvoyé
     */
    size_t getVertexBufferSize() const;
    /*!
     *
     * @return taille en bit du tableau d'indice
     */
    size_t getIndiceBufferSize() const;

    void saveOBJ(std::string filename);

    void clear(){vertex.clear(); indice.clear();}

protected:
    std::vector<float> vertex;
    std::vector<unsigned int> indice;
    int nbIndicesFace;
};

#endif //GEOALGO_MAILLAGE_H

//
// Created by julien on 17/10/17.
//

#ifndef GEOALGO_RENDER_H
#define GEOALGO_RENDER_H

#include <GL/glew.h>
#include "Maillage.h"
#include "lib/orbiter.h"
#include "lib/color.h"

/*!
 * \file Render.h
 * \brief Permet d'afficher un Maillage avec OpenGL3.
 * \author FLECKINGER Julien
 */
namespace GeoLib {
    /*!\class Render
     * \brief Permet d'afficher un Maillage avec OpenGL3.
     */
    class Render {

      public:
        Render() = default;
        /*!
         * Constructeur
         * @param _mesh Tableau des maillages à charger
         * @param _c Couleurs pour chacun des maillage
         */
        Render(std::vector<Maillage*> _mesh, std::vector<Color> _c);

        /*!
         * Procédure d'affichage
         * @param cam la caméra
         * @param update vrai si il faut update les buffers
         * @param affiche tableau de booléan pour savoir si on affiche les maillages
         */
        void draw(Orbiter cam, bool update, std::vector<bool> affiche);

        /*!
         * Libération de la mémoire
         */
        void destroy();

      protected:
        /*!
         * Initialise les buffers sur la CG
         */
        void initBuffer();
        /*!
         * Update les buffers sur la CG
         */
        void updateBuffer();

        std::vector<Color> c;
        std::vector<Maillage*> mesh;
        std::vector<GLuint> indexBuffer;
        std::vector<GLuint> vao;
        std::vector<GLuint> buffer;
        GLuint program;
    };

}

#endif //GEOALGO_RENDER_H

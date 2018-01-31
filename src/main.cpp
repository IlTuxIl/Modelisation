#include <iostream>
#include <AnalyticHeightField.h>
#include <LayerField.h>
#include <Terrain.h>

#include "HeightField.h"
#include "Image.h"

#include "app.h"
#include "vec.h"
#include "Render.h"

using namespace GeoLib;
class Framebuffer : public App {
public:
    // constructeur : donner les dimensions de l'image, et eventuellement la version d'openGL.
    Framebuffer() : App(1024, 640) {}

    void moveCam(){
        int mx, my;
        unsigned int mb= SDL_GetRelativeMouseState(&mx, &my);
        if(mb & SDL_BUTTON(1))              // le bouton gauche est enfonce
            m_camera.rotation(mx, my);
        else if(mb & SDL_BUTTON(3))         // le bouton droit est enfonce
            m_camera.move(mx);
        if(key_state(SDLK_UP))         // le bouton du milieu est enfonce
            m_camera.translation((float) 0 / (float) window_width(), (float) camSpeed / (float) window_height());
        if(key_state(SDLK_DOWN))         // le bouton du milieu est enfonce
            m_camera.translation((float) 0 / (float) window_width(), (float) -camSpeed / (float) window_height());
        if(key_state(SDLK_LEFT))         // le bouton du milieu est enfonce
            m_camera.translation((float) camSpeed / (float) window_width(), (float) 0 / (float) window_height());
        if(key_state(SDLK_RIGHT))         // le bouton du milieu est enfonce
            m_camera.translation((float) -camSpeed / (float) window_width(), (float) 0 / (float) window_height());
    }


    int init() {

        double x = 10.0f;
        double y = 10.0f;

        Array a(Vector2(0,0), Vector2(1,2), 10, 10);
//        HeightField hf;
//        hf.load("data/terrain.ppm", Vector2(0,0), Vector2(x,y), 0, 5.0);
//        hf.noise(Vector2(0,0), Vector2(x,y), 0, 50.0, 100, 100);
//        std::cout << hf.getNormal(7,0) << std::endl;

        std::vector<double> freq;
        std::vector<double> ampli;

        freq.push_back(5000.0);
        freq.push_back(2450.0);
        freq.push_back(1220.0);
        freq.push_back(550.0);

        ampli.push_back(300.0);
        ampli.push_back(140.0);
        ampli.push_back(65.0);
        ampli.push_back(30.0);

//        AnalyticHeightField hf(Vector2(0,0), Vector2(x,y), 100, 100, freq, ampli);
//        hf.normalize();
//        hf.saveImg("data/test.ppm");

        HeightField hf;
        hf.load("data/test.ppm", Vector2(0,0), Vector2(x,y), 0, 500);
//        hf.noise(vector2(0,0), vector2(x,y), 0, 100.0, 100, 100);

//        HeightField hf;
//        hf.load("data/terrain.ppm", Vector2(0,0), Vector2(x,y), 0, 700.0);
//        hf = hf.reSample(200, 200);

        m_camera.lookat(Point(0,0), Point(x,y));

//        hf.saveImg("data/toto.ppm");
        std::vector<Maillage *> mesh;
        _mesh = hf.getMaillage();
        _mesh.saveOBJ("data/terrain.obj");

        mesh.push_back(&_mesh);
        std::vector<Color> c;
        c.push_back(Color(0.6,0.6,0.6));


        r = Render(mesh, c);
        glClearColor(0.2, 0.2, 0.2, 1.f);
        glDepthFunc(GL_LESS);
        glEnable(GL_DEPTH_TEST);
        glFrontFace(GL_CW);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        hf.destroy();
        return 0;   // ras, pas d'erreur
    }

    // destruction des objets de l'application
    int quit() {
        return 0;
    }

    int update(const float time, const float delta) {
        return 0;
    }

    // dessiner une nouvelle image
    int render() {
        moveCam();
        std::vector<bool> affiche;
        bool update = false;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(key_state(' '))
            update = true;
        affiche.push_back(true);
        r.draw(m_camera, update, affiche);

        return 1;
    }

protected:
    Orbiter m_camera;
    Render r;
    Maillage _mesh;
    float camSpeed = 10;
};


int main(int argc, char **argv) {

//    Framebuffer tp;
//    tp.run();
    HeightField hf;
    hf.load("data/terrain.ppm", Vector2(0,0), Vector2(10000.f,10000.f), 0, 700.0);

    Terrain t(hf);

    Foret f = t.Vegetation(10.0);

    ScalarField foret = f.toScalar();
    foret.normalize();
    foret.saveImg("data/Veget.ppm");

    t.getWetness().normalize();
    t.getWetness().saveImg("data/Wetness.ppm");
//    a.normalize();
//    a.saveImg("data/Drainage.ppm");
//    s.saveImg("data/Slope.ppm");

//    hf.PowerStream(s, a).saveImg("data/WaterPower.ppm");

    return 0;
}

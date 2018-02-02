#include <iostream>
#include <AnalyticHeightField.h>
#include <LayerField.h>
#include <Terrain.h>
#include <Route.h>

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

        double x = 10000.0f;
        double y = 10000.0f;

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

        ampli.push_back(700.0);
        ampli.push_back(354.0);
        ampli.push_back(149.0);
        ampli.push_back(85.0);

//        AnalyticHeightField hf(Vector2(0,0), Vector2(x,y), 100, 100, freq, ampli);
//        hf.retourne();
//        hf.saveImg("data/test.ppm");

        HeightField hf;
        hf.load("data/terrain.ppm", Vector2(0,0), Vector2(10000.f,10000.f), 0, 700.0);

//        hf = hf.reSample(250, 250);
        t = Terrain(hf);
        f = t.Vegetation(10.f);
        for(int i = 0; i < 10; ++i){
            ++annee;
            std::cout << "Simulation de l'année : " << annee << std::endl;
            f.simule();
        }
//        f.saveForet("data/terrain.veget");

//        Foret f = Foret("data/terrain.veget", t);
//        ScalarField veget = f.toScalar().normalize();
//        veget.saveImg("data/Veget.ppm");

//        hf.noise(vector2(0,0), vector2(x,y), 0, 100.0, 100, 100);

//        HeightField hf;
//        hf.load("data/terrain.ppm", Vector2(0,0), Vector2(x,y), 0, 7a00.0);
//        hf = hf.reSample(200, 200);

        m_camera.lookat(Point(0,0), Point(x,y));

//        hf.saveImg("data/toto.ppm");
        std::vector<Maillage *> mesh;
        sapin = f.toMaillage("Sapin");
        pommier = f.toMaillage("Pommier");

        _mesh = hf.getMaillage();
        _mesh.saveOBJ("data/terrain.obj");

        mesh.push_back(&_mesh);
        mesh.push_back(&sapin);
        mesh.push_back(&pommier);

        std::vector<Color> c;
        c.push_back(Color(0.6,0.6,0.6));
        c.push_back(Color(0.0,1.0,0.0));
        c.push_back(Color(1.0,0.0,0.0));


        r = Render(mesh, c);
        glClearColor(0.2, 0.2, 0.2, 1.f);
        glDepthFunc(GL_LESS);
        glEnable(GL_DEPTH_TEST);
        glFrontFace(GL_CW);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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
        bool update = false;
        moveCam();
        std::vector<bool> affiche;

        if(key_state(' ') && canSimule){
            ++annee;
            std::cout << "Simulation de l'année : " << annee << std::endl;
            f.simule();
            sapin.clear();
            sapin = f.toMaillage("Sapin");
            pommier.clear();
            pommier = f.toMaillage("Pommier");
            canSimule = false;
            update = true;
        }
        if(key_state('e'))
            canSimule = true;


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        affiche.push_back(true);
        affiche.push_back(true);
        affiche.push_back(true);

        r.draw(m_camera, update, affiche);

        return 1;
    }

protected:
    Orbiter m_camera;
    Render r;
    Maillage _mesh;

    Maillage sapin;
    Maillage pommier;

    float camSpeed = 5;
    Foret f;
    Terrain t;
    int annee = 0;
    bool canSimule = true;
};

int main(int argc, char **argv) {

//    Framebuffer tp;
//    tp.run();

    HeightField hf;
    hf.load("data/terrain.ppm", Vector2(0,0), Vector2(10000.f,10000.f), 0, 700.0);
    Terrain t(hf);

    Route r(t);

    r.computeRoute(Vector2(150.0, 203.0), Vector2(8600.f,2200.f));
    r.computeRoute(Vector2(150.0, 203.0), Vector2(7050.f, 8502.f));

    ScalarField route = r.toScalar();

    route.saveImg("data/route.ppm");

//    Foret f = t.Vegetation(10.f);
//    Foret f = Foret("data/terrain.veget", t);

//    for(int i = 0; i < 15; ++i){
//        std::cout << "Simulation de la " << i << " annees..." << std::endl;
//        f.simule();
//    }

//    ScalarField drai = t.getDrainage().racineCarre();
//    drai = drai.normalize();
//    ScalarField wet = t.getWetness().normalize();
//    ScalarField slope = t.getSlope().normalize();
//    ScalarField Pow = t.getPowerStream().normalize();
//    ScalarField veget = f.toScalar().normalize();
//
//    wet.saveImg("data/Wetness.ppm");
//    slope.saveImg("data/Slope.ppm");
//    Pow.saveImg("data/PowerStream.ppm");
//    drai.saveImg("data/Drainage.ppm");
//    veget.saveImg("data/Veget.ppm");
//    f.saveForet("data/terrain.veget");

//    HeightField hf;
//    hf.load("data/img.ppm", Vector2(0,0), Vector2(10.f,10.f), 0, 1.0);
//    hf.getHeight(Vector2(10.0f, 10.0f));

    return 0;
}
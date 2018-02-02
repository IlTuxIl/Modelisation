#include "Route.h"
#include "assert.h"

float distance(const Index& pos_courante,const Index& voisin)
{
    return std::sqrt(std::pow(pos_courante.x - voisin.x, 2.f) + std::pow(pos_courante.y - voisin.y, 2.f));
}

bool operator<(Index const &a, Index const& b)
{
    if(a.x < b.x) return true;
    else if (a.x > b.x) return false;
    else if (a.y < b.y) return true;
    else return false;
}

bool operator==(Index const &a, Index const& b)
{
    return ( (a.x == b.x) && (a.y == b.y) );
}

Route::Route(const Terrain& hf)
{
    terrain = hf;
    //Case t_cases[hf.getSizeGridX()][hf.getSizeGridY()];
    t_cases.resize(hf.getArray().getSizeX());

    for(uint i = 0; i < hf.getArray().getSizeX(); i++)
        t_cases[i].resize(hf.getArray().getSizeY());

    for(int i = 0; i < hf.getArray().getSizeX(); i++){
        for(int j = 0; j < hf.getArray().getSizeY(); ++j) {
            t_cases[i][j].position = Index(i, j);
        }
    }
}

void Route::computeRoute(const Vector2 &depart, const Vector2 &objectif) {
    // Trouve pour départ et objectif les indes correspondants
    Index index_depart((depart.getX() - terrain.getArray().getXMin()) / terrain.getArray().getSizeGridX(),
                       (depart.getY() - terrain.getArray().getYMin()) / terrain.getArray().getSizeGridY());
    Index index_objectif((objectif.getX() - terrain.getArray().getXMin()) / terrain.getArray().getSizeGridX(),
                         (objectif.getY() - terrain.getArray().getYMin()) / terrain.getArray().getSizeGridY());

    // Initialisation des variables
    std::set<Index> a_traiter, traites;
    a_traiter.insert(index_depart);
    t_cases[index_depart.x][index_depart.y].cout = 0;

    std::vector<Index> tmpChemin;

    while (!a_traiter.empty())
    {
        // On récupère la position la plus prometeuse
        Index pos_courante = findBest(a_traiter, t_cases);

        // Si cette position est notre objectif
        if (pos_courante.x == index_objectif.x && pos_courante.y == index_objectif.y)
        {
            cout = t_cases[pos_courante.x][pos_courante.y].cout;
            // On reconstruit le chemin
            while (!(t_cases[pos_courante.x][pos_courante.y].position == index_depart))
            {
                tmpChemin.push_back(pos_courante);
                pos_courante = t_cases[pos_courante.x][pos_courante.y].parent;//////// TODO
            }
            chemin.push_back(tmpChemin);
            return;
        }

        // Sinon, on déplace cette position de la liste a_traiter à la liste de Vector2 traités
        a_traiter.erase(pos_courante);
        traites.insert(pos_courante);

        // V est le cout de la case a la position courante
        float cout_actuel = t_cases[pos_courante.x][pos_courante.y].cout;

        // Pour chacune des positions voisines
        std::vector<Index> voisins = getVoisins(pos_courante, terrain.getArray().getSizeX(), terrain.getArray().getSizeY());

        for(int i = 0; i < voisins.size(); ++i)
        {
            Index voisin = voisins[i];
            float cout_voisin = calculeCout(pos_courante, voisin) + cout_actuel;
            bool best = false;

            // On vérifie si c'est la première fois qu'on passe sur cette case
            if ((a_traiter.find(voisin) == a_traiter.end()) && (traites.find(voisin) == traites.end()))
            {
                best = true;
                a_traiter.insert(voisin);
            }
                // On regarde si on a trouvé un meilleur chemin pour cette case
            else if(t_cases[voisin.x][voisin.y].cout > cout_voisin)
            {
                best = true;
            }

            // Si le chemin actuel est le meilleurs jusqu'à maintenant
            if (best)
            {
                // On met à jour la case
                t_cases[voisin.x][voisin.y].parent = pos_courante;
                t_cases[voisin.x][voisin.y].cout = cout_voisin;
                // On considère la distance euclidienne comme heurisitique
                t_cases[voisin.x][voisin.y].heuristique = cout_voisin + (int) distance(voisin, index_objectif);
            }
        }
    }

    assert(false);
}

std::vector<Index> Route::getVoisins(const Index& p, int tailleX, int tailleY)
{
    // TODO Faire voisinage de distance 2
    std::vector<Index> res;
    for(int i = p.x - 1; i <= p.x + 1; i++)
    {
        if(i < 0 || i >= tailleX) continue;
        for(int j = p.y - 1; j <= p.y + 1; j++)
        {
            if(j < 0 || j >= tailleY || (i == p.x && j == p.y)) continue;
            res.push_back(Index(i, j));
        }
    }
    return res;
}

float Route::calculeCout(const Index& pos_courante,const Index& voisin)
{
    float sCur = terrain.getHeightMap().getValue(pos_courante.x, pos_courante.y);
    float sNext = terrain.getHeightMap().getValue(voisin.x, voisin.y);

    return distance(pos_courante, voisin) + abs(sCur - sNext);
}

Index Route::findBest(const std::set<Index> &liste, const std::vector<std::vector<Case>>& t_cases)
{
    float meilleurH = INFINITY;
    Index meilleurI(0, 0);

    std::set<Index>::iterator it;
    for (it = liste.begin(); it != liste.end(); it ++)
    {
        Index index = *it;
        float heuristique = t_cases[index.x][index.y].heuristique;
        if(heuristique < meilleurH)
        {
            meilleurH = heuristique;
            meilleurI = index;
        }
    }
    return meilleurI;
}

ScalarField Route::toScalar() {
    ScalarField ret(terrain.getArray(), 0.f);

    for(int j = 0; j < chemin.size(); ++j) {
        int size = chemin[j].size()-1;
        ret.setValue(chemin[j][0].x, chemin[j][0].y, 255);

        for (int i = 1; i < chemin[j].size() - 1; ++i)
            ret.setValue(chemin[j][i].x, chemin[j][i].y, 100);

        ret.setValue(chemin[j][size].x, chemin[j][size].y, 255);
    }
    return ret;
}

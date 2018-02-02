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

Route::Route(const Vector2& depart, const Vector2& objectif, const HeightField& hf)
{
    //Case t_cases[hf.getSizeGridX()][hf.getSizeGridY()];
    std::vector<std::vector<Case>> t_cases(hf.getSizeGridX());
    for(uint i = 0; i < hf.getSizeGridX(); i++)
    {
        t_cases[i].resize(hf.getSizeGridY());
    }

    // Trouve pour départ et objectif les indes correspondants
    Index index_depart((depart.getX() - hf.getXMin()) / hf.getSizeGridX(),
                       (depart.getY() - hf.getYMin()) / hf.getSizeGridY());
    Index index_objectif((objectif.getX() - hf.getXMin()) / hf.getSizeGridX(),
                         (objectif.getY() - hf.getYMin()) / hf.getSizeGridY());

    // Initialisation des variables
    std::set<Index> a_traiter, traites;
    a_traiter.insert(index_depart);
    t_cases[index_depart.x][index_depart.y].cout = 0;

    while (!a_traiter.empty())
    {
        // On récupère la position la plus prometeuse
        Index pos_courante = findBest(a_traiter, t_cases);

        // Si cette position est notre objectif
        if (pos_courante.x == index_objectif.x && pos_courante.y == index_objectif.y)
        {
            cout = t_cases[pos_courante.x][pos_courante.y].cout;
            // On reconstruit le chemin
            while (t_cases[pos_courante.x][pos_courante.y].parent != NULL)
            {
                chemin.push_back(pos_courante);
                pos_courante = *t_cases[pos_courante.x][pos_courante.y].parent;//////// TODO
            }
            return;
        }

        // Sinon, on déplace cette position de la liste a_traiter à la liste de Vector2 traités
        a_traiter.erase(pos_courante);
        traites.insert(pos_courante);

        // V est le cout de la case a la position courante
        float cout_actuel = t_cases[pos_courante.x][pos_courante.y].cout;

        // Pour chacune des positions voisines
        std::vector<Index> voisins = getVoisins(pos_courante, hf.getSizeX(), hf.getSizeY());

        for(int i = 0; i < voisins.size(); ++i)
        {
            Index voisin = voisins[i];
            float cout_voisin = calculeCout(pos_courante, voisin, hf) + cout_actuel;
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
                Case& c = t_cases[voisin.x][voisin.y];
                c.parent = &pos_courante;
                c.cout = cout_voisin;

                // On considère la distance euclidienne comme heurisitique
                c.heuristique = cout_voisin + (int) distance(voisin, index_objectif);
                c.heuristique = cout_voisin + (int) distance(voisin, index_objectif); // TODO : Ajouter pente
            }
        }
    }

    // Pas de solution (ne devrait pas arrivé dans le cas du robot)
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

float Route::calculeCout(const Index& pos_courante,const Index& voisin, const HeightField& hf)
{
    return 1.f; // TODO Prendre en compte la distance et la pente
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

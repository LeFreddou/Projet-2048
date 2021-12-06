#include <vector>
#include <iostream>
#include <random>
using namespace std;
#include "Modele.h"

/** Compare les plateaux de deux Plateaux
 * @param t un Plateau
 * @return true si les deux plateaux sont égaux
 **/
bool Plateau::egale(Plateau t)
{
    return (plateau == t.plateau);
}

/** génère un Plateau de dimensions 4*4 ne contenant que des 0 avec un score de 0
 *  @return un Plateau vide
 **/

Plateau plateauVide()
{
    Plateau p;
    p.plateau = vector<vector<int>>(4);
    for (int i = 0; i < p.plateau.size(); i++)
    {
        p.plateau[i] = vector<int>(4);
        for (int j = 0; j < 4; j++)
        {
            p.plateau[i][j] = 0;
        }
    }
    p.score = 0;
    return p;
}

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre()
{
    return (2 + (2 * ((rand() % 10) / 9)));
}

/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial()
{
    Plateau p;
    p = plateauVide();
    int x1 = rand() % 4;
    int y1 = rand() % 4;
    int x2, y2;
    do
    {
        x2 = rand() % 4;
        y2 = rand() % 4;
    } while ((x2 == x1) and (y2 == y1));
    p.plateau[x1][y1] = tireDeuxOuQuatre();
    p.plateau[x2][y2] = tireDeuxOuQuatre();
    return p;
}

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param p le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        bool blocage = false;
        for (int j = 1; j < p.plateau[i].size(); j++)
        {
            int n = 0;
            while ((n < j) and (p.plateau[i][j - n - 1] == 0))
            {
                n++;
            }
            int valeur = p.plateau[i][j];
            p.plateau[i][j] = 0;
            p.plateau[i][j - n] = valeur;
            if ((j - n > 0) and (blocage == false) and (p.plateau[i][j - n] == p.plateau[i][j - n - 1]))
            {
                p.plateau[i][j - n - 1] = 2 * p.plateau[i][j - n - 1];
                p.score += p.plateau[i][j - n - 1];
                p.plateau[i][j - n] = 0;
                blocage = true;
            }
            else if (p.plateau[i][j - n] != 0)
            {
                blocage = false;
            }
        }
    }
    return p;
}

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param p le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        bool blocage = false;
        for (int j = p.plateau.size() - 2; j >= 0; j--)
        {
            int n = 0;
            while ((n + j < p.plateau.size() - 1) and (p.plateau[i][j + n + 1] == 0))
            {
                n++;
            }
            int valeur = p.plateau[i][j];
            p.plateau[i][j] = 0;
            p.plateau[i][j + n] = valeur;
            if ((j + n < p.plateau.size() - 1) and (blocage == false) and (p.plateau[i][j + n] == p.plateau[i][j + n + 1]))
            {
                p.plateau[i][j + n + 1] = 2 * p.plateau[i][j + n + 1];
                p.score += p.plateau[i][j + n + 1];
                p.plateau[i][j + n] = 0;
                blocage = true;
            }
            else if (p.plateau[i][j + n] != 0)
            {
                blocage = false;
            }
        }
    }
    return p;
}

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param p le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        bool blocage = false;
        for (int j = 1; j < p.plateau[i].size(); j++)
        {
            int n = 0;
            while ((n < j) and (p.plateau[j - n - 1][i] == 0))
            {
                n++;
            }
            int valeur = p.plateau[j][i];
            p.plateau[j][i] = 0;
            p.plateau[j - n][i] = valeur;
            if ((j - n > 0) and (blocage == false) and (p.plateau[j - n][i] == p.plateau[j - n - 1][i]))
            {
                p.plateau[j - n - 1][i] = 2 * p.plateau[j - n - 1][i];
                p.score += p.plateau[j - n - 1][i];
                p.plateau[j - n][i] = 0;
                blocage = true;
            }
            else if (p.plateau[j - n][i] != 0)
            {
                blocage = false;
            }
        }
    }
    return p;
}

/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param p le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        bool blocage = false;
        for (int j = p.plateau.size() - 2; j >= 0; j = j - 1)
        {
            int n = 0;
            while ((n + j < p.plateau.size() - 1) and (p.plateau[j + n + 1][i] == 0))
            {
                n++;
            }
            int valeur = p.plateau[j][i];
            p.plateau[j][i] = 0;
            p.plateau[j + n][i] = valeur;
            if ((j + n < p.plateau.size() - 1) and (blocage == false) and (p.plateau[j + n][i] == p.plateau[j + n + 1][i]))
            {
                p.plateau[j + n + 1][i] = 2 * p.plateau[j + n][i];
                p.score += p.plateau[j + n + 1][i];
                p.plateau[j + n][i] = 0;
                blocage = true;
            }
            else if (p.plateau[j + n][i] != 0)
            {
                blocage = false;
            }
        }
    }
    return p;
}

/** déplace les tuiles d'un Plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param p le Plateau
 *  @param direction la direction
 *  @return le Plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau p, string direction)
{
    if (direction == "z")
    {
        if (p.egale(deplacementHaut(p)))
        {
            return p;
        }
        p = deplacementHaut(p);
    }
    else if (direction == "s")
    {
        if (p.egale(deplacementBas(p)))
        {
            return p;
        }
        p = deplacementBas(p);
    }
    else if (direction == "q")
    {
        if (p.egale(deplacementGauche(p)))
        {
            return p;
        }
        p = deplacementGauche(p);
    }
    else if (direction == "d")
    {
        if (p.egale(deplacementDroite(p)))
        {
            return p;
        }
        p = deplacementDroite(p);
    }
    int x;
    int y;
    do
    {
        x = rand() % (p.plateau.size());
        y = rand() % (p.plateau[x].size());
    } while (p.plateau[x][y] != 0);
    p.plateau[x][y] = tireDeuxOuQuatre();
    return p;
}

/** affiche un Plateau
 * @param p le Plateau
 **/
string dessine(Plateau p)
{
    string dessin = "\n*************************\n";
    for (int i = 0; i < p.plateau.size(); i++)
    {
        for (int j = 0; j < p.plateau[i].size(); j++)
        {
            dessin += "\e[37m*";
            dessin += "\e[" + to_string(31 + (p.plateau[i][j]) % 5) + "m";
            if (p.plateau[i][j] == 0)
            {
                dessin += "     ";
            }
            else if (p.plateau[i][j] < 10)
            {
                dessin += "  " + to_string(p.plateau[i][j]) + "  ";
            }
            else if (p.plateau[i][j] < 100)
            {
                dessin += " " + to_string(p.plateau[i][j]) + "  ";
            }
            else if (p.plateau[i][j] < 1000)
            {
                dessin += " " + to_string(p.plateau[i][j]) + " ";
            }
            else if (p.plateau[i][j] < 10000)
            {
                dessin += to_string(p.plateau[i][j]) + " ";
            }
            else
            {
                dessin += to_string(p.plateau[i][j]);
            }
        }
        dessin += "\e[37m*\n*************************\n";
    }
    return dessin;
}

/** permet de savoir si une partie est terminée
 *  @param p un Plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau p)
{
    return ((p.egale(deplacementGauche(p))) and (p.egale(deplacementHaut(p))) and (p.egale(deplacementDroite(p))) and (p.egale(deplacementBas(p))));
}

/** permet de savoir si une partie est gagnée
 * @param p un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau p)
{
    for (int i = 0; i < p.plateau.size(); i++)
    {
        for (int j = 0; j < p.plateau[i].size(); j++)
        {
            if (p.plateau[i][j] >= 2048)
            {
                return true;
            }
        }
    }
    return false;
}

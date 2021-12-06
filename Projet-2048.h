#include <vector>
#include <iostream>
#include <random>
using namespace std;

class Plateau
{
public:
    /** Compare les plateaux de deux Plateaux
     * @param t un Plateau
     * @return true si les deux plateaux sont égaux
     **/
    bool egale(Plateau t);
    vector<vector<int>> plateau;
    int score;
};

/** génère un Plateau de dimensions 4*4 ne contenant que des 0 avec un score de 0
 *  @return un Plateau vide
 **/
Plateau plateauVide();

/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial();

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau);

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau);

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau);

/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau);

/** déplace les tuiles d'un Plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le Plateau
 *  @param direction la direction
 *  @return le Plateau si le déplacement est invalide, sinon le Plateau déplacé dans la direction
 **/
Plateau deplacement(Plateau plateau, string direction);

/** affiche un Plateau
 * @param p le Plateau
 * @return l'affichage du plateau
 **/
string dessine(Plateau p);

/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si aucun déplacement n'est possible, false sinon
 **/
bool estTermine(Plateau plateau);

/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048 ou plus, false sinon
 **/
bool estGagnant(Plateau plateau);

#include "projet-2048.h"


int main()
{
    srand(time(NULL));
    Plateau p = plateauInitial();
    cout << dessine(p);
    while (not estTermine(p))
    {
        int direction;
        do
        {
            cin >> direction;
        } while ((direction < 0 or direction > 3) or (p.egale(deplacement(p, direction))));
        p = deplacement(p, direction);
        cout << dessine(p) << endl
             << "score : " << p.score << endl;
    }
    if (estGagnant(p))
    {
        cout << "vous avez gagnez, votre score finale est de : " << p.score;
    }
    else
    {
        cout << "Vous avez perdu, votre score finale est de : " << p.score;
    }
}

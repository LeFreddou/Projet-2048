#include <vector>
#include <iostream>
#include <random>
using namespace std;
#include "Projet-2048.h"

int main()
{
    srand(time(NULL));
    Plateau p;
    p.plateau = {{1024,1024,512,256},{512,256,512,128},{256,128,64,32},{64,512,2,0}};
    p.score = 42484;
    cout << dessine(p);
    while (not estTermine(p))
    {
        string direction;
        do
        {
            cin >> direction;
        } while (((direction.compare("z") != 0) and (direction.compare("s") != 0) and (direction.compare("q") != 0) and (direction.compare("d") != 0)) or (p.egale(deplacement(p, direction))));
        p = deplacement(p, direction);
        cout << dessine(p) << endl
             << "score : " << p.score << endl
             << endl;
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

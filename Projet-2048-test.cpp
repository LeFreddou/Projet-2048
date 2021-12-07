#include <iostream>
#include "Projet-2048.h"
using namespace std;

#define CHECK(test) if (!(test)) cout << "Test failed in file " \
         << __FILE__ << " line " << __LINE__ << ": " #test << endl

void plateauVide_test(){
    CHECK(plateauVide()==({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}));
}

void deplacementGauche_test(){
    CHECK(deplacementGauche({{2,0,2,2},{4,4,8,0},{4,4,0,8},{8,0,4,4}}) == ({{4,2,0,0},{8,8,0,0},{8,8,0,0},{8,8,0,0}}));
    CHECK(deplacementGauche({{128,256,256,2},{0,0,0,2},{0,0,4,4},{0,2,2,4}}) == ({{128,512,2,0},{2,0,0,0},{8,0,0,0},{4,4,0,0}}));
}

void deplacementDroit_test(){
    CHECK(deplacementDroit({{2,2,0,2},{0,8,4,4},{8,0,4,4},{4,4,0,8}}) == ({{0,0,2,4},{0,0,8,8},{0,0,8,8},{0,0,8,8}}));
    CHECK(deplacementDroit({{2,256,256,128},{2,0,0,0},{4,4,0,0},{4,2,2,0}}) == ({{0,2,512,128},{0,0,0,2},{0,0,0,8},{0,0,0,4}}));
}

void deplacementHaut_test(){
    CHECK(deplacementHaut({{8,4,4,2},{0,4,4,0},{4,0,8,2},{4,8,0,2}}) == ({{8,8,8,4},{8,8,8,2},{0,0,0,0},{0,0,0,0}}));
    CHECK(deplacementHaut({{0,0,0,128},{2,0,0,256},{2,4,0,256},{4,4,2,2}}) == ({{4,8,2,128},{4,0,0,512},{0,0,0,2},{0,0,0,0}}));
        }      
void deplacementBas_test(){
    CHECK(deplacementBas({{4,8,0,2},{4,0,8,2},{0,4,4,0},{8,4,4,2}}) == ({{0,0,0,0},{0,0,0,0},{8,8,8,2},{8,8,8,4}}));
    CHECK(deplacementBas({{2,2,4,4},{256,0,4,2},{256,0,0,2},{128,0,0,0}}) == ({{0,0,0,0},{2,0,0,0},{512,0,0,4},{128,2,8,4}}));
}

void deplacement_test(){
    CHECK(deplacement({{2,4,8,0},{2,4,8,0},{2,4,8,0},{2,4,8,0}},2) == ({{2,4,8,0},{2,4,8,0},{2,4,8,0},{2,4,8,0}}));
}

void dessine_test(){
    CHECK(dessine({{128,256,256,2},{0,0,0,2},{0,0,4,4},{0,2,2,4}}) == "*************************\n\e[37m*\e[34m 128 *\e[32m 256 *\e[32m 256 *\e[31m  2  *\n*     *     *     *\e[33m  2  *\n*     *     *\e[35m  4  *\e[35m  4  *\n*     *\e[33m  2  *\e[33m  2  *\e[35m  4  \e[37m*\n**************************\n");
    CHECK(dessine({{128,512,2,0},{2,0,0,0},{8,0,0,0},{4,4,0,0}})  == "*************************\n\e[37m*\e[34m 128 *\e[33m 512 *\e[33m  2  *     *\n*\e[33m  2  *     *     *     *\n*\e[34m  8  *     *     *     *\n*\e[35m  4  *\e[35m  4  *     *     \e[37m*\n**************************\n");
}
void estTermine_test(){
    CHECK(estTermine({{2,4,2,4},{8,2,8,2},{2,4,2,4},{8,2,8,2}}) == true);
    CHECK(estTermine({{2,0,0,0},{2,0,0,0},{2,0,0,0},{2,0,0,0}}) == false);
}

void estGagnant_test(){
    CHECK(estGagnant({{2048,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}) == true);
    CHECK(estGagnant({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,2048}}) == true);
    CHECK(estGagnant({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}) == false);
}

int main(){
    plateauVide_test();
    deplacementGauche_test();
    deplacementDroit_test();
    deplacementHaut_test();
    deplacementBas_test();
    deplacement_test();
    dessine_test();
    estTermine_test();
    estGagnant_test();
    return 0;
}

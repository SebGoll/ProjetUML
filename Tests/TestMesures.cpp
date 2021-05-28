#include "../Objets/Mesure.h"
#include <iostream>
#include <time.h>
#include <assert.h>
#include <string>

Mesure *testConstrVide();

Mesure *testConstrString();

Mesure *testConstrtm();

void testAffichage(Mesure *ptrM);

int main() {
    Mesure *mainMesure;
    Mesure *mesureVide;
    Mesure *mesureDatetm;

    //Tests de construction
    mainMesure = testConstrString();
    mesureVide = testConstrVide();
    mesureDatetm = testConstrtm();

    //Tests d'affichage et de valeurs correpondantes à la construction
    testAffichage(mainMesure);
    testAffichage(mesureVide);
    testAffichage(mesureDatetm);

    //Modifications des paramètres simples


    //Tests de destruction des capteurs



    return 0;
}

Mesure *testConstrVide() {
    Mesure *ptrM = new Mesure();
    assert(ptrM != nullptr);
    cout << "Creation d'une nouvelle mesure avec le constructeur par defaut" << endl;
    return ptrM;
}

Mesure *testConstrString() {
    Mesure *ptrM = new Mesure("2020-02-18 19:43:25", 49.75, 72.5, 40.35, 46.58);
    assert(ptrM != nullptr);
    cout << "Creation d'une nouvelle mesure avec date en string" << endl;
    return ptrM;
}

Mesure *testConstrtm() {
    time_t t = time(NULL);
    tm t2 = *localtime(&t);
    Mesure *ptrM = new Mesure(t2, 49.75, 72.5, 40.35, 46.58);
    assert(ptrM != nullptr);
    cout << "Creation d'une nouvelle mesure avec date tm" << endl;
    return ptrM;
}

void testAffichage(Mesure *ptrM){
    cout<<*ptrM<<endl;

}
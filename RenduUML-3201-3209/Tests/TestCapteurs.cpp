
#include <iostream>
#include <list>
#include "../Objets/Capteur.h"
#include "../Objets/Mesure.h"
#include <assert.h>
#include "../Objets/UtilisateurPrive.h"
using namespace std;

Capteur *testCapteurConstr2();

Capteur *testCapteurConstrVide();

void testValParam(Capteur *ptrC);

void testDestructeur(Capteur *ptrC);

void testModificationCapteur(Capteur *ptrC);

int main() {
    Capteur *mainCapteur;
    Capteur *captConstrVide;

    //Tests de construction
    captConstrVide = testCapteurConstrVide();
    mainCapteur = testCapteurConstr2();

    //Tests d'affichage et de valeurs correpondantes à la construction
    testValParam(mainCapteur);
    testValParam(captConstrVide);

    //Modifications des paramètres simples
    testModificationCapteur(mainCapteur);
    testValParam(mainCapteur);

    list <Mesure*> lm;
    for (int i = 0; i < 10; ++i) {
        string date = to_string(2000 + i);
        date.append("-01-01 12:00:00");
        lm.push_back(new Mesure(date, i * 10, i * 10, i * 10, i * 10));

    }





    //Tests de destruction des capteurs
    testDestructeur(mainCapteur);
    testDestructeur(captConstrVide);


    return 0;
}

Capteur *testCapteurConstrVide() {
    Capteur *ptrC = new Capteur();
    assert(ptrC != nullptr);
    cout << "Creation d'un nouveau capteur avec le constructeur par defaut" << endl;
    return ptrC;
}

Capteur *testCapteurConstr2() {
    Capteur *ptrC = new Capteur(1, 0.9, 46.8);
    assert(ptrC != nullptr);
    cout << "Creation d'un nouveau capteur avec le constructeur numero 2" << endl;
    return ptrC;
}

void testValParam(Capteur *ptrC) {

    cout << *ptrC << endl;

}

void testDestructeur(Capteur *ptrC) {
    delete ptrC;
    cout << "Destruction du capteur" << endl;
}

void testModificationCapteur(Capteur *ptrC) {
    ptrC->setId(100);
    ptrC->setLatitude(100.0);
    ptrC->setLongitude(100.0);
    ptrC->setFiable(false);
    cout << "Valeurs modifies" << endl;
}

void testAjoutMesuresParList(Capteur *ptrC, Mesure **) {

    cout << "Valeurs modifies" << endl;
}




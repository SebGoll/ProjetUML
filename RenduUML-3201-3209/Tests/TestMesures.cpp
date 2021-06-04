#include "../Objets/Mesure.h"
#include <iostream>
#include <time.h>
#include <assert.h>
#include <string>

Mesure *testConstrVide();

Mesure *testConstrString();

Mesure *testConstrtm();

void testAffichage(Mesure *ptrM);

void testDestructionMesure(Mesure *ptrM);

void testModifParam(Mesure *ptrM);

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
    testModifParam(mainMesure);
    testAffichage(mainMesure);

    //Tests de destruction des mesures
    testDestructionMesure(mainMesure);
    testDestructionMesure(mesureDatetm);
    testDestructionMesure(mesureVide);


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

void testAffichage(Mesure *ptrM) {
    cout << *ptrM << endl;

}

void testDestructionMesure(Mesure *ptrM) {
    delete ptrM;
    cout << "Destruction d'une mesure" << endl;
}

void testModifParam(Mesure *ptrM) {
    ptrM->setO3(100);
    ptrM->setNo2(100);
    ptrM->setPm10(100);
    ptrM->setPm10(100);
    time_t t = time(NULL);
    tm t2 = *localtime(&t);
    string dateString = "1919-05-30 14:35:25";
    t2.tm_year = stoi(dateString.substr(0, 4)) - 1900;
    t2.tm_mon = stoi(dateString.substr(5, 2)) - 1;
    t2.tm_mday = stoi(dateString.substr(8, 2));
    t2.tm_hour = stoi(dateString.substr(11, 2));
    t2.tm_min = stoi(dateString.substr(14, 2));
    t2.tm_sec = stoi(dateString.substr(17, 2));
    ptrM->setDate(t2);
}
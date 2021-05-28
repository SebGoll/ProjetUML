
#include <iostream>
#include "Capteur.h"
#include "Mesure.h"
#include <assert.h>
#include "UtilisateurPrive.h"

void testCapteurConstr2(Capteur* ptrC);
void testCapteurConstrVide(Capteur * ptrC);
void testValParam(Capteur* ptrC);

int main(){
    Capteur* mainCapteur;
    Capteur* captConstrVide;
    testCapteurConstrVide(captConstrVide);
    testCapteurConstr2(mainCapteur);
    testValParam(mainCapteur);
//    testValParam(captConstrVide);


    return 0;
}

void testCapteurConstrVide(Capteur * ptrC){
    ptrC = new Capteur();
    assert(ptrC!= nullptr);
    cout<<"Creation d'un nouveau capteur avec le constructeur par defaut"<<endl;
}

void testCapteurConstr2(Capteur* ptrC){
    ptrC = new Capteur(1,0.9,46.8);
    assert(ptrC!= nullptr);
    cout<<"Creation d'un nouveau capteur avec le constructeur numero 2"<<endl;
}

void testValParam(Capteur* ptrC){

    cout<<"\nLes valeurs des attributs du capteur sont les suivants:"<<endl;
    cout<<"Id:"<<ptrC->getId()<<"\n";
    cout<<"Latitude:"<<ptrC->getLatitude()<<"\n";
    cout<<"Longitude:"<<ptrC->getLongitude()<<"\n";
    cout<<"Fiable:"<<ptrC->isFiable()<<"\n";
//    cout<<"Proprietaire:"<<ptrC->getProprietaire()<<"\n";
    cout<<"Mesures:"<<&ptrC->getMesures()<<"\n";
    cout<<endl;

}




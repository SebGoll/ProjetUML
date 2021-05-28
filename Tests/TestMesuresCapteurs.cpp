
#include <iostream>
#include "../Objets/Capteur.h"
#include "../Objets/Mesure.h"
#include <assert.h>
#include "../Objets/UtilisateurPrive.h"

Capteur* testCapteurConstr2();
Capteur* testCapteurConstrVide();
void testValParam(Capteur* ptrC);

int main(){
    Capteur* mainCapteur;
    Capteur* captConstrVide;
    captConstrVide = testCapteurConstrVide();
    mainCapteur = testCapteurConstr2();
    testValParam(mainCapteur);
//    testValParam(captConstrVide);


    return 0;
}

Capteur* testCapteurConstrVide(){
    Capteur* ptrC = new Capteur();
    assert(ptrC!= nullptr);
    cout<<"Creation d'un nouveau capteur avec le constructeur par defaut"<<endl;
    return ptrC;
}

Capteur* testCapteurConstr2(){
    Capteur * ptrC = new Capteur(1,0.9,46.8);
    assert(ptrC!= nullptr);
    cout<<"Creation d'un nouveau capteur avec le constructeur numero 2"<<endl;
    return ptrC;
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




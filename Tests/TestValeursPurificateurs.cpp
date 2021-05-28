#include <iostream>
#include "../Objets/Purificateur.h"
#include "../Objets/FournisseurPurificateur.h"
#include <assert.h>
#include <ctime>

FournisseurPurificateur* testCreaFourniPuriVide(); //Test du constructeur fournisseur
Purificateur* testCreaPuriVide(); //Test du constructeur vide
Purificateur* testCreaPuriConstr2(); //Test du constructeur 2 (date=string)
Purificateur* testCreaPuriConstr1(); //Test du constructeur 1 (date=*tm)

int main(){
    FournisseurPurificateur* fourniVide = testCreaFourniPuriVide();
    Purificateur* PuriVide = testCreaPuriVide();
    Purificateur* PuriConstr1 = testCreaPuriConstr1();
    Purificateur* PuriConstr2 = testCreaPuriConstr2();
    cout<<*PuriConstr1<<endl;
    return 0;
}

Purificateur* testCreaPuriVide(){
    Purificateur* ptrP = new Purificateur();
    assert(ptrP!= nullptr);
    cout<<"Creation d'un purificateur avec un constructeur vide par defaut"<<endl;
    return ptrP;
}

Purificateur* testCreaPuriConstr1(){
    time_t timestamp = time( NULL );
    struct tm * now = localtime( & timestamp );
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    Purificateur* ptrP = new Purificateur(1,50,100,*fourni,now,now);
    cout<<"Creation d'un purificateur avec un constructeur avc le date est un *tm"<<endl;
    return ptrP;
}

Purificateur* testCreaPuriConstr2(){
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    Purificateur* ptrP = new Purificateur(1,50,100,*fourni,"2000 02 23 18 04 25","2021 08 24 18 24 18");
    cout<<"Creation d'un purificateur avec un constructeur avc la date est un string"<<endl;
    return ptrP;
}

FournisseurPurificateur* testCreaFourniPuriVide(){
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    return fourni;
}


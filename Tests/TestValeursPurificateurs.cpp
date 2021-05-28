#include <iostream>
#include "../Objets/Purificateur.h"
#include "../Objets/FournisseurPurificateur.h"
#include <assert.h>
#include <ctime>

FournisseurPurificateur* testCreaFourniPuriVide(); //Test du constructeur fournisseur vide
FournisseurPurificateur* testCreaFourniPuriConstr(); //Test du constructeur fournisseur non vide
Purificateur* testCreaPuriVide(); //Test du constructeur vide
Purificateur* testCreaPuriConstr2(); //Test du constructeur 2 (date=string)
Purificateur* testCreaPuriConstr1(); //Test du constructeur 1 (date=*tm)

int main(){

    //Test des constructeurs de FournisseurPurificateur
    FournisseurPurificateur* fourniVide = testCreaFourniPuriVide();
    cout<<*fourniVide<<"\n"<<endl;
    FournisseurPurificateur* fourniConstr = testCreaFourniPuriConstr();
    cout<<*fourniConstr<<"\n"<<endl;

    //Test des constructeurs de Purificateur
    Purificateur* puriVide = testCreaPuriVide();
    cout<<*puriVide<<"\n"<<endl;
    Purificateur* puriConstr1 = testCreaPuriConstr1();
    cout<<*puriConstr1<<"\n"<<endl;
    Purificateur* puriConstr2 = testCreaPuriConstr2();
    cout<<*puriConstr2<<"\n"<<endl;


    return 0;
}

Purificateur* testCreaPuriVide(){
    Purificateur* ptrP = new Purificateur();
    assert(ptrP!= nullptr);
    cout<<"Test: Creation d'un purificateur avec un constructeur vide par defaut"<<endl;

    return ptrP;
}

Purificateur* testCreaPuriConstr1(){
    time_t timestamp = time( NULL );
    struct tm now = *localtime( & timestamp );
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    assert(fourni!= nullptr);
    Purificateur* ptrP = new Purificateur(1,50,100,*fourni,now,now);
    assert(ptrP!= nullptr);
    cout<<"Test: Creation d'un purificateur avec un constructeur avc le date est un *tm"<<endl;
    return ptrP;
}

Purificateur* testCreaPuriConstr2(){
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    assert(fourni!= nullptr);
    Purificateur* ptrP = new Purificateur(1,50,100,*fourni,"2000 02 23 18 04 25","2021 08 24 18 24 18");
    assert(ptrP!= nullptr);
    cout<<"Test: Creation d'un purificateur avec un constructeur avc la date est un string"<<endl;
    return ptrP;
}

FournisseurPurificateur* testCreaFourniPuriVide(){
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    assert(fourni!= nullptr);
    cout<<"Test: Creation d'un fournisseur avec un constructeur vide de defaut"<<endl;
    return fourni;
}

FournisseurPurificateur* testCreaFourniPuriConstr(){
    FournisseurPurificateur * fourni = new FournisseurPurificateur(25,"Louille","LeRaton","megalux@insa-lyon.fr","boulghour987678","INSA");
    assert(fourni!= nullptr);
    cout<<"Test: Creation d'un fournisseur avec un constructeur avec des donnees"<<endl;
    return fourni;
}

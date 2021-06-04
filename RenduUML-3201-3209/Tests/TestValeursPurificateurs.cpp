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
void testGetValeursFournisseur(FournisseurPurificateur* f); //Test des getters du Fournisseur
FournisseurPurificateur* testSetValeursFournisseur(FournisseurPurificateur* f); //Test des setters du Fournisseur
void testGetValeurs(Purificateur* p); //Test des getters du Purificateur
Purificateur* testSetValeursPuri(Purificateur* p); //Test des setters du Purificateur


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

    //Test des setters-getters de FournisseurPurificateur
    testGetValeursFournisseur(fourniConstr);
    FournisseurPurificateur* fourniModif = testSetValeursFournisseur(fourniConstr);
    cout<<*fourniModif<<"\n"<<endl;

    //Test des setters-getters de Purificateur
    testGetValeurs(puriConstr2);
    Purificateur* puriModif = testSetValeursPuri(puriConstr2);
    cout<<*puriModif<<"\n"<<endl;

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
    FournisseurPurificateur * fourni = new FournisseurPurificateur(25,"Louille","Pain","megalux@insa-lyon.fr","boulghour987678","INSA");
    assert(fourni!= nullptr);
    cout<<"Test: Creation d'un fournisseur avec un constructeur avec des donnees"<<endl;
    return fourni;
}

void testGetValeursFournisseur(FournisseurPurificateur* f){
    cout<<"Test: Get les attributs d'un fournisseur"<<endl;
    cout<<"Id:"<<f->getId()<<" - Nom:"<<f->getNom()<<" - Prenom:"<<f->getPrenom()<<" - Mail:"<<f->getMail()<<" - Mdp:"<<f->getMdp()<<" - Nom Entreprise:"<<f->getNomEntreprise()<<"\n"<<endl;
}

FournisseurPurificateur* testSetValeursFournisseur(FournisseurPurificateur* f){
    cout<<"Test: Set les attributs d'un fournisseur"<<endl;
    f->setId(40); f->setNom("Pommier"); f->setPrenom("Roberto"); f->setMail("roberrrto@insa-lyon.fr"); f->setMdp("tJisLJDz486"); f->setNomEntreprise("InsaSuperior");
    return f;
}

void testGetValeurs(Purificateur* p){
    cout<<"Test: Get les attributs d'un purificateur"<<endl;
    cout<<"Id:"<<p->getId()<<" - Longitude:"<<p->getLongitude()<<" - Latitude:"<<p->getLatitude()<<" - Proprietaire:"<<p->getProprietaire().getNomEntreprise();
    tm debut = p->getDateDebut();
    tm fin = p->getDateFin();
    cout<<" - DateDebut:"<<asctime(&debut)<<" - DateFin:"<<asctime(&fin)<<"\n"<<endl;
}

Purificateur* testSetValeursPuri(Purificateur* p) {
    cout << "Test: Set les attributs d'un purificateur" << endl;
    FournisseurPurificateur *fourni = new FournisseurPurificateur();
    fourni->setNomEntreprise("ENSA");
    p->setId(842);
    p->setLongitude(10);
    p->setLatitude(20);
    p->setProprietaire(*fourni);
    return p;
}
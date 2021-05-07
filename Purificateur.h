//Interface de la classe <Purificateur> (Purificateur.h)

#ifndef PROJETUML_PURIFICATEUR_H
#define PROJETUML_PURIFICATEUR_H
#include "FournisseurPurificateur.h"
#include <iostream>
#include <ctime>
using namespace std;

class Purificateur {

public:

    //Constructeurs
    Purificateur();
    Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, tm* &leDebut, tm* &laFin);
    Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, const string &leDebut, const string &laFin);

    //Destructeur
    virtual ~Purificateur();


private:
    //Attributs privés
    long id;
    float longitude;
    float latitude;
    FournisseurPurificateur proprietaire;
    tm* dateDebut;
    tm* dateFin;

};


#endif //PROJETUML_PURIFICATEUR_H

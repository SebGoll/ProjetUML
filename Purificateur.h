#ifndef PROJETUML_PURIFICATEUR_H
#define PROJETUML_PURIFICATEUR_H
#include "FournisseurPurificateur.h"
#include <iostream>
#include <ctime>
using namespace std;

class Purificateur {

public:
    //Méthodes publiques

    long getId() const;

    float getLongitude() const;

    void setLongitude(float longitude);

    float getLatitude() const;

    void setLatitude(float latitude);

    const FournisseurPurificateur &getProprietaire() const;

    void setProprietaire(const FournisseurPurificateur &proprietaire);

    void setId(long id);

    //Constructeurs
    Purificateur();
    Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, tm* &leDebut, tm* &laFin);

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

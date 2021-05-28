//Interface de la classe <Purificateur> (Purificateur.h)

#ifndef PROJETUML_PURIFICATEUR_H
#define PROJETUML_PURIFICATEUR_H
#include "FournisseurPurificateur.h"
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Purificateur {

public:

    tm getDateDebut() const;
    void setDateDebut(tm dateDebut);

    tm getDateFin() const;
    void setDateFin(tm dateFin);

    long getId() const;
    void setId(long id);

    float getLongitude() const;
    void setLongitude(float longitude);

    float getLatitude() const;
    void setLatitude(float latitude);

    const FournisseurPurificateur &getProprietaire() const;
    void setProprietaire(const FournisseurPurificateur &proprietaire);

    //Surcharge d'opérateurs
    friend ostream & operator << (ostream & flux, const Purificateur & c);

    //Constructeurs
    Purificateur();
    Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, tm &leDebut, tm &laFin);
    Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, const string &leDebut, const string &laFin);

    //Destructeur
    virtual ~Purificateur();


private:
    //Attributs privés
    long id;

private:
    float longitude;
    float latitude;
    FournisseurPurificateur proprietaire;
    tm dateDebut;
    tm dateFin;

};


#endif //PROJETUML_PURIFICATEUR_H

//Interface de la classe <Capteur> (fichier Capteur.h)
#ifndef PROJETUML_CAPTEUR_H
#define PROJETUML_CAPTEUR_H

//Interfaces itilisées
#include <list>
#include "Mesure.h"
#include "UtilisateurPrive.h"
#include <iostream>
#include <string>
using namespace std;
//Constantes
//Types

//-------------
//Role de la classe <Capteur>
//Cette classe represente l'objet Capteur

class Capteur {
    //PUBLIC
public:

    //Méthodes publiques
    void ajouterMesure(Mesure *m);

    UtilisateurPrive getProprietaire() const;

    void setProprietaire(UtilisateurPrive proprietaire);

    bool isFiable() const;

    void setFiable(bool fiable);

    unsigned long getId() const;

    void setId(unsigned long id);

    float getLatitude() const;

    void setLatitude(float latitude);

    float getLongitude() const;


    void setLongitude(float longitude);

    const list<Mesure *> &getMesures() const;

    void setMesures(const list<Mesure *> &mesures);

    //Surcharge d'opérateurs
    friend ostream & operator << (ostream & flux, const Capteur & c);

    //Constructeurs destructeurs
    Capteur();

    Capteur(unsigned long id, float latitude, float longitude);

    virtual ~Capteur();


    //PRIVE
protected:
    //Méthodes protégées

    //Attributs protégés
    unsigned long id;
    float latitude;
    float longitude;
    UtilisateurPrive proprietaire;
    bool fiable;
    list<Mesure*> mesures;
};


#endif //PROJETUML_CAPTEUR_H

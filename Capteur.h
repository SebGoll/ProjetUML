//Interface de la classe <Capteur> (fichier Capteur.h)
#ifndef PROJETUML_CAPTEUR_H
#define PROJETUML_CAPTEUR_H

//Interfaces itilisées
#include <list>
using namespace std;
//Constantes
//Types
typedef int UtilisateurPrive;
typedef int Mesure;

//-------------
//Role de la classe <Capteur>
//Cette classe represente l'objet Capteur

class Capteur {
    //PUBLIC
public:

    Capteur();

    Capteur(long id, float latitude, float longitude);


    //PRIVE
protected:
    //Méthodes protégées

    //Attributs protégés
    unsigned long id;
    float latitude;
    float longitude;
    UtilisateurPrive proprietaire;
    bool fiable;
    list<Mesure> mesures;
};


#endif //PROJETUML_CAPTEUR_H

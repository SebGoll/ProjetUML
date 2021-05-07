//Interface de la classe <Utilisateur> (Utilisateur.h)

#ifndef PROJETUML_UTILISATEUR_H
#define PROJETUML_UTILISATEUR_H

#include <iostream>
#include <string>
using namespace std;

class Utilisateur {

public:

    //Constructeur(s)
    Utilisateur();
    Utilisateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);

    //Destructeur
    virtual ~Utilisateur();


private:
    //Attributs privés
    unsigned long id;
    string nom;
    string prenom;
    string mail;
    string mdp;

};


#endif //PROJETUML_UTILISATEUR_H

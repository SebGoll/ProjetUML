#include "Utilisateur.h"

//Surcharge d'opérateurs
ostream &operator<<(ostream &flux, const Utilisateur &u) {
    flux <<  "Utilisateur n°" << u.id<<"\nNom="<<u.nom<<"\nPrenom="<<u.prenom<<"\nMail="<<u.mail<<"\nMot de passe="<<u.mdp;
    return flux;
}

/*Constructeurs*/
Utilisateur::Utilisateur() {}

Utilisateur::Utilisateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp){
    this->id=unId;
    this->nom=unNom;
    this->prenom=unPrenom;
    this->mail=unMail;
    this->mdp=unMdp;
}

/*Destructeur*/
Utilisateur::~Utilisateur() {

}

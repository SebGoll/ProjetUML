#include "Utilisateur.h"

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

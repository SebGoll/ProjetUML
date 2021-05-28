#include "Utilisateur.h"

//Surcharge d'opérateurs
ostream &operator<<(ostream &flux, const Utilisateur &u) {
    flux <<  "Utilisateur numéro=" << u.id<<"\nNom="<<u.nom<<"\nPrenom="<<u.prenom<<"\nMail="<<u.mail<<"\nMot de passe="<<u.mdp;
    return flux;
}

/*Constructeurs*/
Utilisateur::Utilisateur() {
    this->id=-1;
    this->nom="inconnu";
    this->prenom="inconnu";
    this->mail="inconnu";
    this->mdp="inconnu";
}

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

/*Get Set*/

unsigned long Utilisateur::getId() const {
    return id;
}

void Utilisateur::setId(unsigned long id) {
    Utilisateur::id = id;
}

const string &Utilisateur::getNom() const {
    return nom;
}

void Utilisateur::setNom(const string &nom) {
    Utilisateur::nom = nom;
}

const string &Utilisateur::getPrenom() const {
    return prenom;
}

void Utilisateur::setPrenom(const string &prenom) {
    Utilisateur::prenom = prenom;
}

const string &Utilisateur::getMail() const {
    return mail;
}

void Utilisateur::setMail(const string &mail) {
    Utilisateur::mail = mail;
}

const string &Utilisateur::getMdp() const {
    return mdp;
}

void Utilisateur::setMdp(const string &mdp) {
    Utilisateur::mdp = mdp;
}

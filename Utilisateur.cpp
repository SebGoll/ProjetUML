#include "Utilisateur.h"

/*Getters/Setters*/

long Utilisateur::getId() const {
    return id;
}

void Utilisateur::setId(long id) {
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

/*Constructeurs*/
Utilisateur::Utilisateur() {}

Utilisateur::Utilisateur(const long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp){
    id=unId;
    nom=unNom;
    prenom=unPrenom;
    mail=unMail;
    mdp=unMdp;
}

/*Destructeur*/
Utilisateur::~Utilisateur() {

}

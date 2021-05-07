//
// Created by Seb on 07/05/2021.
//

#include "Capteur.h"

Capteur::Capteur(){
    this->fiable=true;
}

Capteur::~Capteur() {

}

Capteur::Capteur(unsigned long id, float latitude, float longitude) : id(id), latitude(latitude), longitude(longitude) {
    this->fiable=true;
}

ostream &operator<<(ostream &flux, const Capteur &c) {
    string s = "Capteur n°";
    flux <<  "Capteur n°" << c.id<<"\tLat="<<c.latitude<<"\tLong="<<c.longitude;
    return flux;
}

void Capteur::ajouterMesure(Mesure *m) {
    this->mesures.push_back(m);
}

UtilisateurPrive Capteur::getProprietaire() const {
    return proprietaire;
}

void Capteur::setProprietaire(UtilisateurPrive proprietaire) {
    Capteur::proprietaire = proprietaire;
}

bool Capteur::isFiable() const {
    return fiable;
}

void Capteur::setFiable(bool fiable) {
    Capteur::fiable = fiable;
}


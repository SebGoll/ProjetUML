//
// Created by Seb on 07/05/2021.
//

#include "Capteur.h"

Capteur::Capteur(){

}

Capteur::~Capteur() {

}

Capteur::Capteur(unsigned long id, float latitude, float longitude) : id(id), latitude(latitude), longitude(longitude) {

}

ostream &operator<<(ostream &flux, const Capteur &c) {
    string s = "Capteur n°";
    flux <<  "Capteur n°" << c.id<<"\tLat="<<c.latitude<<"\tLong="<<c.longitude<<"\n";
}

void Capteur::ajouterMesure(Mesure *m) {
    this->mesures.push_back(m);
}


//
// Created by Seb on 07/05/2021.
//

#include "Capteur.h"

Capteur::Capteur(){
    this->id=0;
    this->latitude=0.0;
    this->longitude=0.0;
    this->fiable=true;
}

Capteur::~Capteur() {

}

Capteur::Capteur(unsigned long id, float latitude, float longitude) : id(id), latitude(latitude), longitude(longitude) {
    this->fiable=true;
}

ostream &operator<<(ostream &flux, const Capteur &c) {

    flux <<  "Capteur numero " << c.getId()<<"\tLat="<<c.getLatitude()<<"\tLong="<<c.getLongitude()<<endl;
    if(c.isFiable()){
        flux<<"Ce capteur est fiable"<<endl;
    }else{
        flux<<"Ce capteur est non-fiable"<<endl;
    }
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

unsigned long Capteur::getId() const {
    return id;
}

void Capteur::setId(unsigned long id) {
    Capteur::id = id;
}

float Capteur::getLatitude() const {
    return latitude;
}

void Capteur::setLatitude(float latitude) {
    Capteur::latitude = latitude;
}

float Capteur::getLongitude() const {
    return longitude;
}

void Capteur::setLongitude(float longitude) {
    Capteur::longitude = longitude;
}

const list<Mesure *> &Capteur::getMesures() const {
    return mesures;
}

void Capteur::setMesures(const list<Mesure *> &mesures) {
    Capteur::mesures = mesures;
}


#include "Purificateur.h"

/*Getters/Setters*/
long Purificateur::getId() const {
    return id;
}

void Purificateur::setId(long id) {
    Purificateur::id = id;
}

float Purificateur::getLongitude() const {
    return longitude;
}

void Purificateur::setLongitude(float longitude) {
    Purificateur::longitude = longitude;
}

float Purificateur::getLatitude() const {
    return latitude;
}

void Purificateur::setLatitude(float latitude) {
    Purificateur::latitude = latitude;
}

const FournisseurPurificateur &Purificateur::getProprietaire() const {
    return proprietaire;
}

void Purificateur::setProprietaire(const FournisseurPurificateur &proprietaire) {
    Purificateur::proprietaire = proprietaire;
}

/*Constructeurs*/
Purificateur::Purificateur() {}

Purificateur::Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, tm* &leDebut, tm* &laFin){
    id= unId;
    longitude=unLong;
    latitude = unLa;
    proprietaire = unFournisseur;
    dateDebut= leDebut;
    dateFin = laFin;
}

/*Destructeur*/
Purificateur::~Purificateur() {

}

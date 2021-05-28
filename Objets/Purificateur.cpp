#include "Purificateur.h"
#include "FournisseurPurificateur.h"

//Purificateur n°XX, longitude:XX, latitude:XX, fournisseur:XX, dateDebut:XX, dateFin:XX

/*Constructeurs*/
Purificateur::Purificateur() {
    this->id= -1;
    this->longitude=0;
    this->latitude = 0;
    this->proprietaire = FournisseurPurificateur();
    time_t timestamp = time( NULL );
    struct tm now = *localtime( & timestamp );
    this->dateDebut = now;
    this->dateFin = now;
}

Purificateur::Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, tm &leDebut, tm &laFin){
    this->id= unId;
    this->longitude=unLong;
    this->latitude = unLa;
    this->proprietaire = unFournisseur;
    this->dateDebut = leDebut;
    this->dateFin = laFin;
}

Purificateur::Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, const string &leDebut, const string &laFin){
    this->id= unId;
    this->longitude=unLong;
    this->latitude = unLa;
    this->proprietaire = unFournisseur;

    time_t now = time(0);
    this->dateDebut = *(localtime(&now));
    this->dateFin = *(localtime(&now));

    //seul les informations modifiées ici seront correcte, impossible d'utiliser tm_wday, tm_yday, tm_isdst
    this->dateDebut.tm_year=stoi(leDebut.substr(0,4))-1900;
    this->dateDebut.tm_mon=stoi(leDebut.substr(5,2))-1;
    this->dateDebut.tm_mday=stoi(leDebut.substr(8,2));
    this->dateDebut.tm_hour=stoi(leDebut.substr(11,2));
    this->dateDebut.tm_min=stoi(leDebut.substr(14,2));
    this->dateDebut.tm_sec=stoi(leDebut.substr(17,2));

    this->dateFin.tm_year=stoi(laFin.substr(0,4))-1900;
    this->dateFin.tm_mon=stoi(laFin.substr(5,2))-1;
    this->dateFin.tm_mday=stoi(laFin.substr(8,2));
    this->dateFin.tm_hour=stoi(laFin.substr(11,2));
    this->dateFin.tm_min=stoi(laFin.substr(14,2));
    this->dateFin.tm_sec=stoi(laFin.substr(17,2));
}

/*Destructeur*/
Purificateur::~Purificateur() {

}

ostream &operator<<(ostream &flux, const Purificateur &p) {
    flux <<  "Purificateur num:"<< p.id<<"\nLat="<<p.latitude<<"\nLong="<<p.longitude<<"\nFournisseur="<<p.proprietaire.getNomEntreprise()
    <<"\nDebut="<<asctime(&p.dateDebut)<<"Fin="<<asctime(&p.dateFin);
    return flux;
}

/*Get Set*/
tm Purificateur::getDateDebut() const {
    return dateDebut;
}

void Purificateur::setDateDebut(tm dateDebut) {
    Purificateur::dateDebut = dateDebut;
}

tm Purificateur::getDateFin() const {
    return dateFin;
}

void Purificateur::setDateFin(tm dateFin) {
    Purificateur::dateFin = dateFin;
}

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

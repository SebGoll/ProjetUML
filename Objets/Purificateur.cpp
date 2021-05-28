#include "Purificateur.h"

/*Constructeurs*/
Purificateur::Purificateur() {}

Purificateur::Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, tm* &leDebut, tm* &laFin){
    this->id= unId;
    this->longitude=unLong;
    this->latitude = unLa;
    this->proprietaire = unFournisseur;
    this->dateDebut= leDebut;
    this->dateFin = laFin;
}

Purificateur::Purificateur(const long &unId,const float &unLong,const float &unLa, const FournisseurPurificateur &unFournisseur, const string &leDebut, const string &laFin){
    this->id= unId;
    this->longitude=unLong;
    this->latitude = unLa;
    this->proprietaire = unFournisseur;

    time_t now = time(0);
    this->dateDebut = localtime(&now);
    this->dateFin = localtime(&now);

    //seul les informations modifiées ici seront correcte, impossible d'utiliser tm_wday, tm_yday, tm_isdst
    this->dateDebut->tm_year=stoi(leDebut.substr(0,4))-1900;
    this->dateDebut->tm_mon=stoi(leDebut.substr(5,2))-1;
    this->dateDebut->tm_mday=stoi(leDebut.substr(8,2));
    this->dateDebut->tm_hour=stoi(leDebut.substr(11,2));
    this->dateDebut->tm_min=stoi(leDebut.substr(14,2));
    this->dateDebut->tm_hour=stoi(leDebut.substr(17,2));

    this->dateFin->tm_year=stoi(laFin.substr(0,4))-1900;
    this->dateFin->tm_mon=stoi(laFin.substr(5,2))-1;
    this->dateFin->tm_mday=stoi(laFin.substr(8,2));
    this->dateFin->tm_hour=stoi(laFin.substr(11,2));
    this->dateFin->tm_min=stoi(laFin.substr(14,2));
    this->dateFin->tm_hour=stoi(laFin.substr(17,2));
}

/*Destructeur*/
Purificateur::~Purificateur() {

}

ostream &operator<<(ostream &flux, const Purificateur &p) {
    flux <<  "Purificateur n°" << p.id<<"\tLat="<<p.latitude<<"\tLong="<<p.longitude;
    return flux;
}
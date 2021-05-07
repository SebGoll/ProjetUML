#include "FournisseurPurificateur.h"

/*Getters/Setters*/
const string &FournisseurPurificateur::getNomEntreprise() const {
    return nomEntreprise;
}

void FournisseurPurificateur::setNomEntreprise(const string &nomEntreprise) {
    FournisseurPurificateur::nomEntreprise = nomEntreprise;
}

/*Constructeurs*/
FournisseurPurificateur::FournisseurPurificateur() {}

FournisseurPurificateur::FournisseurPurificateur(const long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp, const string &unNomEntreprise)
    : Utilisateur(unId,unNom,unPrenom,unMail,unMdp), nomEntreprise(unNomEntreprise){}

/*Destructeur*/
FournisseurPurificateur::~FournisseurPurificateur() {
}

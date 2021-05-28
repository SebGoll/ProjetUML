#include "FournisseurPurificateur.h"

/*Constructeurs*/
FournisseurPurificateur::FournisseurPurificateur() {
    this->nomEntreprise="inconnu";
}

FournisseurPurificateur::FournisseurPurificateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp, const string &unNomEntreprise)
    : Utilisateur(unId,unNom,unPrenom,unMail,unMdp), nomEntreprise(unNomEntreprise){}

/*Destructeur*/
FournisseurPurificateur::~FournisseurPurificateur() {
}

/*Getters/Setters*/

const string &FournisseurPurificateur::getNomEntreprise() const {
    return nomEntreprise;
}

void FournisseurPurificateur::setNomEntreprise(const string &nomEntreprise) {
    FournisseurPurificateur::nomEntreprise = nomEntreprise;
}

/*Surcharge*/
ostream &operator<<(ostream &flux, const FournisseurPurificateur &f) {
    flux <<  "Utilisateur num:" << f.id<<"\nType: Fournisseur"<<"\nNom="<<f.nom<<"\nPrenom="<<f.prenom<<"\nMail="<<f.mail<<"\nMot de passe="<<f.mdp<< "\nNom Entreprise: " <<f.nomEntreprise;
    return flux;
}
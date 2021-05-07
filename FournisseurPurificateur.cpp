#include "FournisseurPurificateur.h"

/*Constructeurs*/
FournisseurPurificateur::FournisseurPurificateur() {}

FournisseurPurificateur::FournisseurPurificateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp, const string &unNomEntreprise)
    : Utilisateur(unId,unNom,unPrenom,unMail,unMdp), nomEntreprise(unNomEntreprise){}

/*Destructeur*/
FournisseurPurificateur::~FournisseurPurificateur() {
}

#include "UtilisateurPrive.h"

/*Constructeurs*/
UtilisateurPrive::UtilisateurPrive() {}

UtilisateurPrive::UtilisateurPrive(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp)
        : Utilisateur(unId, unNom, unPrenom,unMail,unMdp) {}

/*Destructeur*/
UtilisateurPrive::~UtilisateurPrive() {

}

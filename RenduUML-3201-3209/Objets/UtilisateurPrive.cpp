/**
 *  Objet UtilisateurPrive heritant de Utilisateur
 *  @file UtilisateurPrive.cpp
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna
 */
#include "UtilisateurPrive.h"

/*Constructeurs*/
UtilisateurPrive::UtilisateurPrive() {}

UtilisateurPrive::UtilisateurPrive(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp)
        : Utilisateur(unId, unNom, unPrenom,unMail,unMdp) {}

/*Destructeur*/
UtilisateurPrive::~UtilisateurPrive() {

}

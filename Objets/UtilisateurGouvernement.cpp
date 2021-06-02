/**
 *  Objet UtilisateurGouvernement heritant de Utilisateur
 *  @file UtilisateurGouvernement.cpp
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna
 */
#include "UtilisateurGouvernement.h"

/*Constructeurs*/
UtilisateurGouvernement::UtilisateurGouvernement() {}

UtilisateurGouvernement::UtilisateurGouvernement(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp)
    : Utilisateur(unId, unNom, unPrenom,unMail,unMdp) {}

/*Destructeur*/
UtilisateurGouvernement::~UtilisateurGouvernement() {

}

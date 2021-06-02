/**
 *  Interface de l'Objet UtilisateurPrive heritant de Utilisateur
 *  @file UtilisateurPrive.h
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna
 */
#ifndef PROJETUML_UTILISATEURPRIVE_H
#define PROJETUML_UTILISATEURPRIVE_H
#include <iostream>
#include <string>
#include "Utilisateur.h"
using namespace std;

class UtilisateurPrive: public Utilisateur {

public:
    //Constructeur(s)
    UtilisateurPrive();
    UtilisateurPrive(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);


    //Destructeur
    virtual ~UtilisateurPrive();

};


#endif //PROJETUML_UTILISATEURPRIVE_H

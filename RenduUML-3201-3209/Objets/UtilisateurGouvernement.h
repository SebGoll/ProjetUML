/**
 *  Interface de l'Objet UtilisateurGouvernement heritant de Utilisateur
 *  @file UtilisateurGouvernement.h
 *  @author ABHAY Annie, GOLL Sebastien, HASENFRATZ Louis, NGOV Sophanna
 */
#ifndef PROJETUML_UTILISATEURGOUVERNEMENT_H
#define PROJETUML_UTILISATEURGOUVERNEMENT_H
#include <iostream>
#include "Utilisateur.h"
using namespace std;

class UtilisateurGouvernement: public Utilisateur {

public:
    //Constructeur(s)
    UtilisateurGouvernement();
    UtilisateurGouvernement(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);


    //Destructeur
    virtual ~UtilisateurGouvernement();

};


#endif //PROJETUML_UTILISATEURGOUVERNEMENT_H

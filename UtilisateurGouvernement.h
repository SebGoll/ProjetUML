#ifndef PROJETUML_UTILISATEURGOUVERNEMENT_H
#define PROJETUML_UTILISATEURGOUVERNEMENT_H
#include <iostream>
#import "Utilisateur.h";
using namespace std;

class UtilisateurGouvernement: public Utilisateur {

public:
    //Constructeur(s)
    UtilisateurGouvernement();
    UtilisateurGouvernement(const long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);


    //Destructeur
    virtual ~UtilisateurGouvernement();

};


#endif //PROJETUML_UTILISATEURGOUVERNEMENT_H

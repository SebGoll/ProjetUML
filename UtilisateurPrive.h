#ifndef PROJETUML_UTILISATEURPRIVE_H
#define PROJETUML_UTILISATEURPRIVE_H
#include <iostream>
#import "Utilisateur.h"
using namespace std;

class UtilisateurPrive: public Utilisateur {

public:
    //Constructeur(s)
    UtilisateurPrive();
    UtilisateurPrive(const long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);


    //Destructeur
    virtual ~UtilisateurPrive();

};


#endif //PROJETUML_UTILISATEURPRIVE_H

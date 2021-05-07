//Interface de la classe <FournisseurPurificateur> (FournisseurPurificateur.h)

#ifndef PROJETUML_FOURNISSEURPURIFICATEUR_H
#define PROJETUML_FOURNISSEURPURIFICATEUR_H
#include <iostream>
#import "Utilisateur.h";
using namespace std;

class FournisseurPurificateur : public Utilisateur {

public:
    //Constructeur(s)
    FournisseurPurificateur();
    FournisseurPurificateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp, const string &unNomEntreprise);


    //Destructeur
    virtual ~FournisseurPurificateur();



private:
    //Attributs privés
    string nomEntreprise;


};


#endif //PROJETUML_FOURNISSEURPURIFICATEUR_H

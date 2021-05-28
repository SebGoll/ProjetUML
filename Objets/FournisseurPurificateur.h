//Interface de la classe <FournisseurPurificateur> (FournisseurPurificateur.h)

#ifndef PROJETUML_FOURNISSEURPURIFICATEUR_H
#define PROJETUML_FOURNISSEURPURIFICATEUR_H
#include <iostream>
#include "Utilisateur.h"
using namespace std;

class FournisseurPurificateur : public Utilisateur {

public:

    //Get/Set
    const string &getNomEntreprise() const;
    void setNomEntreprise(const string &nomEntreprise);


    //Constructeur(s)
    FournisseurPurificateur();
    FournisseurPurificateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp, const string &unNomEntreprise);


    //Destructeur
    virtual ~FournisseurPurificateur();

    //Surcharge
    friend ostream & operator << (ostream & flux, const FournisseurPurificateur &f);



protected:
    //Attributs privés
    string nomEntreprise;


};


#endif //PROJETUML_FOURNISSEURPURIFICATEUR_H

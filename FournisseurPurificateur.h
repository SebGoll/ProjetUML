#ifndef PROJETUML_FOURNISSEURPURIFICATEUR_H
#define PROJETUML_FOURNISSEURPURIFICATEUR_H
#include <iostream>
#import "Utilisateur.h";
using namespace std;

class FournisseurPurificateur : public Utilisateur {

public:
    //Méthodes publiques
    const string &getNomEntreprise() const;

    void setNomEntreprise(const string &nomEntreprise);

    //Constructeur(s)
    FournisseurPurificateur();
    FournisseurPurificateur(const long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp, const string &unNomEntreprise);


    //Destructeur
    virtual ~FournisseurPurificateur();



private:
    //Attributs privés
    string nomEntreprise;


};


#endif //PROJETUML_FOURNISSEURPURIFICATEUR_H

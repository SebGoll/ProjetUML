#ifndef PROJETUML_UTILISATEUR_H
#define PROJETUML_UTILISATEUR_H

#include <iostream>
#include <string>
using namespace std;

class Utilisateur {

public:
    //Méthodes publiques
    long getId() const;
    void setId(long id);
    const string &getNom() const;
    void setNom(const string &nom);
    const string &getPrenom() const;
    void setPrenom(const string &prenom);
    const string &getMail() const;
    void setMail(const string &mail);
    const string &getMdp() const;
    void setMdp(const string &mdp);

    //Constructeur(s)
    Utilisateur();
    Utilisateur(const long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);

    //Destructeur
    virtual ~Utilisateur();


private:
    //Attributs privés
    long id;
    string nom;
    string prenom;
    string mail;
    string mdp;

};


#endif //PROJETUML_UTILISATEUR_H

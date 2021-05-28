//Interface de la classe <Utilisateur> (Utilisateur.h)

#ifndef PROJETUML_UTILISATEUR_H
#define PROJETUML_UTILISATEUR_H

#include <iostream>
#include <string>
using namespace std;

class Utilisateur {

public:

    //Getters/Setters
    unsigned long getId() const;
    void setId(unsigned long id);

    const string &getNom() const;
    void setNom(const string &nom);

    const string &getPrenom() const;
    void setPrenom(const string &prenom);

    const string &getMail() const;
    void setMail(const string &mail);

    const string &getMdp() const;
    void setMdp(const string &mdp);

    //Surcharge d'opérateurs
    friend ostream & operator << (ostream & flux, const Utilisateur &u);

    //Constructeur(s)
    Utilisateur();
    Utilisateur(const unsigned long &unId, const string &unNom, const string &unPrenom, const string &unMail, const string &unMdp);

    //Destructeur
    virtual ~Utilisateur();

protected:
    //Attributs privés
    unsigned long id;
    string nom;
    string prenom;
    string mail;
    string mdp;

};


#endif //PROJETUML_UTILISATEUR_H
